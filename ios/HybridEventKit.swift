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
    
    func getMonthlyCalendarEvents(entityType: EventKitEntityType) throws -> NitroModules.Promise<[EventKitEvent]> {
        
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }

        let promise = Promise<[EventKitEvent]>()

        let startDate = Date()
        
        let endDate = Calendar.current.date(byAdding: .day, value: 31, to: startDate) ?? Date()
        
        let calendars = self.eventStore.calendars(for: self.mapToEVKitEntityType(entityType))
        
        var allEvents: [EventKitEvent] = []
        
        for calendar in calendars {
            let predicate = self.eventStore.predicateForEvents(withStart: startDate, end: endDate, calendars: [calendar])
            let events = self.eventStore.events(matching: predicate).map(self.mapToNitroEvent)
            
            allEvents.append(contentsOf: events)
        }

        promise.resolve(withResult: allEvents)

        return promise
    }
    
    func getCalendarEventsByRange(options: RangeEventOptions) throws -> NitroModules.Promise<[EventKitEvent]> {
        
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }

        let promise = Promise<[EventKitEvent]>()

        let startDate = options.startDate.asDateFromMilliseconds
        
        let endDate = options.endDate.asDateFromMilliseconds

        let calendars = self.eventStore.calendars(for: self.mapToEVKitEntityType(options.entityType))
        
        var allEvents: [EventKitEvent] = []
        
        for calendar in calendars {
            let predicate = self.eventStore.predicateForEvents(withStart: startDate, end: endDate, calendars: [calendar])
            let events = self.eventStore.events(matching: predicate).map(self.mapToNitroEvent)
            
            allEvents.append(contentsOf: events)
        }

        promise.resolve(withResult: allEvents)

        return promise
    }
    
    func createEvent(options: CreateEventOptions) throws -> NitroModules.Promise<EventKitEvent> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }
        
        guard let calendar = eventStore.calendar(withIdentifier: options.calendarIdentifier) else {
            return Promise.rejected(withError: EventKitError.calendarExistence.nsError)
        }
        
       
        let promise = Promise<EventKitEvent>()

        let newEvent = EKEvent(eventStore: eventStore)
        
        newEvent.startDate = options.startDate.asDateFromMilliseconds
        
        newEvent.endDate = options.endDate.asDateFromMilliseconds

        newEvent.calendar = calendar
        
        newEvent.notes = options.notes
        
        newEvent.title = options.title
        
        if let minutesBefore = options.scheduleAlarmMinutesBefore, let scheduleAlarm = options.scheduleAlarm, scheduleAlarm {
            let secondsPerMinute: TimeInterval = 60
            let alarm = EKAlarm(relativeOffset: TimeInterval(minutesBefore * -secondsPerMinute))
            newEvent.addAlarm(alarm)
        }

        do {
            try eventStore.save(newEvent, span: .thisEvent)
            promise.resolve(withResult: mapToNitroEvent(newEvent))
        } catch {
            promise.reject(withError: error)
        }

        return promise
    }
    
    func deleteEvent(eventIdentifier: String) -> NitroModules.Promise<Bool> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }

        let promise = Promise<Bool>()

        guard let event = eventStore.event(withIdentifier: eventIdentifier) else {
            return Promise.rejected(withError: EventKitError.eventIdentifierNotFound.nsError)
        }

        do {
            try eventStore.remove(event, span: .thisEvent)
            promise.resolve(withResult: true)
        } catch {
            promise.reject(withError: error)
        }

        return promise
    }
    
    func getActiveCalendars() throws -> NitroModules.Promise<[EventKitCalendar]> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }
        
        let promise = Promise<[EventKitCalendar]>()
        
        let calendars = eventStore.calendars(for: .event).map { mapToNitroCalendar($0) }
        
        promise.resolve(withResult: calendars)
        
        return promise
    }
    
    func openCalendarEvent(eventIdentifier: String) throws -> NitroModules.Promise<Void> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
               return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
           }

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
}
