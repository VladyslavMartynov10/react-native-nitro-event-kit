///
/// EventKitSource.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `EventKitSource`, backed by a C++ struct.
 */
public typealias EventKitSource = margelo.nitro.eventkit.EventKitSource

public extension EventKitSource {
  private typealias bridge = margelo.nitro.eventkit.bridge.swift

  /**
   * Create a new instance of `EventKitSource`.
   */
  init(sourceIdentifier: String, sourceType: EventKitSourceType, title: String, isDelegate: Bool?) {
    self.init(std.string(sourceIdentifier), sourceType, std.string(title), { () -> bridge.std__optional_bool_ in
      if let __unwrappedValue = isDelegate {
        return bridge.create_std__optional_bool_(__unwrappedValue)
      } else {
        return .init()
      }
    }())
  }

  var sourceIdentifier: String {
    @inline(__always)
    get {
      return String(self.__sourceIdentifier)
    }
    @inline(__always)
    set {
      self.__sourceIdentifier = std.string(newValue)
    }
  }
  
  var sourceType: EventKitSourceType {
    @inline(__always)
    get {
      return self.__sourceType
    }
    @inline(__always)
    set {
      self.__sourceType = newValue
    }
  }
  
  var title: String {
    @inline(__always)
    get {
      return String(self.__title)
    }
    @inline(__always)
    set {
      self.__title = std.string(newValue)
    }
  }
  
  var isDelegate: Bool? {
    @inline(__always)
    get {
      return self.__isDelegate.value
    }
    @inline(__always)
    set {
      self.__isDelegate = { () -> bridge.std__optional_bool_ in
        if let __unwrappedValue = newValue {
          return bridge.create_std__optional_bool_(__unwrappedValue)
        } else {
          return .init()
        }
      }()
    }
  }
}
