import React, { useState } from 'react';
import {
  Text,
  TextInput,
  TouchableOpacity,
  Alert,
  StyleSheet,
  ScrollView,
} from 'react-native';
import { NitroEventKit } from 'react-native-nitro-event-kit';

export const ManageEventScreen: React.FC = () => {
  const [eventIdentifier, setEventIdentifier] = useState('');

  const [newTitle, setNewTitle] = useState('');
  const [newLocation, setNewLocation] = useState('');
  const [newNotes, setNewNotes] = useState('');
  const [newStartDate, setNewStartDate] = useState(0);
  const [newEndDate, setNewEndDate] = useState(0);
  const [newCalendarId, setNewCalendarId] = useState('');

  const openEvent = async () => {
    if (!eventIdentifier.trim()) {
      Alert.alert('Error', 'Please enter a valid Event ID.');
      return;
    }

    try {
      await NitroEventKit.openCalendarEvent(eventIdentifier);
      console.log(`Opened event: ${eventIdentifier}`);
    } catch (error) {
      console.error('Error opening event:', error);
      Alert.alert('Error', 'Failed to open event.');
    }
  };

  const deleteEvent = async () => {
    if (!eventIdentifier.trim()) {
      Alert.alert('Error', 'Please enter a valid Event ID.');
      return;
    }

    try {
      const success = await NitroEventKit.deleteEvent(eventIdentifier);
      if (success) {
        Alert.alert('Success', `Deleted event: ${eventIdentifier}`);
        setEventIdentifier(''); // Clear input after deletion
      }
    } catch (error) {
      console.error('Error deleting event:', error);
      Alert.alert('Error', 'Failed to delete event.');
    }
  };

  const editEvent = async () => {
    if (!eventIdentifier.trim()) {
      Alert.alert('Error', 'Please enter a valid Event ID.');
      return;
    }

    try {
      const editedEvent = await NitroEventKit.editEvent(eventIdentifier, {
        title: newTitle || undefined,
        notes: newNotes || undefined,
        startDate: newStartDate || undefined,
        endDate: newEndDate || undefined,
        location: newLocation || undefined,
        calendarId: newCalendarId || undefined,
      });

      Alert.alert('Success', `Event Edited: ${editedEvent.eventIdentifier}`);
      console.log('Edited Event:', editedEvent);
    } catch (error) {
      console.error('Error editing event:', error);
      Alert.alert('Error', 'Failed to edit event.');
    }
  };

  return (
    <ScrollView contentContainerStyle={styles.container}>
      <Text style={styles.title} selectable={true}>
        Manage Events
      </Text>

      <TextInput
        style={styles.input}
        placeholder="Enter Event Identifier"
        value={eventIdentifier}
        onChangeText={setEventIdentifier}
      />

      <TextInput
        style={styles.input}
        placeholder="Enter New Title"
        value={newTitle}
        onChangeText={setNewTitle}
      />
      <TextInput
        style={styles.input}
        placeholder="Enter New Location"
        value={newLocation}
        onChangeText={setNewLocation}
      />
      <TextInput
        style={styles.input}
        placeholder="Enter New Notes"
        value={newNotes}
        onChangeText={setNewNotes}
      />
      <TextInput
        style={styles.input}
        placeholder="Enter New Start Date"
        value={String(newStartDate)}
        onChangeText={newValue => setNewStartDate(Number(newValue))}
        keyboardType="numeric"
      />
      <TextInput
        style={styles.input}
        placeholder="Enter New End Date"
        value={String(newEndDate)}
        onChangeText={newValue => setNewEndDate(Number(newValue))}
      />
      <TextInput
        style={styles.input}
        placeholder="Enter New Calendar Id"
        value={newCalendarId}
        onChangeText={setNewCalendarId}
      />

      <TouchableOpacity style={styles.button} onPress={openEvent}>
        <Text style={styles.buttonText}>Open Event</Text>
      </TouchableOpacity>

      <TouchableOpacity style={styles.button} onPress={editEvent}>
        <Text style={styles.buttonText}>Edit Event</Text>
      </TouchableOpacity>

      <TouchableOpacity
        style={[styles.button, styles.deleteButton]}
        onPress={deleteEvent}>
        <Text style={styles.buttonText}>Delete Event</Text>
      </TouchableOpacity>
    </ScrollView>
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
  button: {
    backgroundColor: '#007AFF',
    padding: 12,
    marginTop: 10,
    borderRadius: 8,
    width: '100%',
    alignItems: 'center',
  },
  deleteButton: { backgroundColor: '#FF3B30' },
  buttonText: { color: '#FFFFFF', fontSize: 16, fontWeight: 'bold' },
});
