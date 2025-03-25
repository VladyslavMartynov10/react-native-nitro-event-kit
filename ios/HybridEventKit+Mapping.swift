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
            startDate: event.startDate.timeIntervalSince1970 * 1000,
            endDate: event.endDate.timeIntervalSince1970 * 1000,
            structuredLocation: mapToNitroStructuredLocation(structuredLocation: event.structuredLocation),
            organizer: mapToNitroOrganizer(organizer: event.organizer),
            availability: mapToNitroAvailability(event.availability),
            status: mapToNitroStatus(event.status),
            isDetached: event.isDetached,
            occurrenceDate: (
                event.occurrenceDate != nil
            ) ? event.occurrenceDate.timeIntervalSince1970 * 1000 : nil,
            birthdayContactIdentifier: event.birthdayContactIdentifier
        )
    }
    
    func mapToNitroAvailability(_ availability: EventKit.EKEventAvailability) -> EventKitAvailability {
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
    
    func mapToEVKitEntityType (_ entityType: EventKitEntityType) -> EventKit.EKEntityType {
        switch entityType {
        case .event:
            return .event
        case .reminder:
            return .reminder
        }
    }
    
    func mapToNitroCalendarType(_ type: EventKit.EKCalendarType) -> EventKitCalendarType {
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

    private func mapToNitroGeoLocation(geolocation: CLLocation?) -> EventKitGeoLocation? {
        guard let geolocation = geolocation else {
            return nil
        }
        
        let timestamp = geolocation.timestamp.unixTimestampInMilliseconds
        
        let coordinate = EventKitCoordinate(latitude: geolocation.coordinate.latitude, longitude: geolocation.coordinate.longitude)
        
        return EventKitGeoLocation(coordinate: coordinate, altitude: geolocation.altitude, ellipsoidalAltitude: geolocation.ellipsoidalAltitude, horizontalAccuracy: geolocation.horizontalAccuracy, verticalAccuracy: geolocation.verticalAccuracy, course: geolocation.course, courseAccuracy: geolocation.courseAccuracy, speed: geolocation.speed, speedAccuracy: geolocation.speedAccuracy, timestamp:  timestamp)
    }
    
    private func mapToNitroStructuredLocation (structuredLocation: EventKit.EKStructuredLocation?) -> EventKitStructuredLocation? {
        guard let structuredLocation = structuredLocation else { return nil }

        return EventKitStructuredLocation(
            title: structuredLocation.title,
            geoLocation: mapToNitroGeoLocation(geolocation: structuredLocation.geoLocation),
            radius: structuredLocation.radius
        )
    }
    
    private func mapToNitroParticipantStatus (_ participantStatus: EventKit.EKParticipantStatus) -> EventKitParticipantStatus {
        switch participantStatus {
        case .unknown:
            return .unknown
        case .pending:
            return .pending
        case .accepted:
            return .accepted
        case .declined:
            return .declined
        case .tentative:
            return .tentative
        case .delegated:
            return .delegated
        case .completed:
            return .completed
        case .inProcess:
            return .inprocess
        @unknown default:
            return .unknown
        }
    }
    
    private func maptToNitroParticipantRole (_ participantRole: EventKit.EKParticipantRole) -> EventKitParticipantRole {
        switch participantRole {
        case .unknown:
            return .unknown
        case .required:
            return .required
        case .optional:
            return .optional
        case .chair:
            return .chair
        case .nonParticipant:
            return .nonparticipant
        @unknown default:
            return .unknown
        }
    }
    
    private func mapToParticipantType (_ participantType: EventKit.EKParticipantType) -> EventKitParticipantType {
        switch participantType {
        case .unknown:
            return .unknown
        case .person:
            return .person
        case .room:
            return .room
        case .resource:
            return .resource
        case .group:
            return .group
        @unknown default:
            return .unknown
        }
    }
    
    private func mapToNitroOrganizer (organizer: EventKit.EKParticipant?) -> EventKitParticipant? {
        guard let organizer = organizer else {
            return nil
        }
        
        let contactPredicate = EventKitPredicate(predicateFormat: organizer.contactPredicate.predicateFormat)
        
        return EventKitParticipant(url: organizer.url.absoluteString, name: organizer.name, participantStatus: mapToNitroParticipantStatus(organizer.participantStatus), participantRole: maptToNitroParticipantRole(organizer.participantRole), participantType: mapToParticipantType(organizer.participantType), isCurrentUser: organizer.isCurrentUser, contactPredicate: contactPredicate)
    }
    
    func mapToEVKitSourceType(_ type: EventKitSourceType) -> EventKit.EKSourceType {
        switch type {
        case .local:
            return .local
        case .exchange:
            return .exchange
        case .caldav:
            return .calDAV
        case .mobileme:
            return .mobileMe
        case .subscribed:
            return .subscribed
        case .birthdays:
            return .birthdays
        @unknown default:
            return .local
        }
    }
}

