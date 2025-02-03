//
//  HybridEventKit+Mapping.swift
//  NitroEventKit
//
//  Created by VLAD on 03.02.2025.
//

import Foundation
import EventKit
import NitroModules

extension HybridEventKit {
    func mapToNitroEvent(_ event: EventKit.EKEvent) -> EKEvent {
        return EKEvent(
            eventIdentifier: event.eventIdentifier,
            isAllDay: event.isAllDay,
            startDate: event.startDate.timeIntervalSince1970,
            endDate: event.endDate.timeIntervalSince1970,
            availability: mapToNitroAvailability(event.availability),
            status: mapToNitroStatus(event.status),
            isDetached: event.isDetached,
            occurrenceDate: event.occurrenceDate?.timeIntervalSince1970,
            birthdayContactIdentifier: event.birthdayContactIdentifier
        )
    }
    
    private func mapToNitroAvailability(_ availability: EventKit.EKEventAvailability) -> EKEventAvailability {
        switch availability {
        case .notSupported:
            return .notsupported
        case .busy:
            return .busy
        case .free:
            return .free
        case .tentative:
            return .tentative
        case .unavailable:
            return .unavailable
        @unknown default:
            return .notsupported
        }
    }
    
    private func mapToNitroStatus(_ status: EventKit.EKEventStatus) -> EKEventStatus {
        switch status {
        case .none:
            return .none
        case .confirmed:
            return .confirmed
        case .tentative:
            return .tentative
        case .canceled:
            return .canceled
        @unknown default:
            return .none
        }
    }
}

