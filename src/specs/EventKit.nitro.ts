import { type HybridObject } from 'react-native-nitro-modules'
import type {
  CreateCalendarOptions,
  CreateEventOptions,
  EditEventOptions,
  EventKitCalendar,
  EventKitEvent,
  MonthlyEventOptions,
  RangeEventOptions,
} from './types'

export interface EventKit extends HybridObject<{ ios: 'swift' }> {
  getActiveCalendars(): Promise<EventKitCalendar[]>
  getMonthlyCalendarEvents(
    options: MonthlyEventOptions
  ): Promise<EventKitEvent[]>
  getCalendarEventsByRange(options: RangeEventOptions): Promise<EventKitEvent[]>
  createEvent(options: CreateEventOptions): Promise<EventKitEvent>
  deleteEvent(eventIdentifier: string): Promise<boolean>
  openCalendarEvent(eventIdentifier: string): Promise<void>
  createCalendar(options: CreateCalendarOptions): Promise<EventKitCalendar>
  editEvent(
    eventIdentifier: string,
    options: EditEventOptions
  ): Promise<EventKitEvent>
}
