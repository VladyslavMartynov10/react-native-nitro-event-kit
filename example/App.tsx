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
} from 'react-native-nitro-event-kit';

import { Colors, Header } from 'react-native/Libraries/NewAppScreen';

function App(): React.JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  const getMonthlyCalendarEvents = async () => {
    try {
      const events = await NitroEventKit.getMonthlyCalendarEvents();

      console.log(events);
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

        <Button title="Get Monthly Events" onPress={getMonthlyCalendarEvents} />
        <Button
          title="Request Calendar Permission"
          onPress={requestCalendarPermission}
        />
        <Button
          title="Check Calendar Permission"
          onPress={checkCalendarPermission}
        />
      </ScrollView>
    </SafeAreaView>
  );
}

export default App;
