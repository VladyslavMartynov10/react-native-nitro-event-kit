import React, { useState } from 'react';
import {
  View,
  Text,
  TextInput,
  TouchableOpacity,
  Alert,
  StyleSheet,
} from 'react-native';
import { NitroEventKit } from 'react-native-nitro-event-kit';

export const ManageEventScreen: React.FC = () => {
  const [eventIdentifier, setEventIdentifier] = useState('');

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

  return (
    <View style={styles.container}>
      <Text style={styles.title} selectable={true}>
        Manage Events
      </Text>

      <TextInput
        style={styles.input}
        placeholder="Enter Event Identifier"
        value={eventIdentifier}
        onChangeText={setEventIdentifier}
      />

      <TouchableOpacity style={styles.button} onPress={openEvent}>
        <Text style={styles.buttonText}>Open Event</Text>
      </TouchableOpacity>

      <TouchableOpacity
        style={[styles.button, styles.deleteButton]}
        onPress={deleteEvent}>
        <Text style={styles.buttonText}>Delete Event</Text>
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
