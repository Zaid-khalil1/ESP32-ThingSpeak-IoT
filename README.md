# ESP32 Temperature and Humidity Monitoring

## Project Description
This project uses an ESP32 and a DHT22 sensor to measure temperature and humidity. The ESP32 connects to Wi-Fi and sends readings to ThingSpeak every 20 seconds. ThingSpeak displays the data using cloud charts.

## Student Information
- **Full Name:** Zaid Raed Marouf Khalil
- **University ID:** 12219777
- **University:** An-Najah National University

## Components
- ESP32 DevKit
- DHT22 Temperature and Humidity Sensor
- Wokwi Simulator
- ThingSpeak Cloud Platform

## Wiring
| DHT22 Pin | ESP32 Pin |
|---|---|
| VCC | 3V3 |
| GND | GND.1 |
| DATA | GPIO 15 |

The wiring configuration is provided in `diagram.json`.

## Wokwi Simulation
[Open the Wokwi Project](https://wokwi.com/projects/478872122902055937)

## ThingSpeak Channel
- **Channel ID:** 3549918
- **Public Channel URL:** https://thingspeak.mathworks.com/channels/3549918
- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)

## Source Code
The Arduino source code is provided in `sketch.ino`.

For security, the public source code uses a placeholder instead of the real ThingSpeak Write API Key. Replace it with your own key to run the code.

## Test Results
The simulation successfully connected to Wi-Fi and sent readings to ThingSpeak.

- Temperature: 24.0 °C
- Humidity: 40.0%
- ThingSpeak HTTP Response: 200
- Entry ID: 1

## Update Interval
New readings are sent every 20 seconds.
