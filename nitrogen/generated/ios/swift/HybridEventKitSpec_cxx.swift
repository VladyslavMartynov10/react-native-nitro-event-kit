///
/// HybridEventKitSpec_cxx.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges HybridEventKitSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HybridObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public class HybridEventKitSpec_cxx {
  /**
   * The Swift <> C++ bridge's namespace (`margelo::nitro::eventkit::bridge::swift`)
   * from `NitroEventKit-Swift-Cxx-Bridge.hpp`.
   * This contains specialized C++ templates, and C++ helper functions that can be accessed from Swift.
   */
  public typealias bridge = margelo.nitro.eventkit.bridge.swift

  /**
   * Holds an instance of the `HybridEventKitSpec` Swift protocol.
   */
  private var __implementation: any HybridEventKitSpec

  /**
   * Holds a weak pointer to the C++ class that wraps the Swift class.
   */
  private var __cxxPart: bridge.std__weak_ptr_margelo__nitro__eventkit__HybridEventKitSpec_

  /**
   * Create a new `HybridEventKitSpec_cxx` that wraps the given `HybridEventKitSpec`.
   * All properties and methods bridge to C++ types.
   */
  public init(_ implementation: any HybridEventKitSpec) {
    self.__implementation = implementation
    self.__cxxPart = .init()
    /* no base class */
  }

  /**
   * Get the actual `HybridEventKitSpec` instance this class wraps.
   */
  @inline(__always)
  public func getHybridEventKitSpec() -> any HybridEventKitSpec {
    return __implementation
  }

  /**
   * Casts this instance to a retained unsafe raw pointer.
   * This acquires one additional strong reference on the object!
   */
  public func toUnsafe() -> UnsafeMutableRawPointer {
    return Unmanaged.passRetained(self).toOpaque()
  }

  /**
   * Casts an unsafe pointer to a `HybridEventKitSpec_cxx`.
   * The pointer has to be a retained opaque `Unmanaged<HybridEventKitSpec_cxx>`.
   * This removes one strong reference from the object!
   */
  public class func fromUnsafe(_ pointer: UnsafeMutableRawPointer) -> HybridEventKitSpec_cxx {
    return Unmanaged<HybridEventKitSpec_cxx>.fromOpaque(pointer).takeRetainedValue()
  }

  /**
   * Gets (or creates) the C++ part of this Hybrid Object.
   * The C++ part is a `std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec>`.
   */
  public func getCxxPart() -> bridge.std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_ {
    let cachedCxxPart = self.__cxxPart.lock()
    if cachedCxxPart.__convertToBool() {
      return cachedCxxPart
    } else {
      let newCxxPart = bridge.create_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(self.toUnsafe())
      __cxxPart = bridge.weakify_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(newCxxPart)
      return newCxxPart
    }
  }

  

  /**
   * Get the memory size of the Swift class (plus size of any other allocations)
   * so the JS VM can properly track it and garbage-collect the JS object if needed.
   */
  @inline(__always)
  public var memorySize: Int {
    return MemoryHelper.getSizeOf(self.__implementation) + self.__implementation.memorySize
  }

  // Properties
  

  // Methods
  @inline(__always)
  public func getActiveCalendars() -> bridge.Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____ {
    do {
      let __result = try self.__implementation.getActiveCalendars()
      let __resultCpp = { () -> bridge.std__shared_ptr_Promise_std__vector_EventKitCalendar___ in
        let __promise = bridge.create_std__shared_ptr_Promise_std__vector_EventKitCalendar___()
        let __promiseHolder = bridge.wrap_std__shared_ptr_Promise_std__vector_EventKitCalendar___(__promise)
        __result
          .then({ __result in __promiseHolder.resolve({ () -> bridge.std__vector_EventKitCalendar_ in
              var __vector = bridge.create_std__vector_EventKitCalendar_(__result.count)
              for __item in __result {
                __vector.push_back(__item)
              }
              return __vector
            }()) })
          .catch({ __error in __promiseHolder.reject(__error.toCpp()) })
        return __promise
      }()
      return bridge.create_Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____(__resultCpp)
    } catch (let __error) {
      let __exceptionPtr = __error.toCpp()
      return bridge.create_Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____(__exceptionPtr)
    }
  }
  
  @inline(__always)
  public func getMonthlyCalendarEvents() -> bridge.Result_std__shared_ptr_Promise_std__vector_EventKitEvent____ {
    do {
      let __result = try self.__implementation.getMonthlyCalendarEvents()
      let __resultCpp = { () -> bridge.std__shared_ptr_Promise_std__vector_EventKitEvent___ in
        let __promise = bridge.create_std__shared_ptr_Promise_std__vector_EventKitEvent___()
        let __promiseHolder = bridge.wrap_std__shared_ptr_Promise_std__vector_EventKitEvent___(__promise)
        __result
          .then({ __result in __promiseHolder.resolve({ () -> bridge.std__vector_EventKitEvent_ in
              var __vector = bridge.create_std__vector_EventKitEvent_(__result.count)
              for __item in __result {
                __vector.push_back(__item)
              }
              return __vector
            }()) })
          .catch({ __error in __promiseHolder.reject(__error.toCpp()) })
        return __promise
      }()
      return bridge.create_Result_std__shared_ptr_Promise_std__vector_EventKitEvent____(__resultCpp)
    } catch (let __error) {
      let __exceptionPtr = __error.toCpp()
      return bridge.create_Result_std__shared_ptr_Promise_std__vector_EventKitEvent____(__exceptionPtr)
    }
  }
  
  @inline(__always)
  public func createEvent(options: CreateEventOptions) -> bridge.Result_std__shared_ptr_Promise_EventKitEvent___ {
    do {
      let __result = try self.__implementation.createEvent(options: options)
      let __resultCpp = { () -> bridge.std__shared_ptr_Promise_EventKitEvent__ in
        let __promise = bridge.create_std__shared_ptr_Promise_EventKitEvent__()
        let __promiseHolder = bridge.wrap_std__shared_ptr_Promise_EventKitEvent__(__promise)
        __result
          .then({ __result in __promiseHolder.resolve(__result) })
          .catch({ __error in __promiseHolder.reject(__error.toCpp()) })
        return __promise
      }()
      return bridge.create_Result_std__shared_ptr_Promise_EventKitEvent___(__resultCpp)
    } catch (let __error) {
      let __exceptionPtr = __error.toCpp()
      return bridge.create_Result_std__shared_ptr_Promise_EventKitEvent___(__exceptionPtr)
    }
  }
}
