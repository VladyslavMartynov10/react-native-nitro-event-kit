///
/// EventKitCalendarEventAvailabilityMask.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `EventKitCalendarEventAvailabilityMask`, backed by a C++ struct.
 */
public typealias EventKitCalendarEventAvailabilityMask = margelo.nitro.eventkit.EventKitCalendarEventAvailabilityMask

public extension EventKitCalendarEventAvailabilityMask {
  private typealias bridge = margelo.nitro.eventkit.bridge.swift

  /**
   * Create a new instance of `EventKitCalendarEventAvailabilityMask`.
   */
  init(Busy: Bool?, Free: Bool?, Tentative: Bool?, Unavailable: Bool?) {
    self.init({ () -> bridge.std__optional_bool_ in
      if let __unwrappedValue = Busy {
        return bridge.create_std__optional_bool_(__unwrappedValue)
      } else {
        return .init()
      }
    }(), { () -> bridge.std__optional_bool_ in
      if let __unwrappedValue = Free {
        return bridge.create_std__optional_bool_(__unwrappedValue)
      } else {
        return .init()
      }
    }(), { () -> bridge.std__optional_bool_ in
      if let __unwrappedValue = Tentative {
        return bridge.create_std__optional_bool_(__unwrappedValue)
      } else {
        return .init()
      }
    }(), { () -> bridge.std__optional_bool_ in
      if let __unwrappedValue = Unavailable {
        return bridge.create_std__optional_bool_(__unwrappedValue)
      } else {
        return .init()
      }
    }())
  }

  var Busy: Bool? {
    @inline(__always)
    get {
      return self.__Busy.value
    }
    @inline(__always)
    set {
      self.__Busy = { () -> bridge.std__optional_bool_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_bool_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
  
  var Free: Bool? {
    @inline(__always)
    get {
      return self.__Free.value
    }
    @inline(__always)
    set {
      self.__Free = { () -> bridge.std__optional_bool_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_bool_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
  
  var Tentative: Bool? {
    @inline(__always)
    get {
      return self.__Tentative.value
    }
    @inline(__always)
    set {
      self.__Tentative = { () -> bridge.std__optional_bool_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_bool_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
  
  var Unavailable: Bool? {
    @inline(__always)
    get {
      return self.__Unavailable.value
    }
    @inline(__always)
    set {
      self.__Unavailable = { () -> bridge.std__optional_bool_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_bool_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
}
