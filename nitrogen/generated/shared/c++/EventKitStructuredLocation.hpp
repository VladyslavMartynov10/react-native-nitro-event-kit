///
/// EventKitStructuredLocation.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

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

// Forward declaration of `EventKitGeoLocation` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitGeoLocation; }

#include <optional>
#include <string>
#include "EventKitGeoLocation.hpp"

namespace margelo::nitro::eventkit {

  /**
   * A struct which can be represented as a JavaScript object (EventKitStructuredLocation).
   */
  struct EventKitStructuredLocation {
  public:
    std::optional<std::string> title     SWIFT_PRIVATE;
    std::optional<EventKitGeoLocation> geoLocation     SWIFT_PRIVATE;
    double radius     SWIFT_PRIVATE;

  public:
    explicit EventKitStructuredLocation(std::optional<std::string> title, std::optional<EventKitGeoLocation> geoLocation, double radius): title(title), geoLocation(geoLocation), radius(radius) {}
  };

} // namespace margelo::nitro::eventkit

namespace margelo::nitro {

  using namespace margelo::nitro::eventkit;

  // C++ EventKitStructuredLocation <> JS EventKitStructuredLocation (object)
  template <>
  struct JSIConverter<EventKitStructuredLocation> {
    static inline EventKitStructuredLocation fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return EventKitStructuredLocation(
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "title")),
        JSIConverter<std::optional<EventKitGeoLocation>>::fromJSI(runtime, obj.getProperty(runtime, "geoLocation")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "radius"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const EventKitStructuredLocation& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "title", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.title));
      obj.setProperty(runtime, "geoLocation", JSIConverter<std::optional<EventKitGeoLocation>>::toJSI(runtime, arg.geoLocation));
      obj.setProperty(runtime, "radius", JSIConverter<double>::toJSI(runtime, arg.radius));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "title"))) return false;
      if (!JSIConverter<std::optional<EventKitGeoLocation>>::canConvert(runtime, obj.getProperty(runtime, "geoLocation"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "radius"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
