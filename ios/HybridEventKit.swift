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

class HybridEventKit: HybridEventKitSpec {
    private let eventStore = EventKitManager.shared.eventStore
            
    func getMonthlyCalendarEvents() -> NitroModules.Promise<[EventKitEvent]> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }

        let promise = Promise<[EventKitEvent]>()

        let startDate = Date()
        
        let endDate = Calendar.current.date(byAdding: .day, value: 31, to: startDate) ?? Date()
        
        let calendars = self.eventStore.calendars(for: .event)
        
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

        guard let calendarIdentifier = options.calendarIdentifier,
              let calendar = eventStore.calendar(withIdentifier: calendarIdentifier) else {
            return Promise.rejected(withError: EventKitError.calendarExistence.nsError)
        }

        let promise = Promise<EventKitEvent>()

        let newEvent = EKEvent(eventStore: eventStore)
        
        newEvent.startDate = options.event.startDate.asDateFromMilliseconds
        
        newEvent.endDate = options.event.endDate.asDateFromMilliseconds

        newEvent.calendar = calendar

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
    
    func getActiveCalendars() throws -> NitroModules.Promise<[EventKitCalendar]> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: EventKitError.calendarAvailability.nsError)
        }
        
        let promise = Promise<[EventKitCalendar]>()
        
        let calendars = eventStore.calendars(for: .event).map { mapToNitroCalendar($0) }
        
        promise.resolve(withResult: calendars)
        
        return promise
    }
}
