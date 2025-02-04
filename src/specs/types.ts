export enum EKEventAvailability {
  NotSupported = -1,
  Busy = 0,
  Free = 1,
  Tentative = 2,
  Unavailable = 3,
}

export enum EKEventStatus {
  None = 0,
  Confirmed = 1,
  Tentative = 2,
  Canceled = 3,
}

export enum EKParticipantRole {
  Unknown = 0,
  Required = 1,
  Optional = 2,
  Chair = 3,
  NonParticipant = 4,
}

export enum EKParticipantStatus {
  Unknown = 0,
  Pending = 1,
  Accepted = 2,
  Declined = 3,
  Tentative = 4,
  Delegated = 5,
  Completed = 6,
  InProcess = 7,
}

export interface EKEvent {
  eventIdentifier: string
  isAllDay: boolean
  startDate: number
  endDate: number
  availability: EKEventAvailability
  status: EKEventStatus
  isDetached: boolean
  occurrenceDate?: number
  birthdayContactIdentifier?: string
}

export type EKEventPermissionResult =
  | 'denied'
  | 'notDetermined'
  | 'restricted'
  | 'fullAccess'
  | 'writeOnly'
  | 'unavailable'
