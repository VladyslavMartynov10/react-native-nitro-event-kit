///
/// EventKitParticipant.hpp
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

// Forward declaration of `EventKitParticipantStatus` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitParticipantStatus; }
// Forward declaration of `EventKitParticipantRole` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitParticipantRole; }
// Forward declaration of `EventKitParticipantType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitParticipantType; }
// Forward declaration of `EventKitPredicate` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitPredicate; }

#include <string>
#include <optional>
#include "EventKitParticipantStatus.hpp"
#include "EventKitParticipantRole.hpp"
#include "EventKitParticipantType.hpp"
#include "EventKitPredicate.hpp"

namespace margelo::nitro::eventkit {

  /**
   * A struct which can be represented as a JavaScript object (EventKitParticipant).
   */
  struct EventKitParticipant {
  public:
    std::string url     SWIFT_PRIVATE;
    std::optional<std::string> name     SWIFT_PRIVATE;
    EventKitParticipantStatus participantStatus     SWIFT_PRIVATE;
    EventKitParticipantRole participantRole     SWIFT_PRIVATE;
    EventKitParticipantType participantType     SWIFT_PRIVATE;
    bool isCurrentUser     SWIFT_PRIVATE;
    EventKitPredicate contactPredicate     SWIFT_PRIVATE;

  public:
    explicit EventKitParticipant(std::string url, std::optional<std::string> name, EventKitParticipantStatus participantStatus, EventKitParticipantRole participantRole, EventKitParticipantType participantType, bool isCurrentUser, EventKitPredicate contactPredicate): url(url), name(name), participantStatus(participantStatus), participantRole(participantRole), participantType(participantType), isCurrentUser(isCurrentUser), contactPredicate(contactPredicate) {}
  };

} // namespace margelo::nitro::eventkit

namespace margelo::nitro {

  using namespace margelo::nitro::eventkit;

  // C++ EventKitParticipant <> JS EventKitParticipant (object)
  template <>
  struct JSIConverter<EventKitParticipant> {
    static inline EventKitParticipant fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return EventKitParticipant(
        JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "url")),
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "name")),
        JSIConverter<EventKitParticipantStatus>::fromJSI(runtime, obj.getProperty(runtime, "participantStatus")),
        JSIConverter<EventKitParticipantRole>::fromJSI(runtime, obj.getProperty(runtime, "participantRole")),
        JSIConverter<EventKitParticipantType>::fromJSI(runtime, obj.getProperty(runtime, "participantType")),
        JSIConverter<bool>::fromJSI(runtime, obj.getProperty(runtime, "isCurrentUser")),
        JSIConverter<EventKitPredicate>::fromJSI(runtime, obj.getProperty(runtime, "contactPredicate"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const EventKitParticipant& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "url", JSIConverter<std::string>::toJSI(runtime, arg.url));
      obj.setProperty(runtime, "name", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.name));
      obj.setProperty(runtime, "participantStatus", JSIConverter<EventKitParticipantStatus>::toJSI(runtime, arg.participantStatus));
      obj.setProperty(runtime, "participantRole", JSIConverter<EventKitParticipantRole>::toJSI(runtime, arg.participantRole));
      obj.setProperty(runtime, "participantType", JSIConverter<EventKitParticipantType>::toJSI(runtime, arg.participantType));
      obj.setProperty(runtime, "isCurrentUser", JSIConverter<bool>::toJSI(runtime, arg.isCurrentUser));
      obj.setProperty(runtime, "contactPredicate", JSIConverter<EventKitPredicate>::toJSI(runtime, arg.contactPredicate));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<std::string>::canConvert(runtime, obj.getProperty(runtime, "url"))) return false;
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "name"))) return false;
      if (!JSIConverter<EventKitParticipantStatus>::canConvert(runtime, obj.getProperty(runtime, "participantStatus"))) return false;
      if (!JSIConverter<EventKitParticipantRole>::canConvert(runtime, obj.getProperty(runtime, "participantRole"))) return false;
      if (!JSIConverter<EventKitParticipantType>::canConvert(runtime, obj.getProperty(runtime, "participantType"))) return false;
      if (!JSIConverter<bool>::canConvert(runtime, obj.getProperty(runtime, "isCurrentUser"))) return false;
      if (!JSIConverter<EventKitPredicate>::canConvert(runtime, obj.getProperty(runtime, "contactPredicate"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
