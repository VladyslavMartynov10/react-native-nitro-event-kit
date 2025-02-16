import React from 'react';
import { StyleSheet } from 'react-native';
import { GestureHandlerRootView } from 'react-native-gesture-handler';
import { SafeAreaProvider } from 'react-native-safe-area-context';
import { RootNavigator } from './src/navigation';

export const App: React.FC = () => (
  <GestureHandlerRootView style={styles.layout}>
    <SafeAreaProvider>
      <RootNavigator />
    </SafeAreaProvider>
  </GestureHandlerRootView>
);

const styles = StyleSheet.create({
  layout: {
    flex: 1,
  },
});
