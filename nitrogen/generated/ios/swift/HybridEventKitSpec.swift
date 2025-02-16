///
/// HybridEventKitSpec.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/// See ``HybridEventKitSpec``
public protocol HybridEventKitSpec_protocol: HybridObject {
  // Properties
  

  // Methods
  func getActiveCalendars() throws -> Promise<[EventKitCalendar]>
  func getMonthlyCalendarEvents(entityType: EventKitEntityType) throws -> Promise<[EventKitEvent]>
  func createEvent(options: CreateEventOptions) throws -> Promise<EventKitEvent>
  func openCalendarEvent(eventIdentifier: String) throws -> Promise<Void>
}

/// See ``HybridEventKitSpec``
public class HybridEventKitSpec_base {
  private weak var cxxWrapper: HybridEventKitSpec_cxx? = nil
  public func getCxxWrapper() -> HybridEventKitSpec_cxx {
  #if DEBUG
    guard self is HybridEventKitSpec else {
      fatalError("`self` is not a `HybridEventKitSpec`! Did you accidentally inherit from `HybridEventKitSpec_base` instead of `HybridEventKitSpec`?")
    }
  #endif
    if let cxxWrapper = self.cxxWrapper {
      return cxxWrapper
    } else {
      let cxxWrapper = HybridEventKitSpec_cxx(self as! HybridEventKitSpec)
      self.cxxWrapper = cxxWrapper
      return cxxWrapper
    }
  }
}

/**
 * A Swift base-protocol representing the EventKit HybridObject.
 * Implement this protocol to create Swift-based instances of EventKit.
 * ```swift
 * class HybridEventKit : HybridEventKitSpec {
 *   // ...
 * }
 * ```
 */
public typealias HybridEventKitSpec = HybridEventKitSpec_protocol & HybridEventKitSpec_base
