import React, { useState } from 'react';
import {
  View,
  Text,
  TouchableOpacity,
  StyleSheet,
  Linking,
} from 'react-native';
import {
  NitroEventKitCalendarPermission,
  EventKitPermissionResult,
} from 'react-native-nitro-event-kit';

export const PermissionScreen: React.FC = () => {
  const [permissionStatus, setPermissionStatus] =
    useState<EventKitPermissionResult>('notDetermined');

  const checkPermission = () => {
    const status = NitroEventKitCalendarPermission.getPermissionsStatus();
    setPermissionStatus(status);
  };

  const requestPermission = async () => {
    const status = await NitroEventKitCalendarPermission.requestPermission();
    setPermissionStatus(status);
  };

  const openSettings = () => {
    Linking.openSettings();
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Calendar Permission</Text>
      <Text style={styles.status}>Status: {permissionStatus}</Text>

      <TouchableOpacity style={styles.button} onPress={requestPermission}>
        <Text style={styles.buttonText}>Request Permission</Text>
      </TouchableOpacity>

      <TouchableOpacity style={styles.button} onPress={checkPermission}>
        <Text style={styles.buttonText}>Check Permission</Text>
      </TouchableOpacity>

      {permissionStatus === 'denied' && (
        <TouchableOpacity
          style={[styles.button, styles.settingsButton]}
          onPress={openSettings}>
          <Text style={styles.buttonText}>Open Settings</Text>
        </TouchableOpacity>
      )}
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#F7F8FC',
    padding: 20,
  },
  title: { fontSize: 22, fontWeight: 'bold', marginBottom: 10 },
  status: { fontSize: 16, marginBottom: 20, color: '#333' },
  button: {
    backgroundColor: '#007AFF',
    padding: 12,
    margin: 10,
    borderRadius: 8,
    width: '100%',
    alignItems: 'center',
  },
  settingsButton: { backgroundColor: '#FF3B30' },
  buttonText: { color: '#FFFFFF', fontSize: 16, fontWeight: 'bold' },
});
