///
/// NitroEventKit-Swift-Cxx-Bridge.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "NitroEventKit-Swift-Cxx-Bridge.hpp"

// Include C++ implementation defined types
#include "HybridCalendarPermissionSpecSwift.hpp"
#include "HybridEventKitSpecSwift.hpp"
#include "NitroEventKit-Swift-Cxx-Umbrella.hpp"

namespace margelo::nitro::eventkit::bridge::swift {

  // pragma MARK: std::function<void(EventKitPermissionResult /* result */)>
  Func_void_EventKitPermissionResult create_Func_void_EventKitPermissionResult(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_EventKitPermissionResult::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](EventKitPermissionResult result) mutable -> void {
      swiftClosure.call(static_cast<int>(result));
    };
  }
  
  // pragma MARK: std::function<void(const std::exception_ptr& /* error */)>
  Func_void_std__exception_ptr create_Func_void_std__exception_ptr(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_std__exception_ptr::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](const std::exception_ptr& error) mutable -> void {
      swiftClosure.call(error);
    };
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec>
  std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpec> create_std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_(void* _Nonnull swiftUnsafePointer) {
    NitroEventKit::HybridCalendarPermissionSpec_cxx swiftPart = NitroEventKit::HybridCalendarPermissionSpec_cxx::fromUnsafe(swiftUnsafePointer);
    return std::make_shared<margelo::nitro::eventkit::HybridCalendarPermissionSpecSwift>(swiftPart);
  }
  void* _Nonnull get_std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_(std__shared_ptr_margelo__nitro__eventkit__HybridCalendarPermissionSpec_ cppType) {
    std::shared_ptr<margelo::nitro::eventkit::HybridCalendarPermissionSpecSwift> swiftWrapper = std::dynamic_pointer_cast<margelo::nitro::eventkit::HybridCalendarPermissionSpecSwift>(cppType);
  #ifdef NITRO_DEBUG
    if (swiftWrapper == nullptr) [[unlikely]] {
      throw std::runtime_error("Class \"HybridCalendarPermissionSpec\" is not implemented in Swift!");
    }
  #endif
    NitroEventKit::HybridCalendarPermissionSpec_cxx& swiftPart = swiftWrapper->getSwiftPart();
    return swiftPart.toUnsafe();
  }
  
  // pragma MARK: std::function<void(const std::vector<EventKitCalendar>& /* result */)>
  Func_void_std__vector_EventKitCalendar_ create_Func_void_std__vector_EventKitCalendar_(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_std__vector_EventKitCalendar_::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](const std::vector<EventKitCalendar>& result) mutable -> void {
      swiftClosure.call(result);
    };
  }
  
  // pragma MARK: std::function<void(const std::vector<EventKitEvent>& /* result */)>
  Func_void_std__vector_EventKitEvent_ create_Func_void_std__vector_EventKitEvent_(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_std__vector_EventKitEvent_::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](const std::vector<EventKitEvent>& result) mutable -> void {
      swiftClosure.call(result);
    };
  }
  
  // pragma MARK: std::function<void(const EventKitEvent& /* result */)>
  Func_void_EventKitEvent create_Func_void_EventKitEvent(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_EventKitEvent::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](const EventKitEvent& result) mutable -> void {
      swiftClosure.call(result);
    };
  }
  
  // pragma MARK: std::function<void(bool /* result */)>
  Func_void_bool create_Func_void_bool(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_bool::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](bool result) mutable -> void {
      swiftClosure.call(result);
    };
  }
  
  // pragma MARK: std::function<void()>
  Func_void create_Func_void(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)]() mutable -> void {
      swiftClosure.call();
    };
  }
  
  // pragma MARK: std::function<void(const EventKitCalendar& /* result */)>
  Func_void_EventKitCalendar create_Func_void_EventKitCalendar(void* _Nonnull swiftClosureWrapper) {
    auto swiftClosure = NitroEventKit::Func_void_EventKitCalendar::fromUnsafe(swiftClosureWrapper);
    return [swiftClosure = std::move(swiftClosure)](const EventKitCalendar& result) mutable -> void {
      swiftClosure.call(result);
    };
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec>
  std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpec> create_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(void* _Nonnull swiftUnsafePointer) {
    NitroEventKit::HybridEventKitSpec_cxx swiftPart = NitroEventKit::HybridEventKitSpec_cxx::fromUnsafe(swiftUnsafePointer);
    return std::make_shared<margelo::nitro::eventkit::HybridEventKitSpecSwift>(swiftPart);
  }
  void* _Nonnull get_std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_(std__shared_ptr_margelo__nitro__eventkit__HybridEventKitSpec_ cppType) {
    std::shared_ptr<margelo::nitro::eventkit::HybridEventKitSpecSwift> swiftWrapper = std::dynamic_pointer_cast<margelo::nitro::eventkit::HybridEventKitSpecSwift>(cppType);
  #ifdef NITRO_DEBUG
    if (swiftWrapper == nullptr) [[unlikely]] {
      throw std::runtime_error("Class \"HybridEventKitSpec\" is not implemented in Swift!");
    }
  #endif
    NitroEventKit::HybridEventKitSpec_cxx& swiftPart = swiftWrapper->getSwiftPart();
    return swiftPart.toUnsafe();
  }

} // namespace margelo::nitro::eventkit::bridge::swift
