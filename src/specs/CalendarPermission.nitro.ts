import { type HybridObject } from 'react-native-nitro-modules'
import type { EKEventPermissionResult } from './types'

export interface CalendarPermission extends HybridObject<{ ios: 'swift' }> {
  getPermissionsStatus(): EKEventPermissionResult
  requestPermission(): Promise<EKEventPermissionResult>
}
