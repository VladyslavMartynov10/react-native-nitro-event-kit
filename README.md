# 📅 React Native Nitro Event Kit

🔹 **React Native Nitro Event Kit** enables seamless access to iOS calendar events in your React Native applications. Fetch local events efficiently using the power of Nitro Modules.

---

## 🚀 Features

- **📆 Fetch Local Events**: Retrieve all events from the user’s iOS calendar.
- **⚡ Optimized Performance**: Built with Nitro for low-latency event retrieval.
- **🔒 Secure Access**: Requires user permission for accessing calendar data.
- **📱 Native iOS Integration**: Fully leverages iOS CalendarKit for accurate data.

---

## 🛠️ Prerequisites

Before getting started, ensure you have:

- React Native version `0.60+`
- [`react-native-nitro-modules`](https://www.npmjs.com/package/react-native-nitro-modules)
- **iOS 16+** (Native API support)

---

## 📦 Installation

Run the following command to install the package:

```bash
npm install react-native-nitro-event-kit react-native-nitro-modules

cd ios && pod install
```

Edit **`Info.plist`**. Add the following item (Set **Value** as desired):

| Key                                     | Type     | Value                                                                              |
| --------------------------------------- | -------- | ---------------------------------------------------------------------------------- |
| _Privacy - NSCalendarsUsageDescription_ | `String` | _CHANGEME: This app requires access to your calendar to create and manage events._ |

📝 Example usage

```

import {
  NitroEventKit,
  NitroEventKitCalendarPermission,
} from 'react-native-nitro-event-kit';

const fetchEvents = async () => {
  try {
    const events = await NitroEventKit.getLocalEvents()
    console.log('Fetched events:', events)
  } catch (error) {
    console.error('Error fetching calendar events:', error)
  }
}

const requestCalendarPermission = async () => {
    const status = await NitroEventKitCalendarPermission.requestPermission();
    console.log(status);
};

const checkCalendarPermission = () => {
    const status = NitroEventKitCalendarPermission.getPermissionsStatus();
    console.log(status);
};

```
