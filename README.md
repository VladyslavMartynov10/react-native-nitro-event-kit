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

📝 Examples

📆 Fetch Local Events

```
import { NitroEventKit } from 'react-native-nitro-eventkit'

const fetchEvents = async () => {
  try {
    const events = await NitroEventKit.getLocalEvents()
    console.log('Fetched events:', events)
  } catch (error) {
    console.error('Error fetching calendar events:', error)
  }
}

fetchEvents()
```