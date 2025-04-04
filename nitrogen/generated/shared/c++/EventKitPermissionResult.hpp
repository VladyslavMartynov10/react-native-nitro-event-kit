///
/// EventKitPermissionResult.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/NitroHash.hpp>)
#include <NitroModules/NitroHash.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::eventkit {

  /**
   * An enum which can be represented as a JavaScript union (EventKitPermissionResult).
   */
  enum class EventKitPermissionResult {
    DENIED      SWIFT_NAME(denied) = 0,
    NOTDETERMINED      SWIFT_NAME(notdetermined) = 1,
    RESTRICTED      SWIFT_NAME(restricted) = 2,
    FULLACCESS      SWIFT_NAME(fullaccess) = 3,
    WRITEONLY      SWIFT_NAME(writeonly) = 4,
    UNAVAILABLE      SWIFT_NAME(unavailable) = 5,
  } CLOSED_ENUM;

} // namespace margelo::nitro::eventkit

namespace margelo::nitro {

  using namespace margelo::nitro::eventkit;

  // C++ EventKitPermissionResult <> JS EventKitPermissionResult (union)
  template <>
  struct JSIConverter<EventKitPermissionResult> final {
    static inline EventKitPermissionResult fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, arg);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("denied"): return EventKitPermissionResult::DENIED;
        case hashString("notDetermined"): return EventKitPermissionResult::NOTDETERMINED;
        case hashString("restricted"): return EventKitPermissionResult::RESTRICTED;
        case hashString("fullAccess"): return EventKitPermissionResult::FULLACCESS;
        case hashString("writeOnly"): return EventKitPermissionResult::WRITEONLY;
        case hashString("unavailable"): return EventKitPermissionResult::UNAVAILABLE;
        default: [[unlikely]]
          throw std::invalid_argument("Cannot convert \"" + unionValue + "\" to enum EventKitPermissionResult - invalid value!");
      }
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, EventKitPermissionResult arg) {
      switch (arg) {
        case EventKitPermissionResult::DENIED: return JSIConverter<std::string>::toJSI(runtime, "denied");
        case EventKitPermissionResult::NOTDETERMINED: return JSIConverter<std::string>::toJSI(runtime, "notDetermined");
        case EventKitPermissionResult::RESTRICTED: return JSIConverter<std::string>::toJSI(runtime, "restricted");
        case EventKitPermissionResult::FULLACCESS: return JSIConverter<std::string>::toJSI(runtime, "fullAccess");
        case EventKitPermissionResult::WRITEONLY: return JSIConverter<std::string>::toJSI(runtime, "writeOnly");
        case EventKitPermissionResult::UNAVAILABLE: return JSIConverter<std::string>::toJSI(runtime, "unavailable");
        default: [[unlikely]]
          throw std::invalid_argument("Cannot convert EventKitPermissionResult to JS - invalid value: "
                                    + std::to_string(static_cast<int>(arg)) + "!");
      }
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isString()) {
        return false;
      }
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, value);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("denied"):
        case hashString("notDetermined"):
        case hashString("restricted"):
        case hashString("fullAccess"):
        case hashString("writeOnly"):
        case hashString("unavailable"):
          return true;
        default:
          return false;
      }
    }
  };

} // namespace margelo::nitro
