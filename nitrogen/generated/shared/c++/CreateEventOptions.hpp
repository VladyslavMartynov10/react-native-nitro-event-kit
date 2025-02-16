///
/// CreateEventOptions.hpp
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



#include <string>
#include <optional>

namespace margelo::nitro::eventkit {

  /**
   * A struct which can be represented as a JavaScript object (CreateEventOptions).
   */
  struct CreateEventOptions {
  public:
    double startDate     SWIFT_PRIVATE;
    double endDate     SWIFT_PRIVATE;
    std::string title     SWIFT_PRIVATE;
    std::optional<std::string> location     SWIFT_PRIVATE;
    std::optional<std::string> notes     SWIFT_PRIVATE;
    std::string calendarIdentifier     SWIFT_PRIVATE;
    bool isCalendarImmutable     SWIFT_PRIVATE;
    std::optional<bool> scheduleAlarm     SWIFT_PRIVATE;
    std::optional<double> scheduleAlarmMinutesBefore     SWIFT_PRIVATE;

  public:
    explicit CreateEventOptions(double startDate, double endDate, std::string title, std::optional<std::string> location, std::optional<std::string> notes, std::string calendarIdentifier, bool isCalendarImmutable, std::optional<bool> scheduleAlarm, std::optional<double> scheduleAlarmMinutesBefore): startDate(startDate), endDate(endDate), title(title), location(location), notes(notes), calendarIdentifier(calendarIdentifier), isCalendarImmutable(isCalendarImmutable), scheduleAlarm(scheduleAlarm), scheduleAlarmMinutesBefore(scheduleAlarmMinutesBefore) {}
  };

} // namespace margelo::nitro::eventkit

namespace margelo::nitro {

  using namespace margelo::nitro::eventkit;

  // C++ CreateEventOptions <> JS CreateEventOptions (object)
  template <>
  struct JSIConverter<CreateEventOptions> {
    static inline CreateEventOptions fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return CreateEventOptions(
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "startDate")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "endDate")),
        JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "title")),
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "location")),
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "notes")),
        JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "calendarIdentifier")),
        JSIConverter<bool>::fromJSI(runtime, obj.getProperty(runtime, "isCalendarImmutable")),
        JSIConverter<std::optional<bool>>::fromJSI(runtime, obj.getProperty(runtime, "scheduleAlarm")),
        JSIConverter<std::optional<double>>::fromJSI(runtime, obj.getProperty(runtime, "scheduleAlarmMinutesBefore"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const CreateEventOptions& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "startDate", JSIConverter<double>::toJSI(runtime, arg.startDate));
      obj.setProperty(runtime, "endDate", JSIConverter<double>::toJSI(runtime, arg.endDate));
      obj.setProperty(runtime, "title", JSIConverter<std::string>::toJSI(runtime, arg.title));
      obj.setProperty(runtime, "location", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.location));
      obj.setProperty(runtime, "notes", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.notes));
      obj.setProperty(runtime, "calendarIdentifier", JSIConverter<std::string>::toJSI(runtime, arg.calendarIdentifier));
      obj.setProperty(runtime, "isCalendarImmutable", JSIConverter<bool>::toJSI(runtime, arg.isCalendarImmutable));
      obj.setProperty(runtime, "scheduleAlarm", JSIConverter<std::optional<bool>>::toJSI(runtime, arg.scheduleAlarm));
      obj.setProperty(runtime, "scheduleAlarmMinutesBefore", JSIConverter<std::optional<double>>::toJSI(runtime, arg.scheduleAlarmMinutesBefore));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "startDate"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "endDate"))) return false;
      if (!JSIConverter<std::string>::canConvert(runtime, obj.getProperty(runtime, "title"))) return false;
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "location"))) return false;
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "notes"))) return false;
      if (!JSIConverter<std::string>::canConvert(runtime, obj.getProperty(runtime, "calendarIdentifier"))) return false;
      if (!JSIConverter<bool>::canConvert(runtime, obj.getProperty(runtime, "isCalendarImmutable"))) return false;
      if (!JSIConverter<std::optional<bool>>::canConvert(runtime, obj.getProperty(runtime, "scheduleAlarm"))) return false;
      if (!JSIConverter<std::optional<double>>::canConvert(runtime, obj.getProperty(runtime, "scheduleAlarmMinutesBefore"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
