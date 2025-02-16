///
/// HybridEventKitSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridEventKitSpec.hpp"

namespace margelo::nitro::eventkit {

  void HybridEventKitSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("getActiveCalendars", &HybridEventKitSpec::getActiveCalendars);
      prototype.registerHybridMethod("getMonthlyCalendarEvents", &HybridEventKitSpec::getMonthlyCalendarEvents);
      prototype.registerHybridMethod("getCalendarEventsByRange", &HybridEventKitSpec::getCalendarEventsByRange);
      prototype.registerHybridMethod("createEvent", &HybridEventKitSpec::createEvent);
      prototype.registerHybridMethod("deleteEvent", &HybridEventKitSpec::deleteEvent);
      prototype.registerHybridMethod("openCalendarEvent", &HybridEventKitSpec::openCalendarEvent);
    });
  }

} // namespace margelo::nitro::eventkit
