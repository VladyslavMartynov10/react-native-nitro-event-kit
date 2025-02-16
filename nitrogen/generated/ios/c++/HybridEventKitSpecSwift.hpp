///
/// HybridEventKitSpecSwift.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#include "HybridEventKitSpec.hpp"

// Forward declaration of `HybridEventKitSpec_cxx` to properly resolve imports.
namespace NitroEventKit { class HybridEventKitSpec_cxx; }

// Forward declaration of `EventKitCalendar` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCalendar; }
// Forward declaration of `EventKitCalendarType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitCalendarType; }
// Forward declaration of `EventKitCalendarEventAvailabilityMask` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCalendarEventAvailabilityMask; }
// Forward declaration of `EventKitEntityMask` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitEntityMask; }
// Forward declaration of `EventKitSource` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitSource; }
// Forward declaration of `EventKitSourceType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitSourceType; }
// Forward declaration of `EventKitEvent` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitEvent; }
// Forward declaration of `EventKitStructuredLocation` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitStructuredLocation; }
// Forward declaration of `EventKitGeoLocation` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitGeoLocation; }
// Forward declaration of `EventKitCoordinate` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCoordinate; }
// Forward declaration of `EventKitParticipant` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitParticipant; }
// Forward declaration of `EventKitParticipantStatus` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitParticipantStatus; }
// Forward declaration of `EventKitParticipantRole` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitParticipantRole; }
// Forward declaration of `EventKitParticipantType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitParticipantType; }
// Forward declaration of `EventKitPredicate` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitPredicate; }
// Forward declaration of `EventKitAvailability` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitAvailability; }
// Forward declaration of `EventKitStatus` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitStatus; }
// Forward declaration of `EventKitEntityType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitEntityType; }
// Forward declaration of `CreateEventOptions` to properly resolve imports.
namespace margelo::nitro::eventkit { struct CreateEventOptions; }

#include <NitroModules/Promise.hpp>
#include <vector>
#include "EventKitCalendar.hpp"
#include <string>
#include "EventKitCalendarType.hpp"
#include <optional>
#include "EventKitCalendarEventAvailabilityMask.hpp"
#include "EventKitEntityMask.hpp"
#include "EventKitSource.hpp"
#include "EventKitSourceType.hpp"
#include "EventKitEvent.hpp"
#include "EventKitStructuredLocation.hpp"
#include "EventKitGeoLocation.hpp"
#include "EventKitCoordinate.hpp"
#include "EventKitParticipant.hpp"
#include "EventKitParticipantStatus.hpp"
#include "EventKitParticipantRole.hpp"
#include "EventKitParticipantType.hpp"
#include "EventKitPredicate.hpp"
#include "EventKitAvailability.hpp"
#include "EventKitStatus.hpp"
#include "EventKitEntityType.hpp"
#include "CreateEventOptions.hpp"

#include "NitroEventKit-Swift-Cxx-Umbrella.hpp"

namespace margelo::nitro::eventkit {

  /**
   * The C++ part of HybridEventKitSpec_cxx.swift.
   *
   * HybridEventKitSpecSwift (C++) accesses HybridEventKitSpec_cxx (Swift), and might
   * contain some additional bridging code for C++ <> Swift interop.
   *
   * Since this obviously introduces an overhead, I hope at some point in
   * the future, HybridEventKitSpec_cxx can directly inherit from the C++ class HybridEventKitSpec
   * to simplify the whole structure and memory management.
   */
  class HybridEventKitSpecSwift: public virtual HybridEventKitSpec {
  public:
    // Constructor from a Swift instance
    explicit HybridEventKitSpecSwift(const NitroEventKit::HybridEventKitSpec_cxx& swiftPart):
      HybridObject(HybridEventKitSpec::TAG),
      _swiftPart(swiftPart) { }

  public:
    // Get the Swift part
    inline NitroEventKit::HybridEventKitSpec_cxx& getSwiftPart() noexcept {
      return _swiftPart;
    }

  public:
    // Get memory pressure
    inline size_t getExternalMemorySize() noexcept override {
      return _swiftPart.getMemorySize();
    }

  public:
    // Properties
    

  public:
    // Methods
    inline std::shared_ptr<Promise<std::vector<EventKitCalendar>>> getActiveCalendars() override {
      auto __result = _swiftPart.getActiveCalendars();
      if (__result.hasError()) [[unlikely]] {
        std::rethrow_exception(__result.error());
      }
      auto __value = std::move(__result.value());
      return __value;
    }
    inline std::shared_ptr<Promise<std::vector<EventKitEvent>>> getMonthlyCalendarEvents(EventKitEntityType entityType) override {
      auto __result = _swiftPart.getMonthlyCalendarEvents(static_cast<int>(entityType));
      if (__result.hasError()) [[unlikely]] {
        std::rethrow_exception(__result.error());
      }
      auto __value = std::move(__result.value());
      return __value;
    }
    inline std::shared_ptr<Promise<EventKitEvent>> createEvent(const CreateEventOptions& options) override {
      auto __result = _swiftPart.createEvent(options);
      if (__result.hasError()) [[unlikely]] {
        std::rethrow_exception(__result.error());
      }
      auto __value = std::move(__result.value());
      return __value;
    }
    inline std::shared_ptr<Promise<void>> openCalendarEvent(const std::string& eventIdentifier) override {
      auto __result = _swiftPart.openCalendarEvent(eventIdentifier);
      if (__result.hasError()) [[unlikely]] {
        std::rethrow_exception(__result.error());
      }
      auto __value = std::move(__result.value());
      return __value;
    }

  private:
    NitroEventKit::HybridEventKitSpec_cxx _swiftPart;
  };

} // namespace margelo::nitro::eventkit
