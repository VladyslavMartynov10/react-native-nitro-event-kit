import { type HybridObject } from 'react-native-nitro-modules'
import type {
  CreateEventOptions,
  EventKitCalendar,
  EventKitEvent,
} from './types'

export interface EventKit extends HybridObject<{ ios: 'swift' }> {
  createEvent(options: CreateEventOptions): Promise<EventKitEvent>
  getActiveCalendars(): Promise<EventKitCalendar[]>
  getMonthlyCalendarEvents(): Promise<EventKitEvent[]>
}
