///
/// NitroEventKit-Swift-Cxx-Bridge.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

// Forward declarations of C++ defined types
// Forward declaration of `EventKitAvailability` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitAvailability; }
// Forward declaration of `EventKitCalendarEventAvailabilityMask` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCalendarEventAvailabilityMask; }
// Forward declaration of `EventKitCalendarType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitCalendarType; }
// Forward declaration of `EventKitCalendar` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCalendar; }
// Forward declaration of `EventKitCoordinate` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitCoordinate; }
// Forward declaration of `EventKitEntityMask` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitEntityMask; }
// Forward declaration of `EventKitEvent` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitEvent; }
// Forward declaration of `EventKitGeoLocation` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitGeoLocation; }
// Forward declaration of `EventKitPermissionResult` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitPermissionResult; }
// Forward declaration of `EventKitSourceType` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitSourceType; }
// Forward declaration of `EventKitSource` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitSource; }
// Forward declaration of `EventKitStatus` to properly resolve imports.
namespace margelo::nitro::eventkit { enum class EventKitStatus; }
// Forward declaration of `EventKitStructuredLocation` to properly resolve imports.
namespace margelo::nitro::eventkit { struct EventKitStructuredLocation; }
// Forward declaration of `HybridCalendarPermissionSpec` to properly resolve imports.
namespace margelo::nitro::eventkit { class HybridCalendarPermissionSpec; }
// Forward declaration of `HybridEventKitSpec` to properly resolve imports.
namespace margelo::nitro::eventkit { class HybridEventKitSpec; }

// Forward declarations of Swift defined types
// Forward declaration of `HybridCalendarPermissionSpec_cxx` to properly resolve imports.
namespace NitroEventKit { class HybridCalendarPermissionSpec_cxx; }
// Forward declaration of `HybridEventKitSpec_cxx` to properly resolve imports.
namespace NitroEventKit { class HybridEventKitSpec_cxx; }

// Include C++ defined types
#include "EventKitAvailability.hpp"
#include "EventKitCalendar.hpp"
#include "EventKitCalendarEventAvailabilityMask.hpp"
#include "EventKitCalendarType.hpp"
#include "EventKitCoordinate.hpp"
#include "EventKitEntityMask.hpp"
#include "EventKitEvent.hpp"
#include "EventKitGeoLocation.hpp"
#include "EventKitPermissionResult.hpp"
#include "EventKitSource.hpp"
#include "EventKitSourceType.hpp"
#include "EventKitStatus.hpp"
#include "EventKitStructuredLocation.hpp"
#include "HybridCalendarPermissionSpec.hpp"
#include "HybridEventKitSpec.hpp"
#include <NitroModules/Promise.hpp>
#include <NitroModules/PromiseHolder.hpp>
#include <NitroModules/Result.hpp>
#include <exception>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

/**
 * Contains specialized versions of C++ templated types so they can be accessed from Swift,
 * as well as helper functions to interact with those C++ types from Swift.
 */
namespace margelo::nitro::eventkit::bridge::swift {

  // pragma MARK: std::shared_ptr<Promise<EventKitPermissionResult>>
  /**
   * Specialized version of `std::shared_ptr<Promise<EventKitPermissionResult>>`.
   */
  using std__shared_ptr_Promise_EventKitPermissionResult__ = std::shared_ptr<Promise<EventKitPermissionResult>>;
  inline std::shared_ptr<Promise<EventKitPermissionResult>> create_std__shared_ptr_Promise_EventKitPermissionResult__() {
    return Promise<EventKitPermissionResult>::create();
  }
  inline PromiseHolder<EventKitPermissionResult> wrap_std__shared_ptr_Promise_EventKitPermissionResult__(std::shared_ptr<Promise<EventKitPermissionResult>> promise) {
    return PromiseHolder<EventKitPermissionResult>(std::move(promise));
  }
  
  // pragma MARK: std::function<void(EventKitPermissionResult /* result */)>
  /**
   * Specialized version of `std::function<void(EventKitPermissionResult)>`.
   */
  using Func_void_EventKitPermissionResult = std::function<void(EventKitPermissionResult /* result */)>;
  /**
   * Wrapper class for a `std::function<void(EventKitPermissionResult / * result * /)>`, this can be used from Swift.
   */
  class Func_void_EventKitPermissionResult_Wrapper final {
  public:
    explicit Func_void_EventKitPermissionResult_Wrapper(std::function<void(EventKitPermissionResult /* result */)>&& func): _function(std::make_shared<std::function<void(EventKitPermissionResult /* result */)>>(std::move(func))) {}
    inline void call(int result) const {
      _function->operator()(static_cast<EventKitPermissionResult>(result));
    }
  private:
    std::shared_ptr<std::function<void(EventKitPermissionResult /* result */)>> _function;
  };
  Func_void_EventKitPermissionResult create_Func_void_EventKitPermissionResult(void* _Nonnull swiftClosureWrapper);
  inline Func_void_EventKitPermissionResult_Wrapper wrap_Func_void_EventKitPermissionResult(Func_void_EventKitPermissionResult value) {
    return Func_void_EventKitPermissionResult_Wrapper(std::move(value));
  }
  
  // pragma MARK: std::function<void(const std::exception_ptr& /* error */)>
  /**
   * Specialized version of `std::function<void(const std::exception_ptr&)>`.
   */
  using Func_void_std__exception_ptr = std::function<void(const std::exception_ptr& /* error */)>;
  /**
   * Wrapper class for a `std::function<void(const std::exception_ptr& / * error * /)>`, this can be used from Swift.
   */
  class Func_void_std__exception_ptr_Wrapper final {
  public:
    explicit Func_void_std__exception_ptr_Wrapper(std::function<void(const std::exception_ptr& /* error */)>&& func): _function(std::make_shared<std::function<void(const std::exception_ptr& /* error */)>>(std::move(func))) {}
    inline void call(std::exception_ptr error) const {
      _function->operator()(error);
    }
  private:
    std::shared_ptr<std::function<void(const std::exception_ptr& /* error */)>> _function;
  };
  Func_void_std__exception_ptr create_Func_void_std__exception_ptr(void* _Nonnull swiftClosureWrapper);
  inline Func_void_std__exception_ptr_Wrapper wrap_Func_void_std__exception_ptr(Func_void_std__exception_ptr value) {
    return Func_void_std__exception_ptr_Wrapper(std::move(value));
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>`.
   */
  using std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_ = std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>;
  std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec> create_std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_(std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_ cppType);
  
  // pragma MARK: std::weak_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>
  using std__weak_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_ = std::weak_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>;
  inline std__weak_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_ weakify_std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_(const std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>& strong) { return strong; }
  
  // pragma MARK: Result<EventKitPermissionResult>
  using Result_EventKitPermissionResult_ = Result<EventKitPermissionResult>;
  inline Result_EventKitPermissionResult_ create_Result_EventKitPermissionResult_(EventKitPermissionResult value) {
    return Result<EventKitPermissionResult>::withValue(std::move(value));
  }
  inline Result_EventKitPermissionResult_ create_Result_EventKitPermissionResult_(const std::exception_ptr& error) {
    return Result<EventKitPermissionResult>::withError(error);
  }
  
  // pragma MARK: Result<std::shared_ptr<Promise<EventKitPermissionResult>>>
  using Result_std__shared_ptr_Promise_EventKitPermissionResult___ = Result<std::shared_ptr<Promise<EventKitPermissionResult>>>;
  inline Result_std__shared_ptr_Promise_EventKitPermissionResult___ create_Result_std__shared_ptr_Promise_EventKitPermissionResult___(const std::shared_ptr<Promise<EventKitPermissionResult>>& value) {
    return Result<std::shared_ptr<Promise<EventKitPermissionResult>>>::withValue(value);
  }
  inline Result_std__shared_ptr_Promise_EventKitPermissionResult___ create_Result_std__shared_ptr_Promise_EventKitPermissionResult___(const std::exception_ptr& error) {
    return Result<std::shared_ptr<Promise<EventKitPermissionResult>>>::withError(error);
  }
  
  // pragma MARK: std::optional<bool>
  /**
   * Specialized version of `std::optional<bool>`.
   */
  using std__optional_bool_ = std::optional<bool>;
  inline std::optional<bool> create_std__optional_bool_(const bool& value) {
    return std::optional<bool>(value);
  }
  
  // pragma MARK: std::optional<std::string>
  /**
   * Specialized version of `std::optional<std::string>`.
   */
  using std__optional_std__string_ = std::optional<std::string>;
  inline std::optional<std::string> create_std__optional_std__string_(const std::string& value) {
    return std::optional<std::string>(value);
  }
  
  // pragma MARK: std::vector<EventKitCalendar>
  /**
   * Specialized version of `std::vector<EventKitCalendar>`.
   */
  using std__vector_EventKitCalendar_ = std::vector<EventKitCalendar>;
  inline std::vector<EventKitCalendar> create_std__vector_EventKitCalendar_(size_t size) {
    std::vector<EventKitCalendar> vector;
    vector.reserve(size);
    return vector;
  }
  
  // pragma MARK: std::shared_ptr<Promise<std::vector<EventKitCalendar>>>
  /**
   * Specialized version of `std::shared_ptr<Promise<std::vector<EventKitCalendar>>>`.
   */
  using std__shared_ptr_Promise_std__vector_EventKitCalendar___ = std::shared_ptr<Promise<std::vector<EventKitCalendar>>>;
  inline std::shared_ptr<Promise<std::vector<EventKitCalendar>>> create_std__shared_ptr_Promise_std__vector_EventKitCalendar___() {
    return Promise<std::vector<EventKitCalendar>>::create();
  }
  inline PromiseHolder<std::vector<EventKitCalendar>> wrap_std__shared_ptr_Promise_std__vector_EventKitCalendar___(std::shared_ptr<Promise<std::vector<EventKitCalendar>>> promise) {
    return PromiseHolder<std::vector<EventKitCalendar>>(std::move(promise));
  }
  
  // pragma MARK: std::function<void(const std::vector<EventKitCalendar>& /* result */)>
  /**
   * Specialized version of `std::function<void(const std::vector<EventKitCalendar>&)>`.
   */
  using Func_void_std__vector_EventKitCalendar_ = std::function<void(const std::vector<EventKitCalendar>& /* result */)>;
  /**
   * Wrapper class for a `std::function<void(const std::vector<EventKitCalendar>& / * result * /)>`, this can be used from Swift.
   */
  class Func_void_std__vector_EventKitCalendar__Wrapper final {
  public:
    explicit Func_void_std__vector_EventKitCalendar__Wrapper(std::function<void(const std::vector<EventKitCalendar>& /* result */)>&& func): _function(std::make_shared<std::function<void(const std::vector<EventKitCalendar>& /* result */)>>(std::move(func))) {}
    inline void call(std::vector<EventKitCalendar> result) const {
      _function->operator()(result);
    }
  private:
    std::shared_ptr<std::function<void(const std::vector<EventKitCalendar>& /* result */)>> _function;
  };
  Func_void_std__vector_EventKitCalendar_ create_Func_void_std__vector_EventKitCalendar_(void* _Nonnull swiftClosureWrapper);
  inline Func_void_std__vector_EventKitCalendar__Wrapper wrap_Func_void_std__vector_EventKitCalendar_(Func_void_std__vector_EventKitCalendar_ value) {
    return Func_void_std__vector_EventKitCalendar__Wrapper(std::move(value));
  }
  
  // pragma MARK: std::optional<EventKitGeoLocation>
  /**
   * Specialized version of `std::optional<EventKitGeoLocation>`.
   */
  using std__optional_EventKitGeoLocation_ = std::optional<EventKitGeoLocation>;
  inline std::optional<EventKitGeoLocation> create_std__optional_EventKitGeoLocation_(const EventKitGeoLocation& value) {
    return std::optional<EventKitGeoLocation>(value);
  }
  
  // pragma MARK: std::optional<EventKitStructuredLocation>
  /**
   * Specialized version of `std::optional<EventKitStructuredLocation>`.
   */
  using std__optional_EventKitStructuredLocation_ = std::optional<EventKitStructuredLocation>;
  inline std::optional<EventKitStructuredLocation> create_std__optional_EventKitStructuredLocation_(const EventKitStructuredLocation& value) {
    return std::optional<EventKitStructuredLocation>(value);
  }
  
  // pragma MARK: std::optional<double>
  /**
   * Specialized version of `std::optional<double>`.
   */
  using std__optional_double_ = std::optional<double>;
  inline std::optional<double> create_std__optional_double_(const double& value) {
    return std::optional<double>(value);
  }
  
  // pragma MARK: std::vector<EventKitEvent>
  /**
   * Specialized version of `std::vector<EventKitEvent>`.
   */
  using std__vector_EventKitEvent_ = std::vector<EventKitEvent>;
  inline std::vector<EventKitEvent> create_std__vector_EventKitEvent_(size_t size) {
    std::vector<EventKitEvent> vector;
    vector.reserve(size);
    return vector;
  }
  
  // pragma MARK: std::shared_ptr<Promise<std::vector<EventKitEvent>>>
  /**
   * Specialized version of `std::shared_ptr<Promise<std::vector<EventKitEvent>>>`.
   */
  using std__shared_ptr_Promise_std__vector_EventKitEvent___ = std::shared_ptr<Promise<std::vector<EventKitEvent>>>;
  inline std::shared_ptr<Promise<std::vector<EventKitEvent>>> create_std__shared_ptr_Promise_std__vector_EventKitEvent___() {
    return Promise<std::vector<EventKitEvent>>::create();
  }
  inline PromiseHolder<std::vector<EventKitEvent>> wrap_std__shared_ptr_Promise_std__vector_EventKitEvent___(std::shared_ptr<Promise<std::vector<EventKitEvent>>> promise) {
    return PromiseHolder<std::vector<EventKitEvent>>(std::move(promise));
  }
  
  // pragma MARK: std::function<void(const std::vector<EventKitEvent>& /* result */)>
  /**
   * Specialized version of `std::function<void(const std::vector<EventKitEvent>&)>`.
   */
  using Func_void_std__vector_EventKitEvent_ = std::function<void(const std::vector<EventKitEvent>& /* result */)>;
  /**
   * Wrapper class for a `std::function<void(const std::vector<EventKitEvent>& / * result * /)>`, this can be used from Swift.
   */
  class Func_void_std__vector_EventKitEvent__Wrapper final {
  public:
    explicit Func_void_std__vector_EventKitEvent__Wrapper(std::function<void(const std::vector<EventKitEvent>& /* result */)>&& func): _function(std::make_shared<std::function<void(const std::vector<EventKitEvent>& /* result */)>>(std::move(func))) {}
    inline void call(std::vector<EventKitEvent> result) const {
      _function->operator()(result);
    }
  private:
    std::shared_ptr<std::function<void(const std::vector<EventKitEvent>& /* result */)>> _function;
  };
  Func_void_std__vector_EventKitEvent_ create_Func_void_std__vector_EventKitEvent_(void* _Nonnull swiftClosureWrapper);
  inline Func_void_std__vector_EventKitEvent__Wrapper wrap_Func_void_std__vector_EventKitEvent_(Func_void_std__vector_EventKitEvent_ value) {
    return Func_void_std__vector_EventKitEvent__Wrapper(std::move(value));
  }
  
  // pragma MARK: std::shared_ptr<Promise<EventKitEvent>>
  /**
   * Specialized version of `std::shared_ptr<Promise<EventKitEvent>>`.
   */
  using std__shared_ptr_Promise_EventKitEvent__ = std::shared_ptr<Promise<EventKitEvent>>;
  inline std::shared_ptr<Promise<EventKitEvent>> create_std__shared_ptr_Promise_EventKitEvent__() {
    return Promise<EventKitEvent>::create();
  }
  inline PromiseHolder<EventKitEvent> wrap_std__shared_ptr_Promise_EventKitEvent__(std::shared_ptr<Promise<EventKitEvent>> promise) {
    return PromiseHolder<EventKitEvent>(std::move(promise));
  }
  
  // pragma MARK: std::function<void(const EventKitEvent& /* result */)>
  /**
   * Specialized version of `std::function<void(const EventKitEvent&)>`.
   */
  using Func_void_EventKitEvent = std::function<void(const EventKitEvent& /* result */)>;
  /**
   * Wrapper class for a `std::function<void(const EventKitEvent& / * result * /)>`, this can be used from Swift.
   */
  class Func_void_EventKitEvent_Wrapper final {
  public:
    explicit Func_void_EventKitEvent_Wrapper(std::function<void(const EventKitEvent& /* result */)>&& func): _function(std::make_shared<std::function<void(const EventKitEvent& /* result */)>>(std::move(func))) {}
    inline void call(EventKitEvent result) const {
      _function->operator()(result);
    }
  private:
    std::shared_ptr<std::function<void(const EventKitEvent& /* result */)>> _function;
  };
  Func_void_EventKitEvent create_Func_void_EventKitEvent(void* _Nonnull swiftClosureWrapper);
  inline Func_void_EventKitEvent_Wrapper wrap_Func_void_EventKitEvent(Func_void_EventKitEvent value) {
    return Func_void_EventKitEvent_Wrapper(std::move(value));
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec>`.
   */
  using std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_ = std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec>;
  std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec> create_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_ cppType);
  
  // pragma MARK: std::weak_ptr<margelo::nitro::eventkit::HybridEventKitSpec>
  using std__weak_ptr_margelo__nitro__eventkit__HybridEventKitSpec_ = std::weak_ptr<margelo::nitro::eventkit::HybridEventKitSpec>;
  inline std__weak_ptr_margelo__nitro__eventkit__HybridEventKitSpec_ weakify_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(const std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec>& strong) { return strong; }
  
  // pragma MARK: Result<std::shared_ptr<Promise<std::vector<EventKitCalendar>>>>
  using Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____ = Result<std::shared_ptr<Promise<std::vector<EventKitCalendar>>>>;
  inline Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____ create_Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____(const std::shared_ptr<Promise<std::vector<EventKitCalendar>>>& value) {
    return Result<std::shared_ptr<Promise<std::vector<EventKitCalendar>>>>::withValue(value);
  }
  inline Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____ create_Result_std__shared_ptr_Promise_std__vector_EventKitCalendar____(const std::exception_ptr& error) {
    return Result<std::shared_ptr<Promise<std::vector<EventKitCalendar>>>>::withError(error);
  }
  
  // pragma MARK: Result<std::shared_ptr<Promise<std::vector<EventKitEvent>>>>
  using Result_std__shared_ptr_Promise_std__vector_EventKitEvent____ = Result<std::shared_ptr<Promise<std::vector<EventKitEvent>>>>;
  inline Result_std__shared_ptr_Promise_std__vector_EventKitEvent____ create_Result_std__shared_ptr_Promise_std__vector_EventKitEvent____(const std::shared_ptr<Promise<std::vector<EventKitEvent>>>& value) {
    return Result<std::shared_ptr<Promise<std::vector<EventKitEvent>>>>::withValue(value);
  }
  inline Result_std__shared_ptr_Promise_std__vector_EventKitEvent____ create_Result_std__shared_ptr_Promise_std__vector_EventKitEvent____(const std::exception_ptr& error) {
    return Result<std::shared_ptr<Promise<std::vector<EventKitEvent>>>>::withError(error);
  }
  
  // pragma MARK: Result<std::shared_ptr<Promise<EventKitEvent>>>
  using Result_std__shared_ptr_Promise_EventKitEvent___ = Result<std::shared_ptr<Promise<EventKitEvent>>>;
  inline Result_std__shared_ptr_Promise_EventKitEvent___ create_Result_std__shared_ptr_Promise_EventKitEvent___(const std::shared_ptr<Promise<EventKitEvent>>& value) {
    return Result<std::shared_ptr<Promise<EventKitEvent>>>::withValue(value);
  }
  inline Result_std__shared_ptr_Promise_EventKitEvent___ create_Result_std__shared_ptr_Promise_EventKitEvent___(const std::exception_ptr& error) {
    return Result<std::shared_ptr<Promise<EventKitEvent>>>::withError(error);
  }

} // namespace margelo::nitro::eventkit::bridge::swift
