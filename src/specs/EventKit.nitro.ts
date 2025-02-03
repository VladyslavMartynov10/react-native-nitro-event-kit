import { type HybridObject } from 'react-native-nitro-modules'
import type { EKEvent } from './types'

export interface EventKit extends HybridObject<{ ios: 'swift' }> {
  getMonthlyCalendarEvents(): Promise<EKEvent[]>
}
