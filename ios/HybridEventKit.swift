//
//  HybridEventKit.swift
//  NitroEventKit
//
//  Created by VLAD on 03.02.2025.
//

import Foundation
import NitroModules
import UIKit
import EventKit
import EventKitUI

class HybridEventKit: HybridEventKitSpec {
    private let eventStore = EventKitManager.shared.eventStore
    
    private func checkCalendarAvailability() throws {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            throw RuntimeError.error(withMessage: EventKitError.calendarAvailability.message)
        }
    }
    
    private func getCalendar(by identifier: String) throws -> EKCalendar {
        guard let calendar = self.eventStore.calendar(withIdentifier: identifier) else {
            throw RuntimeError.error(withMessage: EventKitError.calendarExistence.message)
        }
        
        return calendar
    }
    
    private func getEvent(by identifier: String) throws -> EKEvent {
        guard let event = self.eventStore.event(withIdentifier: identifier) else {
            throw RuntimeError.error(withMessage: EventKitError.eventIdentifierNotFound.message)
        }
        
        return event
    }

    func getMonthlyCalendarEvents(options: MonthlyEventOptions) throws -> NitroModules.Promise<[EventKitEvent]> {
        return Promise.async {
            try self.checkCalendarAvailability()
            
            let entityType = options.entityType
            
            let startDate = Date()
            let endDate = Calendar.current.date(byAdding: .day, value: 31, to: startDate) ?? Date()
            
            let calendars: [EKCalendar]
            if let calendarId = options.calendarId, let specificCalendar = self.eventStore.calendar(
                withIdentifier: calendarId
            ) {
                calendars = [specificCalendar]
            } else {
                calendars = self.eventStore.calendars(for: self.mapToEVKitEntityType(entityType))
            }

            return calendars.flatMap { calendar in
                let predicate = self.eventStore.predicateForEvents(
                    withStart: startDate,
                    end: endDate,
                    calendars: [calendar]
                )
                return self.eventStore
                    .events(matching: predicate)
                    .map(self.mapToNitroEvent)
            }
        }
    }
    
    func getCalendarEventsByRange(options: RangeEventOptions) throws -> NitroModules.Promise<[EventKitEvent]> {
        return Promise.async {
            try self.checkCalendarAvailability()
            
            let entityType = options.entityType

            let startDate = options.startDate.asDateFromMilliseconds
            let endDate = options.endDate.asDateFromMilliseconds

            let calendars: [EKCalendar]
            if let calendarId = options.calendarId, let specificCalendar = self.eventStore.calendar(
                withIdentifier: calendarId
            ) {
                calendars = [specificCalendar]
            } else {
                calendars = self.eventStore.calendars(for: self.mapToEVKitEntityType(entityType))
            }
                    
            return calendars.flatMap { calendar in
                let predicate = self.eventStore.predicateForEvents(
                    withStart: startDate,
                    end: endDate,
                    calendars: [calendar]
                )
                return self.eventStore
                    .events(matching: predicate)
                    .map(self.mapToNitroEvent)
            }
        }
    }
    
    func createEvent(options: CreateEventOptions) throws -> NitroModules.Promise<EventKitEvent> {
        return Promise.async {
            try self.checkCalendarAvailability()
            
            let calendar = try self.getCalendar(by: options.calendarIdentifier)
            
            let newEvent = EKEvent(eventStore: self.eventStore)
            
            newEvent.startDate = options.startDate.asDateFromMilliseconds
            
            newEvent.endDate = options.endDate.asDateFromMilliseconds

            newEvent.calendar = calendar
            
            newEvent.notes = options.notes
            
            newEvent.title = options.title
            
            if let location = options.location {
                let structuredLocation = EKStructuredLocation(
                    title: location.title ?? ""
                )
                
                structuredLocation.geoLocation = CLLocation(
                    latitude: location.latitude,
                    longitude: location.longitude
                )
                
                newEvent.location = location.title
                newEvent.structuredLocation = structuredLocation
            }
            
            if let minutesBefore = options.scheduleAlarmMinutesBefore, let scheduleAlarm = options.scheduleAlarm, scheduleAlarm {
                let secondsPerMinute: TimeInterval = 60
                let alarm = EKAlarm(relativeOffset: TimeInterval(minutesBefore * -secondsPerMinute))
                newEvent.addAlarm(alarm)
            }

            do {
                try self.eventStore.save(newEvent, span: .thisEvent)
                
                return self.mapToNitroEvent(newEvent)
            } catch {
                throw RuntimeError.error(withMessage: EventKitError.eventCreationFailed.message)
            }
        }
    }
    
    func deleteEvent(eventIdentifier: String) -> NitroModules.Promise<Bool> {
        return Promise.async {
            try self.checkCalendarAvailability()
            
            let event = try self.getEvent(by: eventIdentifier)
            
            do {
                try self.eventStore.remove(event, span: .thisEvent)
                
                return true
            } catch {
                throw RuntimeError.error(withMessage: EventKitError.eventCreationFailed.message)
            }
        }
    }
    
    func getActiveCalendars() throws -> NitroModules.Promise<[EventKitCalendar]> {
        return Promise.async {
            try self.checkCalendarAvailability()
            
            let calendars = self.eventStore.calendars(for: .event).map { self.mapToNitroCalendar($0) }
            
            return calendars
        }
    }
    
    func openCalendarEvent(eventIdentifier: String) throws -> NitroModules.Promise<Void> {
           try self.checkCalendarAvailability()

           let promise = Promise<Void>()
        
           DispatchQueue.main.async {
               guard let rootViewController = UIApplication.shared.rootViewController else {
                   promise.reject(withError: EventKitError.rootViewControllerNotFound.nsError)
                   return
               }
            
               let eventPreviewController = EventPreviewController(eventIdentifier: eventIdentifier)
               
               let navigationController = UINavigationController(rootViewController: eventPreviewController)

               rootViewController.present(navigationController, animated: true) {
                   promise.resolve(withResult: ())
               }
           }

           return promise
    }
    
    func createCalendar(options: CreateCalendarOptions) throws -> NitroModules.Promise<EventKitCalendar> {
        return Promise.async {
            try self.checkCalendarAvailability()
            
            let calendar = EKCalendar(
                for: self.mapToEVKitEntityType(options.entityType),
                eventStore: self.eventStore
            )
            
            calendar.title = options.name
            
            if let colorHex = options.cgColor,
               let color = UIColor(hexString: colorHex) {
                calendar.cgColor = color.cgColor
            }
            
            if let sourceTypeRaw = options.sourceType {
                let sourceType = self.mapToEVKitSourceType(sourceTypeRaw)
                
                if let matchedSource = self.eventStore.sources.first(
                    where: { $0.sourceType == sourceType }
                ) {
                    calendar.source = matchedSource
                } else {
                    throw RuntimeError.error(
                        withMessage: EventKitError.calendarSourceInvalid.message
                    )
                }
            } else if let localSource = self.eventStore.sources.first(
                where: { $0.sourceType == .local }
            ) {
                calendar.source = localSource
            } else if let defaultSource = self.eventStore.defaultCalendarForNewEvents?.source {
                calendar.source = defaultSource
            } else {
                throw RuntimeError.error(
                    withMessage: EventKitError.calendarSourceNotFound.message
                )
            }

            
            do {
                try self.eventStore.saveCalendar(calendar, commit: true)
                
                return self.mapToNitroCalendar(calendar)
            } catch {
                throw RuntimeError.error(
                    withMessage: EventKitError.calendarSavingFailed.message
                )
            }
        }
    }
    
    
    func editEvent(eventIdentifier: String, options: EditEventOptions) throws -> NitroModules.Promise<EventKitEvent> {
        return Promise.async {
            try self.checkCalendarAvailability()

            guard let event = self.eventStore.event(withIdentifier: eventIdentifier) else {
                throw RuntimeError.error(
                    withMessage: EventKitError.eventIdentifierNotFound.message
                )
            }
            
            if let newTitle = options.title {
                event.title = newTitle
            }

            if let newStartDate = options.startDate {
                event.startDate = newStartDate.asDateFromMilliseconds
            }

            if let newEndDate = options.endDate {
                event.endDate = newEndDate.asDateFromMilliseconds
            }

            if let newNotes = options.notes {
                event.notes = newNotes
            }

            if let newLocation = options.location {
                let structuredLocation = EKStructuredLocation(
                    title: newLocation.title ?? ""
                )
                
                if let newLatitude = newLocation.latitude, let newLongitude = newLocation.longitude {
                    structuredLocation.geoLocation = CLLocation(
                        latitude: newLatitude,
                        longitude: newLongitude
                    )
                }
                
                
                event.location = newLocation.title
                event.structuredLocation = structuredLocation
            }
            
            if let minutesBefore = options.scheduleAlarmMinutesBefore, let scheduleAlarm = options.scheduleAlarm, scheduleAlarm {
                let secondsPerMinute: TimeInterval = 60
                let alarm = EKAlarm(relativeOffset: TimeInterval(minutesBefore * -secondsPerMinute))
                event.addAlarm(alarm)
            }

            if let newCalendarId = options.calendarId {
                guard let targetCalendar = self.eventStore.calendars(for: .event).first(
                    where: { $0.calendarIdentifier == newCalendarId }) else {
                    throw RuntimeError
                        .error(
                            withMessage: EventKitError.calendarExistence.message
                        )
                }
                
                event.calendar = targetCalendar
            }

            do {
                try self.eventStore.save(event, span: .thisEvent, commit: true)
                return self.mapToNitroEvent(event)
            } catch {
                throw RuntimeError.error(
                    withMessage: EventKitError.eventUpdateFailed.message
                )
            }
        }
    }
}
