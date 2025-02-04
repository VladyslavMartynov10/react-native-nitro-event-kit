//
//  HybridEventKit.swift
//  NitroEventKit
//
//  Created by VLAD on 03.02.2025.
//

import Foundation
import NitroModules
import UIKit

class HybridEventKit: HybridEventKitSpec {
    private let eventStore = EventKitManager.shared.eventStore
        
    func getMonthlyCalendarEvents() -> NitroModules.Promise<[EKEvent]> {
        guard EventKitManager.shared.isCalendarAccessAvailable else {
            return Promise.rejected(withError: NSError(
                domain: "HybridEventKit",
                code: 1,
                userInfo: [NSLocalizedDescriptionKey: "Calendar access is not available"]
            ))
        }

        let promise = Promise<[EKEvent]>()

        let startDate = Date()
        let endDate = Calendar.current.date(byAdding: .day, value: 31, to: startDate) ?? Date()
        let calendars = self.eventStore.calendars(for: .event)
        
        var allEvents: [EKEvent] = []
        
        for calendar in calendars {
            let predicate = self.eventStore.predicateForEvents(withStart: startDate, end: endDate, calendars: [calendar])
            let events = self.eventStore.events(matching: predicate).map(self.mapToNitroEvent)
            
            allEvents.append(contentsOf: events)
        }

        promise.resolve(withResult: allEvents)

        return promise
    }
}
