// TODO: Export all HybridObjects here for the user
import { NitroModules } from 'react-native-nitro-modules'

import type { EventKit } from './specs/EventKit.nitro'
import type { CalendarPermission } from './specs/CalendarPermission.nitro'

export const NitroEventKit =
  NitroModules.createHybridObject<EventKit>('EventKit')

export const NitroEventKitCalendarPermission =
  NitroModules.createHybridObject<CalendarPermission>('CalendarPermission')

export * from './specs/EventKit.nitro'
export * from './specs/CalendarPermission.nitro'
