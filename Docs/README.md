# Documentation

This directory contains the technical documentation and development references for the **CrowPanel 2.4-inch ESP32 HMI** project.

The documents cover the ESP32-WROOM-32 hardware platform, Arduino IDE programming setup, and the technical specifications of the CrowPanel HMI module.

---

## Documents

### 1. ESP32 Arduino IDE Programming Guide

**File:** `esp32-arduino-ide-programming-guide-original.pdf`

A step-by-step guide for setting up ESP32 development in the Arduino IDE.

Topics covered include:

- Arduino IDE setup
- ESP32 Boards Manager configuration
- Adding the ESP32 board package
- Installing **ESP32 by Espressif Systems**
- Selecting the ESP32 development board
- Selecting the serial/COM port
- Uploading firmware
- Basic ESP32 programming
- BOOT/programming-mode troubleshooting

This document is intended as the starting point for configuring a development environment before programming the CrowPanel ESP32 HMI.

---

### 2. CrowPanel 2.4-inch ESP32 HMI Technical Specifications

**File:** `crowpanel-2.4inch-esp32-hmi-technical-specifications.pdf`

Technical reference documentation for the **Elecrow CrowPanel 2.4-inch ESP32 HMI**.

The document covers:

- ESP32-WROOM-32-N4 specifications
- 2.4-inch TFT display
- 320 × 240 display resolution
- Resistive touchscreen
- ILI9341V display controller
- Wi-Fi and Bluetooth
- TF / microSD interface
- UART interfaces
- I²C interface
- GPIO interface
- Speaker interface
- Battery interface
- BOOT and RESET controls
- Display GPIO mapping
- Touch GPIO mapping
- TF card GPIO mapping
- Mechanical dimensions
- PCB and connector reference
- Supported software frameworks and libraries
- Typical embedded HMI applications

---

### 3. ESP32-WROOM-32E / ESP32-WROOM-32UE Datasheet

**File:** `esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf`

Manufacturer datasheet reference for the **ESP32-WROOM-32E** and **ESP32-WROOM-32UE** modules.

This document is provided as the hardware-level reference for understanding the ESP32 module used as the core processing platform.

It can be used when working with:

- ESP32 module specifications
- GPIO functionality
- Peripheral interfaces
- Electrical characteristics
- Power requirements
- Wireless capabilities
- Module pin configuration
- Hardware design considerations

---

## Documentation Structure

```text
docs/
│
├── README.md
│
├── esp32-arduino-ide-programming-guide-original.pdf
│   └── ESP32 Arduino IDE programming setup
│
├── crowpanel-2.4inch-esp32-hmi-technical-specifications.pdf
│   └── CrowPanel HMI hardware specifications
│
└── esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf
    └── ESP32-WROOM module datasheet
```

---

## Recommended Reading Order

For new users or developers working with this repository:

**1 → Arduino IDE Programming Guide**

Set up the ESP32 development environment.

**2 → CrowPanel HMI Technical Specifications**

Understand the CrowPanel hardware, interfaces and GPIO assignments.

**3 → ESP32-WROOM Datasheet**

Refer to the underlying ESP32-WROOM module documentation for detailed hardware and electrical information.

---

## Scope

The `docs` directory is intended to serve as the central technical documentation reference for the **CrowPanel 2.4-inch ESP32 HMI** development repository.

Additional documentation, application notes, interface guides and project-specific references can be added to this directory as the project evolves.
