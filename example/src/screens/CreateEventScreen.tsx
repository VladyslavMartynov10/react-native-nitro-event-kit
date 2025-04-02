import React, { useState } from 'react';
import {
  View,
  Text,
  TextInput,
  TouchableOpacity,
  StyleSheet,
  Alert,
} from 'react-native';
import {
  NitroEventKit,
  CreateEventOptions,
} from 'react-native-nitro-event-kit';
import dayjs from 'dayjs';

export const CreateEventScreen: React.FC = () => {
  const [title, setTitle] = useState('');
  const [notes, setNotes] = useState('');
  const [calendarIdentifier, setCalendarIdentifier] = useState('');
  const [startDate] = useState(dayjs().add(1, 'day').startOf('day').valueOf());
  const [endDate] = useState(dayjs().add(1, 'day').endOf('day').valueOf());
  const [scheduleAlarm, setScheduleAlarm] = useState(false);
  const [scheduleAlarmMinutesBefore, setScheduleAlarmMinutesBefore] =
    useState(10);

  const [locationTitle, setLocationTitle] = useState('');
  const [longitudeLocation, setLongitudeLocation] = useState('');
  const [latitudeLocation, setLatitudeLocation] = useState('');

  const createEvent = async () => {
    if (!title || !calendarIdentifier) {
      Alert.alert('Error', 'Title and Calendar ID are required!');
      return;
    }

    const options: CreateEventOptions = {
      title,
      notes,
      calendarIdentifier,
      startDate,
      endDate,
      scheduleAlarm,
      isCalendarImmutable: false,
      scheduleAlarmMinutesBefore: scheduleAlarm
        ? scheduleAlarmMinutesBefore
        : undefined,
      location:
        longitudeLocation &&
        latitudeLocation &&
        !isNaN(+latitudeLocation) &&
        !isNaN(+longitudeLocation)
          ? {
              title: locationTitle,
              latitude: +latitudeLocation,
              longitude: +longitudeLocation,
            }
          : undefined,
    };

    try {
      const createdEvent = await NitroEventKit.createEvent(options);
      Alert.alert('Success', `Event Created: ${createdEvent.eventIdentifier}`);
      console.log('Created Event:', createdEvent);
    } catch (error) {
      console.error('Error creating event:', error);
      Alert.alert('Error', 'Failed to create event.');
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Create New Event</Text>

      <TextInput
        style={styles.input}
        placeholder="Event Title"
        value={title}
        onChangeText={setTitle}
      />

      <TextInput
        style={styles.input}
        placeholder="Event Notes"
        value={notes}
        onChangeText={setNotes}
      />

      <TextInput
        style={styles.input}
        placeholder="Calendar ID"
        value={calendarIdentifier}
        onChangeText={setCalendarIdentifier}
      />

      <TextInput
        style={styles.input}
        placeholder="Location Title"
        value={locationTitle}
        onChangeText={setLocationTitle}
      />

      <TextInput
        style={styles.input}
        placeholder="Location Latitude"
        value={latitudeLocation}
        onChangeText={setLatitudeLocation}
        keyboardType="numeric"
      />

      <TextInput
        style={styles.input}
        placeholder="Location Longitude"
        value={longitudeLocation}
        onChangeText={setLongitudeLocation}
        keyboardType="numeric"
      />

      <Text style={styles.label}>
        Start Date: {dayjs(startDate).format('DD MMM YYYY, HH:mm')}
      </Text>
      <Text style={styles.label}>
        End Date: {dayjs(endDate).format('DD MMM YYYY, HH:mm')}
      </Text>

      <TouchableOpacity
        style={[styles.button, scheduleAlarm ? styles.activeButton : {}]}
        onPress={() => setScheduleAlarm(!scheduleAlarm)}>
        <Text style={styles.buttonText}>
          {scheduleAlarm ? 'Disable Alarm' : 'Enable Alarm'}
        </Text>
      </TouchableOpacity>

      {scheduleAlarm && (
        <TextInput
          style={styles.input}
          placeholder="Alarm Minutes Before"
          keyboardType="numeric"
          value={scheduleAlarmMinutesBefore.toString()}
          onChangeText={text =>
            setScheduleAlarmMinutesBefore(Number(text) || 0)
          }
        />
      )}

      <TouchableOpacity style={styles.createButton} onPress={createEvent}>
        <Text style={styles.buttonText}>Create Event</Text>
      </TouchableOpacity>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    padding: 20,
    backgroundColor: '#F7F8FC',
  },
  title: { fontSize: 22, fontWeight: 'bold', marginBottom: 20 },
  input: {
    width: '100%',
    padding: 12,
    marginVertical: 8,
    borderWidth: 1,
    borderColor: '#ccc',
    borderRadius: 8,
  },
  label: { fontSize: 14, fontWeight: 'bold', marginTop: 10 },
  button: {
    backgroundColor: '#007AFF',
    padding: 12,
    margin: 10,
    borderRadius: 8,
    width: '100%',
    alignItems: 'center',
  },
  activeButton: { backgroundColor: '#28A745' },
  createButton: {
    backgroundColor: '#007AFF',
    padding: 12,
    marginTop: 20,
    borderRadius: 8,
    width: '100%',
    alignItems: 'center',
  },
  buttonText: { color: '#FFFFFF', fontSize: 16, fontWeight: 'bold' },
});
