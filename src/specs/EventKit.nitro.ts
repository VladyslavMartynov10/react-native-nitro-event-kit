import { type HybridObject } from 'react-native-nitro-modules'
import type {
  CreateEventOptions,
  EventKitCalendar,
  EventKitEvent,
} from './types'

export interface EventKit extends HybridObject<{ ios: 'swift' }> {
  getActiveCalendars(): Promise<EventKitCalendar[]>
  getMonthlyCalendarEvents(): Promise<EventKitEvent[]>
  createEvent(options: CreateEventOptions): Promise<EventKitEvent>
}
