import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import {
  CalendarScreen,
  CreateEventScreen,
  EventsScreen,
  HomeScreen,
  ManageEventScreen,
  PermissionScreen,
} from '../screens';

export const Stack = createNativeStackNavigator();

export const RootNavigator: React.FC = () => {
  return (
    <NavigationContainer>
      <Stack.Navigator>
        <Stack.Screen name="Home" component={HomeScreen} />
        <Stack.Screen name="Permissions" component={PermissionScreen} />
        <Stack.Screen name="Calendars" component={CalendarScreen} />
        <Stack.Screen name="Events" component={EventsScreen} />
        <Stack.Screen name="Create Event" component={CreateEventScreen} />
        <Stack.Screen name="Manage Event" component={ManageEventScreen} />
      </Stack.Navigator>
    </NavigationContainer>
  );
};
