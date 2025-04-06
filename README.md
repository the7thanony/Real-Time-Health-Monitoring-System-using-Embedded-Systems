# Real-Time-Health-Monitoring-System-using-Embedded-Systems
ESP32-based Health Monitoring System simulating pulse (60-130bpm) &amp; temperature (36-39.5°C) with LCD display. Includes emergency alerts (LED/buzzer) when thresholds are exceeded. Built with Wokwi simulator for hardware-free testing. Open-source, IoT-ready design for future sensor/cloud integration. Ideal for medical IoT prototyping.


# ESP32-Based Health Monitoring System with Simulated Sensors
# Project Overview
This project implements a real-time health monitoring system using the ESP32 microcontroller, designed to track heart rate (pulse) and body temperature with emergency alert functionality. Built as a low-cost embedded system, it serves as a prototype for wearable medical devices, demonstrating how IoT and embedded systems can be used for remote patient monitoring.

Since this is a simulation-based project, it uses potentiometers to mimic medical sensor inputs, making it ideal for testing and development without requiring physical hardware. The system includes:

LCD display for real-time vital sign visualization

Buzzer & LED for emergency alerts

Wokwi simulator for virtual testing

The project is fully open-source, with Arduino-based firmware, making it easy to modify, extend, or integrate with real sensors in the future.

# Key Features
1. Simulated Health Monitoring
Pulse Rate (60–130 bpm):

Simulated using a potentiometer (GPIO14)

Random fluctuations mimic natural heart rate variability

Body Temperature (36.0–39.5°C):

Simulated via a second potentiometer (GPIO27)

Automatically adjusts with minor random variations

# 2. Emergency Alert System
Visual & Audio Warnings:

🔴 Red LED (GPIO2) lights up when thresholds are exceeded

🔔 Buzzer (GPIO4) sounds at 1030Hz for critical alerts

Thresholds:

Pulse ≥ 100 bpm (tachycardia)

Temperature ≥ 38.0°C (fever)

# 3. Real-Time Data Display
16x2 I2C LCD Screen shows:

Copy
Pulse: 85 bpm  
Temp: 36.5°C  
Updates every second for continuous monitoring

# 4. Simulated "Danger Mode" (Testing Feature)
5% random chance to trigger high pulse/temperature

Tests the system’s alert response without manual input

# 5. IoT-Ready Architecture
ESP32’s built-in Wi-Fi/Bluetooth allows future cloud integration (e.g., ThingSpeak, Blynk)

Scalable design – can replace potentiometers with real sensors (MAX30100, LM35)

Technical Implementation
Hardware Components
Component	Role	Connection
ESP32 DevKit-C	Main MCU	-
Potentiometer 1	Pulse Simulator	GPIO14 (ADC)
Potentiometer 2	Temp Simulator	GPIO27 (ADC)
I2C LCD (16x2)	Display	GPIO21 (SDA), GPIO22 (SCL)
Buzzer	Audio Alert	GPIO4
Red LED	Visual Alert	GPIO2 (with 220Ω resistor)
Software & Libraries
Arduino IDE (C++ firmware)

LiquidCrystal_I2C (LCD control)

Wokwi Simulator (virtual testing)

# Why This Project?
1. Cost-Effective Medical Prototyping
Uses <$10 in components (vs. commercial health monitors)

Simulator allows zero-cost testing before hardware investment

2. Modular & Customizable
Easily upgradable to real sensors (Pulse Sensor, LM35)

Code can be adapted for different thresholds (pediatric/geriatric)

3. Open-Source & Reproducible
Full GitHub repository with schematics, code, and docs

Ideal for students, researchers, and hobbyists

4. Foundation for IoT Health Devices
Can be extended to:

Telemedicine apps (send alerts to doctors)

Cloud-based patient records (ThingSpeak, Firebase)

Wearable integration (3D-printed casing, battery optimization)

# Future Enhancements
✅ Replace potentiometers with real sensors (MAX30100 for pulse, DS18B20 for temp)
✅ Add Wi-Fi logging (ThingSpeak, Blynk, or MQTT)
✅ Implement deep sleep mode for battery-powered wearables
✅ Mobile app integration (BLE notifications to smartphones)

# How to Use This Project
Simulation (Wokwi):

Open the project in Wokwi (link in repo)

Adjust potentiometers to simulate vital signs

Observe alerts when thresholds are crossed

Hardware Deployment:

Assemble the circuit (ESP32 + LCD + buzzer + LED)

Upload the Arduino sketch

Test with real sensors (future upgrade)
