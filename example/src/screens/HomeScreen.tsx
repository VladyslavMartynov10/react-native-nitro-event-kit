import React from 'react';
import { View, Text, TouchableOpacity, StyleSheet } from 'react-native';
import { NativeStackNavigationProp } from '@react-navigation/native-stack';

type RootStackParamList = {
  Permissions: undefined;
  Calendars: undefined;
  Events: undefined;
  'Create Event': undefined;
  'Manage Event': undefined;
};

type HomeScreenProps = {
  navigation: NativeStackNavigationProp<RootStackParamList, 'Permissions'>;
};

export const HomeScreen: React.FC<HomeScreenProps> = ({ navigation }) => {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>React Native Nitro Event Kit</Text>

      <TouchableOpacity
        style={styles.button}
        onPress={() => navigation.navigate('Permissions')}>
        <Text style={styles.buttonText}>Check & Request Permissions</Text>
      </TouchableOpacity>

      <TouchableOpacity
        style={styles.button}
        onPress={() => navigation.navigate('Calendars')}>
        <Text style={styles.buttonText}>Get Active Calendars</Text>
      </TouchableOpacity>

      <TouchableOpacity
        style={styles.button}
        onPress={() => navigation.navigate('Events')}>
        <Text style={styles.buttonText}>Fetch Calendar Events</Text>
      </TouchableOpacity>

      <TouchableOpacity
        style={styles.button}
        onPress={() => navigation.navigate('Create Event')}>
        <Text style={styles.buttonText}>Create New Event</Text>
      </TouchableOpacity>

      <TouchableOpacity
        style={styles.button}
        onPress={() => navigation.navigate('Manage Event')}>
        <Text style={styles.buttonText}>Manage Events</Text>
      </TouchableOpacity>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#F7F8FC',
  },
  title: { fontSize: 22, fontWeight: 'bold', marginBottom: 20 },
  button: {
    backgroundColor: '#007AFF',
    padding: 12,
    margin: 10,
    borderRadius: 8,
    width: '80%',
    alignItems: 'center',
  },
  buttonText: { color: '#FFFFFF', fontSize: 16, fontWeight: 'bold' },
});
