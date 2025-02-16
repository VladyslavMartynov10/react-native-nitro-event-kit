import React, { useState, useCallback, useEffect } from 'react';
import {
  SafeAreaView,
  StatusBar,
  FlatList,
  Text,
  TouchableOpacity,
  StyleSheet,
  Linking,
} from 'react-native';
import {
  NitroEventKit,
  NitroEventKitCalendarPermission,
  EventKitEntityType,
  RangeEventOptions,
  EventKitEvent,
  EventKitPermissionResult,
} from 'react-native-nitro-event-kit';
import dayjs from 'dayjs';

export const TestScreen: React.FC = () => {
  const [events, setEvents] = useState<EventKitEvent[]>([]);
  const [permissionStatus, setPermissionStatus] =
    useState<EventKitPermissionResult>('notDetermined');

  useEffect(() => {
    const checkCalendarPermission = () => {
      const status = NitroEventKitCalendarPermission.getPermissionsStatus();
      setPermissionStatus(status);
    };

    checkCalendarPermission();
  }, []);

  const requestCalendarPermission = async () => {
    const status = await NitroEventKitCalendarPermission.requestPermission();
    setPermissionStatus(status);
  };

  const openSettings = () => {
    Linking.openSettings();
  };

  const getRangeCalendarEvents = async () => {
    const options: RangeEventOptions = {
      startDate: dayjs().startOf('month').valueOf(),
      endDate: dayjs().endOf('month').valueOf(),
      entityType: EventKitEntityType.Event,
    };

    try {
      const fetchedEvents =
        await NitroEventKit.getCalendarEventsByRange(options);
      setEvents(fetchedEvents);
      console.log(fetchedEvents, 'Fetched Events');
    } catch (error) {
      console.log(error, 'Error fetching events');
    }
  };

  const openCalendarEvent = useCallback(async (eventIdentifier: string) => {
    try {
      await NitroEventKit.openCalendarEvent(eventIdentifier);
    } catch (error) {
      console.log(error, 'Error opening event');
    }
  }, []);

  const keyExtractor = useCallback(
    (item: EventKitEvent) => item.eventIdentifier,
    [],
  );

  const renderItem = useCallback(
    ({ item }: { item: EventKitEvent }) => {
      const formattedStartDate = item.startDate
        ? dayjs(item.startDate).format('DD MMM YYYY, HH:mm')
        : 'N/A';
      const formattedEndDate = item.endDate
        ? dayjs(item.endDate).format('DD MMM YYYY, HH:mm')
        : 'N/A';

      return (
        <TouchableOpacity
          style={styles.eventCard}
          onLongPress={() => openCalendarEvent(item.eventIdentifier)}>
          <Text style={styles.eventTitle}>📅 {item.eventIdentifier}</Text>
          <Text style={styles.eventText}>
            <Text style={styles.label}>Start:</Text> {formattedStartDate}
          </Text>
          <Text style={styles.eventText}>
            <Text style={styles.label}>End:</Text> {formattedEndDate}
          </Text>
          {item.isAllDay && (
            <Text style={styles.eventText}>
              <Text style={styles.label}>All Day:</Text> Yes
            </Text>
          )}
        </TouchableOpacity>
      );
    },
    [openCalendarEvent],
  );

  return (
    <SafeAreaView style={styles.container}>
      <StatusBar barStyle="dark-content" />

      {permissionStatus === 'notDetermined' && (
        <TouchableOpacity
          style={styles.button}
          onPress={requestCalendarPermission}>
          <Text style={styles.buttonText}>Request Permission</Text>
        </TouchableOpacity>
      )}

      {permissionStatus === 'denied' && (
        <TouchableOpacity
          style={[styles.button, styles.warningButton]}
          onPress={openSettings}>
          <Text style={styles.buttonText}>Go to Settings</Text>
        </TouchableOpacity>
      )}

      {permissionStatus === 'fullAccess' && (
        <>
          <TouchableOpacity
            style={styles.button}
            onPress={getRangeCalendarEvents}>
            <Text style={styles.buttonText}>Get Range Events</Text>
          </TouchableOpacity>

          <FlatList
            data={events}
            keyExtractor={keyExtractor}
            renderItem={renderItem}
            contentContainerStyle={styles.listContainer}
            ListEmptyComponent={
              <Text style={styles.emptyText}>No events found</Text>
            }
          />
        </>
      )}
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#F7F8FC',
  },
  button: {
    backgroundColor: '#007AFF',
    padding: 12,
    margin: 16,
    borderRadius: 8,
    alignItems: 'center',
  },
  warningButton: {
    backgroundColor: '#FF3B30',
  },
  buttonText: {
    color: '#FFFFFF',
    fontSize: 16,
    fontWeight: 'bold',
  },
  listContainer: {
    paddingBottom: 20,
  },
  emptyText: {
    textAlign: 'center',
    marginTop: 20,
    fontSize: 16,
    color: '#666',
  },
  eventCard: {
    backgroundColor: '#FFFFFF',
    marginHorizontal: 16,
    marginVertical: 8,
    padding: 16,
    borderRadius: 8,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 4,
    elevation: 3,
  },
  eventTitle: {
    fontSize: 16,
    fontWeight: 'bold',
    marginBottom: 6,
  },
  eventText: {
    fontSize: 14,
    color: '#333',
  },
  label: {
    fontWeight: 'bold',
    color: '#555',
  },
});
