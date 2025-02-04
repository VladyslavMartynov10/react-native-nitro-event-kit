//
//  EventKitManager.swift
//  NitroEventKit
//
//  Created by VLAD on 04.02.2025.
//

import Foundation
import EventKit

final class EventKitManager {
    static let shared = EventKitManager()

    let eventStore = EKEventStore()
    
    private(set) var isCalendarAccessAvailable: Bool

    private init() {
        self.isCalendarAccessAvailable = Self.checkAuthorizationStatus()
    }
    
    private static func checkAuthorizationStatus() -> Bool {
        let status = EKEventStore.authorizationStatus(for: .event)
        
        if #available(iOS 17.0, *) {
            return status == .fullAccess
        } else {
            return status == .authorized
        }
    }

    func updateCalendarAccessStatus() {
        self.isCalendarAccessAvailable = Self.checkAuthorizationStatus()
    }
}
