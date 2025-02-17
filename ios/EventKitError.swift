//
//  EventKitError.swift
//  NitroEventKit
//
//  Created by VLAD on 07.02.2025.
//

import Foundation

enum EventKitError: Int {
    case calendarAvailability = 1
    case calendarExistence = 2
    case calendarIsReadOnly = 3
    case eventCreationFailed = 4
    case rootViewControllerNotFound = 5
    case eventIdentifierNotFound = 6

    var message: String {
        switch self {
        case .calendarAvailability:
            return "Calendar access is not available"
        case .calendarExistence:
            return "Calendar with the given identifier was not found"
        case .calendarIsReadOnly:
            return "Calendar is read-only"
        case .eventCreationFailed:
            return "Failed to create event"
        case .rootViewControllerNotFound:
            return "Failed to find rootViewController"
        case .eventIdentifierNotFound:
            return "Failed to found event with such identifier"
        }
    }

    var nsError: NSError {
        return NSError(
            domain: "HybridEventKit",
            code: self.rawValue,
            userInfo: [NSLocalizedDescriptionKey: self.message]
        )
    }
}
