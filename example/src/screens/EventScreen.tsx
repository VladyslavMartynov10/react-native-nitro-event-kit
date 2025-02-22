import React, { useState, useCallback } from 'react';
import {
  View,
  Text,
  TouchableOpacity,
  StyleSheet,
  FlatList,
} from 'react-native';
import {
  NitroEventKit,
  RangeEventOptions,
  EventKitEntityType,
  EventKitEvent,
} from 'react-native-nitro-event-kit';
import dayjs from 'dayjs';

export const EventsScreen: React.FC = () => {
  const [events, setEvents] = useState<EventKitEvent[]>([]);

  const fetchEvents = async () => {
    const options: RangeEventOptions = {
      startDate: dayjs().startOf('month').valueOf(),
      endDate: dayjs().endOf('month').valueOf(),
      entityType: EventKitEntityType.Event,
    };

    try {
      const fetchedEvents =
        await NitroEventKit.getCalendarEventsByRange(options);
      setEvents(fetchedEvents);
    } catch (error) {
      console.error('Error fetching events', error);
    }
  };

  const keyExtractor = useCallback(
    (item: EventKitEvent) => item.eventIdentifier,
    [],
  );

  const renderItem = useCallback(({ item }: { item: EventKitEvent }) => {
    const formattedStartDate = item.startDate
      ? dayjs(item.startDate).format('DD MMM YYYY, HH:mm')
      : 'N/A';
    const formattedEndDate = item.endDate
      ? dayjs(item.endDate).format('DD MMM YYYY, HH:mm')
      : 'N/A';

    return (
      <View style={styles.card}>
        <Text style={styles.title} selectable={true}>
          📅 {item.eventIdentifier || 'No ID'}
        </Text>
        <Text style={styles.text} selectable={true}>
          <Text style={styles.label} selectable={true}>
            Start:
          </Text>{' '}
          {formattedStartDate}
        </Text>
        <Text style={styles.text} selectable={true}>
          <Text style={styles.label} selectable={true}>
            End:
          </Text>{' '}
          {formattedEndDate}
        </Text>
        {item.isAllDay && (
          <Text style={styles.text} selectable={true}>
            <Text style={styles.label} selectable={true}>
              All Day:
            </Text>{' '}
            Yes
          </Text>
        )}
      </View>
    );
  }, []);

  return (
    <View style={styles.container}>
      <Text style={styles.screenTitle}>Calendar Events</Text>
      <TouchableOpacity style={styles.button} onPress={fetchEvents}>
        <Text style={styles.buttonText}>Fetch Events</Text>
      </TouchableOpacity>

      {events.length > 0 ? (
        <FlatList
          data={events}
          keyExtractor={keyExtractor}
          renderItem={renderItem}
          contentContainerStyle={styles.listContainer}
        />
      ) : (
        <Text style={styles.emptyText}>No events found</Text>
      )}
    </View>
  );
};

const styles = StyleSheet.create({
  container: { flex: 1, padding: 16, backgroundColor: '#F7F8FC' },
  screenTitle: {
    fontSize: 22,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 10,
  },
  button: {
    backgroundColor: '#007AFF',
    padding: 12,
    borderRadius: 8,
    alignItems: 'center',
    marginBottom: 16,
  },
  buttonText: { color: '#FFFFFF', fontSize: 16, fontWeight: 'bold' },
  listContainer: { paddingBottom: 20 },
  emptyText: {
    textAlign: 'center',
    marginTop: 20,
    fontSize: 16,
    color: '#666',
  },
  card: {
    backgroundColor: '#FFFFFF',
    padding: 16,
    marginVertical: 8,
    borderRadius: 8,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 4,
    elevation: 3,
  },
  title: { fontSize: 16, fontWeight: 'bold', marginBottom: 6 },
  text: { fontSize: 14, color: '#333', marginBottom: 2 },
  label: { fontWeight: 'bold', color: '#555' },
});
