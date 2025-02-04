import React from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  useColorScheme,
  Button,
} from 'react-native';
import {NitroEventKit} from 'react-native-nitro-event-kit';

import {Colors, Header} from 'react-native/Libraries/NewAppScreen';

function App(): React.JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    flex: 1,
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  const getMonthlyCalendarEvents = async () => {
    const events = await NitroEventKit.getMonthlyCalendarEvents();
    console.log(events);
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
      </ScrollView>
    </SafeAreaView>
  );
}

export default App;
