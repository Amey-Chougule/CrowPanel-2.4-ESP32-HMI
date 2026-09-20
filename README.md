# Elecrow 2.4-inch ESP32 HMI

![ESP32 HMI](assets/images/elecrow-2.4-hmi.jpg)

A collection of hardware documentation, Arduino examples, HMI projects,
LVGL interfaces and embedded applications for the Elecrow CrowPanel
2.4-inch ESP32 HMI Display.

The platform combines an ESP32-WROOM-32 microcontroller with a
2.4-inch 320×240 TFT display, resistive touchscreen, Wi-Fi, Bluetooth,
TF card storage and multiple peripheral interfaces.

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
- Wi-Fi 2.4 GHz
- Bluetooth
- TF/microSD card slot
- UART
- I²C
- GPIO
- Speaker interface
- Battery interface
- BOOT button
- RESET button
- LVGL support

---

## Hardware

| Parameter | Specification |
|---|---|
| MCU | ESP32-WROOM-32-N4 |
| CPU | Dual-core LX6 |
| Frequency | Up to 240 MHz |
| Flash | 4 MB |
| Display | 2.4" TFT LCD |
| Resolution | 320 × 240 |
| Display Driver | ILI9341V |
| Touch | Resistive |
| Wi-Fi | 2.4 GHz 802.11 b/g/n |
| Bluetooth | Bluetooth |
| Storage | TF / microSD |
| USB | USB / USB-C |
| Battery Input | 3.7–4.2 V |
| Speaker | Supported |
| Dimensions | Approximately 78 × 51 mm |

---

# Pinout

## Display

The display uses SPI communication.

| Function | ESP32 GPIO |
|---|---:|
| TFT MISO | GPIO12 |
| TFT MOSI | GPIO13 |
| TFT SCLK | GPIO14 |
| TFT CS | GPIO15 |
| TFT DC | GPIO2 |
| TFT RESET | -1 |
| TFT Backlight | GPIO27 |

## Touch

| Function | ESP32 GPIO |
|---|---:|
| Touch CS | GPIO33 |
| Touch IRQ | GPIO36 |
| Touch SPI Clock | GPIO14 |
| Touch MOSI | GPIO13 |
| Touch MISO | GPIO12 |

> Touch uses the SPI bus shared with the display.

---

## UART

### UART1

| Signal | GPIO |
|---|---:|
| RX | GPIO16 |
| TX | GPIO17 |

Connector:

`UART1`

---

## I²C

| Signal | GPIO |
|---|---:|
| SDA | GPIO22 |
| SCL | GPIO21 |

Connector:

`I2C`

---

## GPIO

The GPIO connector provides:

| GPIO |
|---:|
| GPIO25 |
| GPIO32 |

Connector:

`GPIO_D`

---

## Speaker

| Function | GPIO |
|---|---:|
| Speaker | GPIO26 |

The board includes an onboard amplifier circuit.

---

## TF / microSD

The TF card interface uses SPI.

| Signal | GPIO |
|---|---:|
| MOSI | GPIO23 |
| MISO | GPIO19 |
| SCLK | GPIO18 |
| CS | GPIO5 |

---

# Software Support

This repository primarily focuses on Arduino development, but the
hardware can also be used with:

- Arduino IDE
- PlatformIO
- ESP-IDF
- MicroPython
- LVGL
- ESPHome
- Home Assistant

---

# Arduino Libraries

Recommended libraries:

- Adafruit GFX
- Adafruit ILI9341
- XPT2046 Touch
- SD
- SPI
- Wire
- WiFi
- Bluetooth
- LVGL

---

# Getting Started

## 1. Install Arduino IDE

Install the Arduino IDE and add ESP32 board support.

Select:

`ESP32 Dev Module`

---

## 2. Install Libraries

Install the required display and touch libraries using the Arduino
Library Manager.

Example:

```text
Adafruit GFX Library
Adafruit ILI9341
XPT2046_Touchscreen
