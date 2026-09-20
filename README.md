# CrowPanel 2.4-inch ESP32 HMI

A technical development repository for the **Elecrow CrowPanel 2.4-inch
ESP32 HMI Display**, covering hardware documentation, firmware examples,
display and touchscreen interfaces, peripheral communication, LVGL
applications, and embedded HMI projects.

The platform combines an **ESP32-WROOM-32-N4** with a 2.4-inch
320 × 240 TFT display, resistive touchscreen, Wi-Fi, Bluetooth,
TF card storage, UART, I²C, GPIO and audio interfaces.

---

## Hardware Overview

### Front View

The front side of the module integrates the **2.4-inch 320 × 240 TFT
touchscreen** along with the ESP32 controller board.

<p align="center">
  <img src="images/FR01.JPG" alt="Elecrow 2.4-inch ESP32 HMI Front View" width="600">
</p>

<p align="center">
  <b>FR01 — Front View of the Elecrow 2.4-inch ESP32 HMI</b>
</p>

---

### Mechanical Dimensions

The module has an approximate overall mechanical dimension of:

**78 mm × 51 mm**

The image below provides the reference width and height measurements.

<p align="center">
  <img src="images/FR02.JPG" alt="Elecrow 2.4-inch ESP32 HMI Dimensions" width="600">
</p>

<p align="center">
  <b>FR02 — Front View with Mechanical Dimensions</b>
</p>

---

### PCB Layout

The PCB view provides an overview of the component placement, connectors,
test points and major circuit sections of the module.

<p align="center">
  <img src="images/PB01.jpg" alt="Elecrow 2.4-inch ESP32 HMI PCB Layout" width="800">
</p>

<p align="center">
  <b>PB01 — PCB Layout and Component Placement</b>
</p>

---

### Rear / Component View

The rear/component view identifies the major onboard interfaces,
connectors and user-accessible hardware features including UART,
I²C, GPIO, battery, TF card, speaker, BOOT and RESET interfaces.

<p align="center">
  <img src="images/RR01.JPG" alt="Elecrow 2.4-inch ESP32 HMI Rear Component View" width="800">
</p>

<p align="center">
  <b>RR01 — Rear View with Connectors and Component Details</b>
</p>

---

## Features

- ESP32-WROOM-32-N4
- Dual-core 32-bit LX6 processor
- Up to 240 MHz
- 4 MB Flash
- 2.4-inch TFT LCD
- 320 × 240 resolution
- ILI9341V display controller
- Resistive touchscreen
- 2.4 GHz Wi-Fi
- Bluetooth
- TF / microSD card interface
- UART interface
- I²C interface
- GPIO interface
- Speaker interface
- Battery interface
- BOOT button
- RESET button
- LVGL support

---

# Hardware Specifications

| Parameter | Specification |
|---|---|
| MCU | ESP32-WROOM-32-N4 |
| CPU | Dual-core Xtensa LX6 |
| Maximum Frequency | 240 MHz |
| Flash | 4 MB |
| Display | 2.4-inch TFT LCD |
| Resolution | 320 × 240 |
| Display Controller | ILI9341V |
| Touch | Resistive |
| Wireless | 2.4 GHz Wi-Fi + Bluetooth |
| Storage | TF / microSD |
| USB | USB / USB-C |
| Battery Input | 3.7–4.2 V |
| Audio | Speaker interface |
| Dimensions | Approx. 78 × 51 mm |

---

# Pinout

## Display Interface

The TFT display uses an SPI interface.

| Function | ESP32 GPIO |
|---|---:|
| TFT MISO | GPIO12 |
| TFT MOSI | GPIO13 |
| TFT SCLK | GPIO14 |
| TFT CS | GPIO15 |
| TFT DC | GPIO2 |
| TFT RESET | -1 |
| TFT Backlight | GPIO27 |

---

## Touch Interface

The resistive touchscreen uses the SPI bus shared with the display.

| Function | ESP32 GPIO |
|---|---:|
| Touch CS | GPIO33 |
| Touch IRQ | GPIO36 |
| Touch SCLK | GPIO14 |
| Touch MOSI | GPIO13 |
| Touch MISO | GPIO12 |

---

## UART

### UART1

UART1 is available through the dedicated 4-pin connector.

| Signal | ESP32 GPIO |
|---|---:|
| RX | GPIO16 |
| TX | GPIO17 |

**Connector:** `UART1`

---

## I²C

The dedicated I²C connector provides access to external sensors,
peripherals and expansion modules.

| Signal | ESP32 GPIO |
|---|---:|
| SDA | GPIO22 |
| SCL | GPIO21 |

**Connector:** `I2C`

---

## GPIO

The GPIO-D connector provides two general-purpose digital I/O lines.

| Signal | ESP32 GPIO |
|---|---:|
| GPIO-D1 | GPIO25 |
| GPIO-D2 | GPIO32 |

**Connector:** `GPIO_D`

---

## Speaker

The board provides a dedicated speaker output connected to an onboard
audio amplifier circuit.

| Function | ESP32 GPIO |
|---|---:|
| Speaker | GPIO26 |

**Connector:** `SPK`

---

## TF / microSD Card

The TF card interface uses SPI communication.

| Signal | ESP32 GPIO |
|---|---:|
| MOSI | GPIO23 |
| MISO | GPIO19 |
| SCLK | GPIO18 |
| CS | GPIO5 |

The TF card can be used for:

- Image storage
- Configuration files
- Data logging
- HMI assets
- Fonts
- Application data

---

# Software Support

This repository primarily focuses on **Arduino-based development**, but
the hardware can also be used with multiple embedded software
frameworks and platforms.

- Arduino IDE
- PlatformIO
- ESP-IDF
- MicroPython
- LVGL
- ESPHome
- Home Assistant

---

# Arduino Libraries

Recommended libraries for the examples in this repository:

```text
Adafruit GFX Library
Adafruit ILI9341
XPT2046_Touchscreen
SD
SPI
Wire
WiFi
Bluetooth
LVGL
