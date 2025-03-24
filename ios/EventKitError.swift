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
    case calendarCreationFailed = 7
    case calendarSourceNotFound = 8
    case calendarSavingFailed = 9
    case calendarSourceInvalid = 10

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
        case .calendarCreationFailed:
            return "Failed to create event"
        case .calendarSourceNotFound:
            return "No valid calendar source found"
        case .calendarSavingFailed:
            return "Failed to save calendar"
        case .calendarSourceInvalid:
            return "Calendar source in invalid"
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
