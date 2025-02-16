import React from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  useColorScheme,
  Button,
} from 'react-native';
import {
  NitroEventKit,
  NitroEventKitCalendarPermission,
  EventKitEntityType,
  CreateEventOptions,
  RangeEventOptions,
} from 'react-native-nitro-event-kit';
import dayjs from 'dayjs';

import { Colors, Header } from 'react-native/Libraries/NewAppScreen';

function App(): JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  const getMonthlyCalendarEvents = async (entityType: EventKitEntityType) => {
    try {
      const events = await NitroEventKit.getMonthlyCalendarEvents(entityType);

      console.log(events);
    } catch (error) {
      console.log(error);
    }
  };

  const getActiveCalendars = async () => {
    try {
      const calendars = await NitroEventKit.getActiveCalendars();

      console.log(calendars);
    } catch (error) {
      console.log(error);
    }
  };

  const requestCalendarPermission = async () => {
    const status = await NitroEventKitCalendarPermission.requestPermission();
    console.log(status);
  };

  const checkCalendarPermission = () => {
    const status = NitroEventKitCalendarPermission.getPermissionsStatus();
    console.log(status);
  };

  const openCalendarEvent = async (eventIdentifier: string) => {
    try {
      await NitroEventKit.openCalendarEvent(eventIdentifier);
    } catch (error) {
      console.log(error, 'error');
    }
  };

  const deleteEvent = async (eventIdentifier: string) => {
    try {
      const test = await NitroEventKit.deleteEvent(eventIdentifier);

      console.log(test, 'test');
    } catch (error) {
      console.log(error, 'error');
    }
  };

  const createEvent = async () => {
    const event = {
      notes: 'Test Event',
      location: 'Test Location',
      title: 'Test Event',
      startDate: dayjs().add(1, 'hour').valueOf(),
      endDate: dayjs().add(2, 'hour').valueOf(),
      isCalendarImmutable: false,
      scheduleAlarmMinutesBefore: 10,
      scheduleAlarm: true,
      calendarIdentifier: '66C97F38-EB2B-4F6F-9E51-EEE42646A7BC',
    } satisfies CreateEventOptions;

    try {
      const test = await NitroEventKit.createEvent(event);

      console.log(test, 'test event');
    } catch (error) {
      console.log(error);

      console.log('here errror');
    }
  };
  const getRangeCalendarEvents = async () => {
    const options = {
      startDate: dayjs().startOf('month').valueOf(),
      endDate: dayjs().endOf('month').valueOf(),
      entityType: EventKitEntityType.Event,
    } satisfies RangeEventOptions;

    try {
      const events = await NitroEventKit.getCalendarEventsByRange(options);
      console.log(events, 'events');
    } catch (error) {
      console.log(error, 'Error fetching events');
    }
  };

  return (
    <SafeAreaView style={backgroundStyle}>
      <StatusBar
        barStyle={isDarkMode ? 'light-content' : 'dark-content'}
        backgroundColor={backgroundStyle.backgroundColor}
      />
      <ScrollView
        contentInsetAdjustmentBehavior="automatic"
        style={backgroundStyle}>
        <Header />

        <Button
          title="Get Monthly Events"
          onPress={() => getMonthlyCalendarEvents(EventKitEntityType.Event)}
        />

        <Button
          title="Request Calendar Permission"
          onPress={requestCalendarPermission}
        />

        <Button
          title="Check Calendar Permission"
          onPress={checkCalendarPermission}
        />

        <Button
          title="Open Calendar Event"
          onPress={() =>
            openCalendarEvent(
              '4AAD3EF8-BA21-4AF1-8D4D-7977C4457FA9:338C2180-D6AC-446F-B7B8-CD9FA12664C1',
            )
          }
        />

        <Button
          title="Delete Event"
          onPress={() =>
            deleteEvent(
              '4AAD3EF8-BA21-4AF1-8D4D-7977C4457FA9:B2F50C0D-10AB-4E7E-8ED9-257061C858CE',
            )
          }
        />

        <Button title="Get Range Events" onPress={getRangeCalendarEvents} />

        <Button title="Create Event" onPress={createEvent} />

        <Button title="Get Active Calendars" onPress={getActiveCalendars} />
      </ScrollView>
    </SafeAreaView>
  );
}

export default App;
