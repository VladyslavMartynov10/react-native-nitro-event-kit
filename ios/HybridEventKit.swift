//
//  HybridEventKit.swift
//  NitroEventKit
//
//  Created by VLAD on 03.02.2025.
//

import Foundation
import EventKit
import NitroModules
import UIKit

class HybridEventKit: HybridEventKitSpec {
    private let eventStore: EKEventStore = EKEventStore()
    
    func getMonthlyCalendarEvents() throws -> NitroModules.Promise<[EKEvent]> {
        return Promise.async {
            let startDate = Date()
            let endDate = Calendar.current.date(byAdding: .day, value: 31, to: startDate) ?? Date()
            
            let calendars = self.eventStore.calendars(for: .event)
            var allEvents: [EKEvent] = []
            
            for calendar in calendars {
                let predicate = self.eventStore.predicateForEvents(withStart: startDate, end: endDate, calendars: [calendar])
                let events = self.eventStore.events(matching: predicate).map(self.mapToNitroEvent)
                
                allEvents.append(contentsOf: events)
            }

            return allEvents
        }
    }
}
