//
//  HybridCalendarPermission.swift
//  NitroEventKit
//
//  Created by VLAD on 04.02.2025.
//

import Foundation
import NitroModules
import EventKit

class HybridCalendarPermission: HybridCalendarPermissionSpec {
    private let eventStore = EventKitManager.shared.eventStore

    func getPermissionsStatus() throws -> EKEventPermissionResult {
        let status = EKEventStore.authorizationStatus(for: .event)
        return parseStatus(status)
    }
    
    func requestPermission() throws -> NitroModules.Promise<EKEventPermissionResult> {
        let promise = Promise<EKEventPermissionResult>()

        let completionHandler: EKEventStoreRequestAccessCompletionHandler = { [weak self] granted, error in
            DispatchQueue.main.async {
                guard let self = self else { return }

                if let error = error {
                    promise.reject(withError: error)
                    return
                }

                if granted {
                    EventKitManager.shared.updateCalendarAccessStatus()
                    promise.resolve(withResult: .fullaccess)
                } else {
                    do {
                        let status = try self.getPermissionsStatus()
                        promise.resolve(withResult: status)
                    } catch {
                        promise.reject(withError: error)
                    }
                }
            }
        }

        if #available(iOS 17.0, *) {
            eventStore.requestFullAccessToEvents(completion: completionHandler)
        } else {
            eventStore.requestAccess(to: .event, completion: completionHandler)
        }

        return promise
    }

//    func requestPermission() throws -> NitroModules.Promise<EKEventPermissionResult> {
//        let promise = Promise<EKEventPermissionResult>()
//
//        let completion: (Bool, Error?) -> Void = { granted, error in
//            if let error = error {
//                promise.reject(withError: error)
//                return
//            }
//
//            if granted {
//                EventKitManager.shared.updateCalendarAccessStatus()
//                
//                promise.resolve(withResult: .fullaccess)
//            } else {
//                do {
//                    let status = try self.getPermissionsStatus()
//                    promise.resolve(withResult: status)
//                } catch {
//                    promise.reject(withError: error)
//                }
//            }
//        }
//
//        if #available(iOS 17.0, *) {
//            self.eventStore.requestFullAccessToEvents(completion: completion)
//        } else {
//            self.eventStore.requestAccess(to: .event, completion: completion)
//        }
//
//        return promise
//    }

    private func parseStatus(_ status: EKAuthorizationStatus) -> EKEventPermissionResult {
        switch status {
        case .denied:
            return .denied
        case .notDetermined:
            return .notdetermined
        case .restricted:
            return .restricted
        case .fullAccess:
            return .fullaccess
        case .writeOnly:
            return .writeonly
        @unknown default:
            return .unavailable
        }
    }
}
