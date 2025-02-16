import { type HybridObject } from 'react-native-nitro-modules'
import type {
  CreateEventOptions,
  EventKitCalendar,
  EventKitEntityType,
  EventKitEvent,
  RangeEventOptions,
} from './types'

export interface EventKit extends HybridObject<{ ios: 'swift' }> {
  getActiveCalendars(): Promise<EventKitCalendar[]>
  getMonthlyCalendarEvents(
    entityType: EventKitEntityType
  ): Promise<EventKitEvent[]>
  getCalendarEventsByRange(options: RangeEventOptions): Promise<EventKitEvent[]>
  createEvent(options: CreateEventOptions): Promise<EventKitEvent>
  deleteEvent(eventIdentifier: string): Promise<boolean>
  openCalendarEvent(eventIdentifier: string): Promise<void>
}
