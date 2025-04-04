///
/// RangeEventOptions.hpp
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

// Forward declaration of `EventKitEntityType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitEntityType; }

#include "EventKitEntityType.hpp"
#include <optional>
#include <string>

namespace margelo::nitro::eventkit {

  /**
   * A struct which can be represented as a JavaScript object (RangeEventOptions).
   */
  struct RangeEventOptions {
  public:
    double startDate     SWIFT_PRIVATE;
    double endDate     SWIFT_PRIVATE;
    EventKitEntityType entityType     SWIFT_PRIVATE;
    std::optional<std::string> calendarId     SWIFT_PRIVATE;

  public:
    RangeEventOptions() = default;
    explicit RangeEventOptions(double startDate, double endDate, EventKitEntityType entityType, std::optional<std::string> calendarId): startDate(startDate), endDate(endDate), entityType(entityType), calendarId(calendarId) {}
  };

} // namespace margelo::nitro::eventkit

namespace margelo::nitro {

  using namespace margelo::nitro::eventkit;

  // C++ RangeEventOptions <> JS RangeEventOptions (object)
  template <>
  struct JSIConverter<RangeEventOptions> final {
    static inline RangeEventOptions fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return RangeEventOptions(
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "startDate")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "endDate")),
        JSIConverter<EventKitEntityType>::fromJSI(runtime, obj.getProperty(runtime, "entityType")),
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "calendarId"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const RangeEventOptions& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "startDate", JSIConverter<double>::toJSI(runtime, arg.startDate));
      obj.setProperty(runtime, "endDate", JSIConverter<double>::toJSI(runtime, arg.endDate));
      obj.setProperty(runtime, "entityType", JSIConverter<EventKitEntityType>::toJSI(runtime, arg.entityType));
      obj.setProperty(runtime, "calendarId", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.calendarId));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "startDate"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "endDate"))) return false;
      if (!JSIConverter<EventKitEntityType>::canConvert(runtime, obj.getProperty(runtime, "entityType"))) return false;
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "calendarId"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
