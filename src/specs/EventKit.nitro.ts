import { type HybridObject } from 'react-native-nitro-modules'
import type {
  CreateEventOptions,
  EventKitCalendar,
  EventKitEntityType,
  EventKitEvent,
} from './types'

export interface EventKit extends HybridObject<{ ios: 'swift' }> {
  getActiveCalendars(): Promise<EventKitCalendar[]>
  getMonthlyCalendarEvents(
    entityType: EventKitEntityType
  ): Promise<EventKitEvent[]>
  createEvent(options: CreateEventOptions): Promise<EventKitEvent>
  openCalendarEvent(eventIdentifier: string): Promise<void>
}
