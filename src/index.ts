import { NitroModules } from 'react-native-nitro-modules'

import type { EventKit } from './specs/EventKit.nitro'
import type { CalendarPermission } from './specs/CalendarPermission.nitro'

export const NitroEventKit =
  NitroModules.createHybridObject<EventKit>('EventKit')

export const NitroEventKitCalendarPermission =
  NitroModules.createHybridObject<CalendarPermission>('CalendarPermission')

export * from './specs/types'
