///
/// EventKitCalendarEventAvailabilityMask.hpp
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



#include <optional>

namespace margelo::nitro::eventkit {

  /**
   * A struct which can be represented as a JavaScript object (EventKitCalendarEventAvailabilityMask).
   */
  struct EventKitCalendarEventAvailabilityMask {
  public:
    std::optional<bool> Busy     SWIFT_PRIVATE;
    std::optional<bool> Free     SWIFT_PRIVATE;
    std::optional<bool> Tentative     SWIFT_PRIVATE;
    std::optional<bool> Unavailable     SWIFT_PRIVATE;

  public:
    EventKitCalendarEventAvailabilityMask() = default;
    explicit EventKitCalendarEventAvailabilityMask(std::optional<bool> Busy, std::optional<bool> Free, std::optional<bool> Tentative, std::optional<bool> Unavailable): Busy(Busy), Free(Free), Tentative(Tentative), Unavailable(Unavailable) {}
  };

} // namespace margelo::nitro::eventkit

namespace margelo::nitro {

  using namespace margelo::nitro::eventkit;

  // C++ EventKitCalendarEventAvailabilityMask <> JS EventKitCalendarEventAvailabilityMask (object)
  template <>
  struct JSIConverter<EventKitCalendarEventAvailabilityMask> final {
    static inline EventKitCalendarEventAvailabilityMask fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return EventKitCalendarEventAvailabilityMask(
        JSIConverter<std::optional<bool>>::fromJSI(runtime, obj.getProperty(runtime, "Busy")),
        JSIConverter<std::optional<bool>>::fromJSI(runtime, obj.getProperty(runtime, "Free")),
        JSIConverter<std::optional<bool>>::fromJSI(runtime, obj.getProperty(runtime, "Tentative")),
        JSIConverter<std::optional<bool>>::fromJSI(runtime, obj.getProperty(runtime, "Unavailable"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const EventKitCalendarEventAvailabilityMask& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "Busy", JSIConverter<std::optional<bool>>::toJSI(runtime, arg.Busy));
      obj.setProperty(runtime, "Free", JSIConverter<std::optional<bool>>::toJSI(runtime, arg.Free));
      obj.setProperty(runtime, "Tentative", JSIConverter<std::optional<bool>>::toJSI(runtime, arg.Tentative));
      obj.setProperty(runtime, "Unavailable", JSIConverter<std::optional<bool>>::toJSI(runtime, arg.Unavailable));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<std::optional<bool>>::canConvert(runtime, obj.getProperty(runtime, "Busy"))) return false;
      if (!JSIConverter<std::optional<bool>>::canConvert(runtime, obj.getProperty(runtime, "Free"))) return false;
      if (!JSIConverter<std::optional<bool>>::canConvert(runtime, obj.getProperty(runtime, "Tentative"))) return false;
      if (!JSIConverter<std::optional<bool>>::canConvert(runtime, obj.getProperty(runtime, "Unavailable"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
