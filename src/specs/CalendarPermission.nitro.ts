import { type HybridObject } from 'react-native-nitro-modules'
import type { EventKitPermissionResult } from './types'

export interface CalendarPermission extends HybridObject<{ ios: 'swift' }> {
  getPermissionsStatus(): EventKitPermissionResult
  requestPermission(): Promise<EventKitPermissionResult>
}
