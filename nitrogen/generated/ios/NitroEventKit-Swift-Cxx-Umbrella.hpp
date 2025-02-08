///
/// NitroEventKit-Swift-Cxx-Umbrella.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

// Forward declarations of C++ defined types
// Forward declaration of `CreateEventOptions` to properly resolve imports.
namespace margelo::nitro::eventkit { struct CreateEventOptions; }
// Forward declaration of `EventKitAvailability` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitAvailability; }
// Forward declaration of `EventKitCalendarEventAvailabilityMask` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCalendarEventAvailabilityMask; }
// Forward declaration of `EventKitCalendarType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitCalendarType; }
// Forward declaration of `EventKitCalendar` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCalendar; }
// Forward declaration of `EventKitEntityMask` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitEntityMask; }
// Forward declaration of `EventKitEvent` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitEvent; }
// Forward declaration of `EventKitPermissionResult` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitPermissionResult; }
// Forward declaration of `EventKitSourceType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitSourceType; }
// Forward declaration of `EventKitSource` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitSource; }
// Forward declaration of `EventKitStatus` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitStatus; }
// Forward declaration of `HybridCalendarPermissionSpec` to properly resolve imports.
namespace margelo::nitro::eventkit { class HybridCalendarPermissionSpec; }
// Forward declaration of `HybridEventKitSpec` to properly resolve imports.
namespace margelo::nitro::eventkit { class HybridEventKitSpec; }

// Include C++ defined types
#include "CreateEventOptions.hpp"
#include "EventKitAvailability.hpp"
#include "EventKitCalendar.hpp"
#include "EventKitCalendarEventAvailabilityMask.hpp"
#include "EventKitCalendarType.hpp"
#include "EventKitEntityMask.hpp"
#include "EventKitEvent.hpp"
#include "EventKitPermissionResult.hpp"
#include "EventKitSource.hpp"
#include "EventKitSourceType.hpp"
#include "EventKitStatus.hpp"
#include "HybridCalendarPermissionSpec.hpp"
#include "HybridEventKitSpec.hpp"
#include <NitroModules/Promise.hpp>
#include <NitroModules/Result.hpp>
#include <exception>
#include <memory>
#include <optional>
#include <string>
#include <vector>

// C++ helpers for Swift
#include "NitroEventKit-Swift-Cxx-Bridge.hpp"

// Common C++ types used in Swift
#include <NitroModules/ArrayBufferHolder.hpp>
#include <NitroModules/AnyMapHolder.hpp>
#include <NitroModules/HybridContext.hpp>
#include <NitroModules/RuntimeError.hpp>

// Forward declarations of Swift defined types
// Forward declaration of `HybridCalendarPermissionSpec_cxx` to properly resolve imports.
namespace NitroEventKit { class HybridCalendarPermissionSpec_cxx; }
// Forward declaration of `HybridEventKitSpec_cxx` to properly resolve imports.
namespace NitroEventKit { class HybridEventKitSpec_cxx; }

// Include Swift defined types
#if __has_include("NitroEventKit-Swift.h")
// This header is generated by Xcode/Swift on every app build.
// If it cannot be found, make sure the Swift module's name (= podspec name) is actually "NitroEventKit".
#include "NitroEventKit-Swift.h"
// Same as above, but used when building with frameworks (`use_frameworks`)
#elif __has_include(<NitroEventKit/NitroEventKit-Swift.h>)
#include <NitroEventKit/NitroEventKit-Swift.h>
#else
#error NitroEventKit's autogenerated Swift header cannot be found! Make sure the Swift module's name (= podspec name) is actually "NitroEventKit", and try building the app first.
#endif
