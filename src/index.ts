// TODO: Export all HybridObjects here for the user
import { NitroModules } from 'react-native-nitro-modules'

import type { EventKit } from './specs/EventKit.nitro'

export const NitroEventKit =
  NitroModules.createHybridObject<EventKit>('EventKit')

export * from './specs/EventKit.nitro'
