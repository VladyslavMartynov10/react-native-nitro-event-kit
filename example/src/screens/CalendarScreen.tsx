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
  EventKitCalendar,
  EventKitCalendarType,
  EventKitSourceType,
} from 'react-native-nitro-event-kit';

export const CalendarScreen: React.FC = () => {
  const [calendars, setCalendars] = useState<EventKitCalendar[]>([]);

  const fetchCalendars = async () => {
    try {
      const data = await NitroEventKit.getActiveCalendars();
      setCalendars(data);
    } catch (error) {
      console.error('Error fetching calendars', error);
    }
  };

  const keyExtractor = useCallback(
    (item: EventKitCalendar) => item.calendarIdentifier,
    [],
  );

  const renderItem = useCallback(
    ({ item }: { item: EventKitCalendar }) => (
      <View style={styles.card}>
        <Text style={styles.title} selectable={true}>
          📅 {item.title}
        </Text>
        <Text style={styles.text} selectable={true}>
          <Text style={styles.label} selectable={true}>
            ID:
          </Text>{' '}
          {item.calendarIdentifier}
        </Text>
        <Text style={styles.text} selectable={true}>
          <Text style={styles.label} selectable={true}>
            Type:
          </Text>{' '}
          {EventKitCalendarType[item.type]}
        </Text>
        <Text style={styles.text} selectable={true}>
          <Text style={styles.label} selectable={true}>
            Allows Modifications:
          </Text>{' '}
          {item.allowsContentModifications ? 'Yes' : 'No'}
        </Text>
        {item.isSubscribed !== undefined && (
          <Text style={styles.text} selectable={true}>
            <Text style={styles.label} selectable={true}>
              Subscribed:
            </Text>{' '}
            {item.isSubscribed ? 'Yes' : 'No'}
          </Text>
        )}
        {item.isImmutable !== undefined && (
          <Text style={styles.text} selectable={true}>
            <Text style={styles.label} selectable={true}>
              Immutable:
            </Text>{' '}
            {item.isImmutable ? 'Yes' : 'No'}
          </Text>
        )}
        {item.cgColor && (
          <Text style={styles.text} selectable={true}>
            <Text style={styles.label} selectable={true}>
              Color:
            </Text>{' '}
            {item.cgColor}
          </Text>
        )}
        <Text style={styles.text} selectable={true}>
          <Text style={styles.label} selectable={true}>
            Source:
          </Text>{' '}
          {item.source.title} ({EventKitSourceType[item.source.sourceType]})
        </Text>
      </View>
    ),
    [],
  );

  return (
    <View style={styles.container}>
      <Text style={styles.screenTitle}>Active Calendars</Text>
      <TouchableOpacity style={styles.button} onPress={fetchCalendars}>
        <Text style={styles.buttonText}>Get Calendars</Text>
      </TouchableOpacity>

      {calendars.length > 0 ? (
        <FlatList
          data={calendars}
          keyExtractor={keyExtractor}
          renderItem={renderItem}
          contentContainerStyle={styles.listContainer}
        />
      ) : (
        <Text style={styles.emptyText}>No calendars available</Text>
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
