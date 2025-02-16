# 📅 React Native Nitro Event Kit

🔹 **React Native Nitro Event Kit** enables seamless access to iOS calendar events in your React Native applications. Fetch local events efficiently using the power of Nitro Modules.

---

## 🚀 Features

- **📆 Fetch Local Events**: Retrieve all events from the user’s iOS calendar.
- **⚡ Optimized Performance**: Built with Nitro for low-latency event retrieval.
- **🔒 Secure Access**: Requires user permission for accessing calendar data.
- **📱 Native iOS Integration**: Fully leverages iOS CalendarKit for accurate data.

---

## 🛠️ Prerequisites

Before getting started, ensure you have:

- React Native version `0.75+`
- [`react-native-nitro-modules`](https://www.npmjs.com/package/react-native-nitro-modules)
- **iOS 16+** (Native API support)
- new architecture support

---

## 📦 Installation

Run the following command to install the package:

```bash
npm install react-native-nitro-event-kit react-native-nitro-modules

yarn add react-native-nitro-event-kit react-native-nitro-modules

cd ios && pod install
```

Edit **`Info.plist`**. Add the following item (Set **Value** as desired):

| Key                                     | Type     | Value                                                                              |
| --------------------------------------- | -------- | ---------------------------------------------------------------------------------- |
| _Privacy - NSCalendarsUsageDescription_ | `String` | _CHANGEME: This app requires access to your calendar to create and manage events._ |

🎯 API Reference

### 📜 Permissions Statuses in React Native Nitro Event Kit

Permission checks and requests resolve into one of the following statuses:

| **Return Value**      | **Description**                                                               |
| --------------------- | ----------------------------------------------------------------------------- |
| **`"unavailable"`**   | This feature is not available on the current device or in this context.       |
| **`"denied"`**        | The user has not granted permission, but it is requestable.                   |
| **`"restricted"`**    | The permission is restricted due to parental controls or device policies.     |
| **`"fullAccess"`**    | The permission has been granted, and the app has full access to the calendar. |
| **`"writeOnly"`**     | The app can write to the calendar but cannot read existing events.            |
| **`"notDetermined"`** | The user has not been asked for permission yet.                               |

These statuses help determine whether the app can **read, write, or modify calendar events**. If the status is `"denied"` or `"restricted"`, users must **manually enable permissions** in the device settings.

📌 Example Usage

✅ Checking Permission Status

To check the current status of calendar permissions, use:

```ts
import { NitroEventKitCalendarPermission } from 'react-native-nitro-event-kit';

const checkCalendarPermission = () => {
  const status = NitroEventKitCalendarPermission.getPermissionsStatus();
  console.log('Current permission status:', status);
};
```

🔄 Requesting Permission

To request calendar access from the user, use:

```ts
import { NitroEventKitCalendarPermission } from 'react-native-nitro-event-kit';

const requestCalendarPermission = async () => {
  try {
    const status = await NitroEventKitCalendarPermission.requestPermission();
    console.log('Updated permission status:', status);
  } catch (error) {
    console.error('Error requesting permission:', error);
  }
};
```

### 📆 Calendar Methods

Below are the methods available in **React Native Nitro Event Kit**, allowing you to interact with the iOS calendar system.

---

### Get Active Calendars

Retrieves all active calendars available on the device.

```ts
NitroEventKit.getActiveCalendars(): Promise<EventKitCalendar[]>
```

📌 Example Usage

```ts
import { NitroEventKit } from 'react-native-nitro-event-kit';

const getActiveCalendars = async () => {
  try {
    const calendars = await NitroEventKit.getActiveCalendars();
    console.log('Active Calendars:', calendars);
  } catch (error) {
    console.error('Error fetching calendars:', error);
  }
};
```

### Get Monthly Calendar Events

Fetches all calendar events for the current month.

```ts
NitroEventKit.getMonthlyCalendarEvents(entityType: EventKitEntityType): Promise<EventKitEvent[]>
```

📌 Example Usage

```ts
import {
  NitroEventKit,
  EventKitEntityType,
} from 'react-native-nitro-event-kit';

const getMonthlyEvents = async () => {
  try {
    const events = await NitroEventKit.getMonthlyCalendarEvents(
      EventKitEntityType.Event,
    );
    console.log('Monthly Events:', events);
  } catch (error) {
    console.error('Error fetching monthly events:', error);
  }
};
```

### Get Events in Date Range

Fetches calendar events within a specific date range.

```ts
NitroEventKit.getCalendarEventsByRange(options: RangeEventOptions): Promise<EventKitEvent[]>
```

📌 Example Usage

```ts
import {
  NitroEventKit,
  EventKitEntityType,
} from 'react-native-nitro-event-kit';
import dayjs from 'dayjs';

const getEventsByRange = async () => {
  const options = {
    startDate: dayjs().startOf('month').valueOf(),
    endDate: dayjs().endOf('month').valueOf(),
    entityType: EventKitEntityType.Event,
  };

  try {
    const events = await NitroEventKit.getCalendarEventsByRange(options);
    console.log('Events in Range:', events);
  } catch (error) {
    console.error('Error fetching events in range:', error);
  }
};
```

### Create a New Event

Creates a new event in the specified calendar.

```ts
NitroEventKit.createEvent(options: CreateEventOptions): Promise<EventKitEvent>
```

📌 Example Usage

```ts
import { NitroEventKit } from 'react-native-nitro-event-kit';
import dayjs from 'dayjs';

const createEvent = async () => {
  const eventOptions = {
    title: 'Meeting with Team',
    location: 'Office',
    notes: 'Discuss project updates',
    startDate: dayjs().add(1, 'hour').valueOf(),
    endDate: dayjs().add(2, 'hour').valueOf(),
    calendarIdentifier: '66C97F38-EB2B-4F6F-9E51-EEE42646A7BC',
    isCalendarImmutable: false,
    scheduleAlarmMinutesBefore: 10,
    scheduleAlarm: true,
  };

  try {
    const newEvent = await NitroEventKit.createEvent(eventOptions);
    console.log('Event Created:', newEvent);
  } catch (error) {
    console.error('Error creating event:', error);
  }
};
```

### Delete an Event

Deletes an event by its event identifier.

```ts
NitroEventKit.deleteEvent(eventIdentifier: string): Promise<boolean>
```

📌 Example Usage

```ts
import { NitroEventKit } from 'react-native-nitro-event-kit';

const deleteEvent = async (eventId: string) => {
  try {
    const success = await NitroEventKit.deleteEvent(eventId);
    console.log(success ? 'Event Deleted' : 'Failed to Delete Event');
  } catch (error) {
    console.error('Error deleting event:', error);
  }
};
```

### Open an Event in the iOS View Controller (WIP)

Opens a specific event in the native iOS Calendar app.

```ts
NitroEventKit.openCalendarEvent(eventIdentifier: string): Promise<void>
```

📌 Example Usage

```ts
import { NitroEventKit } from 'react-native-nitro-event-kit';

const openEventInCalendar = async (eventId: string) => {
  try {
    await NitroEventKit.openCalendarEvent(eventId);
    console.log('Calendar event opened successfully');
  } catch (error) {
    console.error('Error opening calendar event:', error);
  }
};
```
