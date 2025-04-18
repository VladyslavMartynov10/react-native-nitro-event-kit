///
/// Func_void_std__vector_EventKitCalendar_.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Wraps a Swift `(_ value: [EventKitCalendar]) -> Void` as a class.
 * This class can be used from C++, e.g. to wrap the Swift closure as a `std::function`.
 */
public final class Func_void_std__vector_EventKitCalendar_ {
  public typealias bridge = margelo.nitro.eventkit.bridge.swift

  private let closure: (_ value: [EventKitCalendar]) -> Void

  public init(_ closure: @escaping (_ value: [EventKitCalendar]) -> Void) {
    self.closure = closure
  }

  @inline(__always)
  public func call(value: bridge.std__vector_EventKitCalendar_) -> Void {
    self.closure(value.map({ __item in __item }))
  }

  /**
   * Casts this instance to a retained unsafe raw pointer.
   * This acquires one additional strong reference on the object!
   */
  @inline(__always)
  public func toUnsafe() -> UnsafeMutableRawPointer {
    return Unmanaged.passRetained(self).toOpaque()
  }

  /**
   * Casts an unsafe pointer to a `Func_void_std__vector_EventKitCalendar_`.
   * The pointer has to be a retained opaque `Unmanaged<Func_void_std__vector_EventKitCalendar_>`.
   * This removes one strong reference from the object!
   */
  @inline(__always)
  public static func fromUnsafe(_ pointer: UnsafeMutableRawPointer) -> Func_void_std__vector_EventKitCalendar_ {
    return Unmanaged<Func_void_std__vector_EventKitCalendar_>.fromOpaque(pointer).takeRetainedValue()
  }
}
