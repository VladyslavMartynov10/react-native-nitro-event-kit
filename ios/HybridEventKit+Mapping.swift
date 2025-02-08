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
    func mapToNitroEvent(_ event: EventKit.EKEvent) -> EventKitEvent {
        return EventKitEvent(
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
    
    private func mapToNitroAvailability(_ availability: EventKit.EKEventAvailability) -> EventKitAvailability {
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
    
    private func mapToNitroStatus(_ status: EventKit.EKEventStatus) -> EventKitStatus {
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
    
    func mapToNitroCalendar(_ calendar: EventKit.EKCalendar) -> EventKitCalendar {
        return EventKitCalendar(
            calendarIdentifier: calendar.calendarIdentifier,
            title: calendar.title,
            type: mapToNitroCalendarType(calendar.type),
            allowsContentModifications: calendar.allowsContentModifications,
            isSubscribed: calendar.isSubscribed,
            isImmutable: calendar.isImmutable,
            cgColor: calendar.cgColor?.hexString ?? "#000000",
            supportedEventAvailabilities: mapToNitroAvailabilities(calendar.supportedEventAvailabilities),
            allowedEntityTypes: mapToNitroEntityTypes(calendar.allowedEntityTypes),
            source: mapToNitroSource(calendar.source) ?? EventKitSource(
                sourceIdentifier: "unknown",
                sourceType: .local,
                title: "Unknown Source",
                isDelegate: false
            )
        )
    }
    
    private func mapToNitroCalendarType(_ type: EventKit.EKCalendarType) -> EventKitCalendarType {
        switch type {
        case .local:
            return .local
        case .calDAV:
            return .caldav
        case .exchange:
            return .exchange
        case .subscription:
            return .subscription
        case .birthday:
            return .birthday
        @unknown default:
            return .local
        }
    }
    
    private func mapToNitroSource(_ source: EventKit.EKSource?) -> EventKitSource? {
         guard let source = source else { return nil }
         
        if #available(iOS 16.0, *) {
            return EventKitSource(
                sourceIdentifier: source.sourceIdentifier,
                sourceType: mapToNitroSourceType(source.sourceType),
                title: source.title,
                isDelegate: source.isDelegate
            )
        } else {
            return EventKitSource(
                sourceIdentifier: source.sourceIdentifier,
                sourceType: mapToNitroSourceType(source.sourceType),
                title: source.title,
                isDelegate: false
            )
        }
     }
    
    
    private func mapToNitroSourceType(_ type: EventKit.EKSourceType) -> EventKitSourceType {
        switch type {
        case .local:
            return .local
        case .exchange:
            return .exchange
        case .calDAV:
            return .caldav
        case .mobileMe:
            return .mobileme
        case .subscribed:
            return .subscribed
        case .birthdays:
            return .birthdays
        @unknown default:
            return .local
        }
    }
    
    private func mapToNitroAvailabilities(_ mask: EventKit.EKCalendarEventAvailabilityMask) -> EventKitCalendarEventAvailabilityMask {
        return EventKitCalendarEventAvailabilityMask(
            Busy: mask.contains(.busy),
            Free: mask.contains(.free),
            Tentative: mask.contains(.tentative),
            Unavailable: mask.contains(.unavailable)
        )
    }
    
    
    private func mapToNitroEntityTypes(_ mask: EventKit.EKEntityMask) -> EventKitEntityMask {
        return EventKitEntityMask(
            Event: mask.contains(.event),
            Reminder: mask.contains(.reminder)
        )
    }
}

