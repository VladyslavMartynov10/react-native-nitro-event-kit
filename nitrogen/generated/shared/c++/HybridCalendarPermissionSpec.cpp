///
/// HybridCalendarPermissionSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridCalendarPermissionSpec.hpp"

namespace margelo::nitro::eventkit {

  void HybridCalendarPermissionSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("getPermissionsStatus", &HybridCalendarPermissionSpec::getPermissionsStatus);
      prototype.registerHybridMethod("requestPermission", &HybridCalendarPermissionSpec::requestPermission);
    });
  }

} // namespace margelo::nitro::eventkit
