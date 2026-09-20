# HMI Button Control Example

This example demonstrates a basic **touch-controlled button interface** for the Elecrow CrowPanel 2.4-inch ESP32 HMI.

The application provides four touchscreen buttons that can be individually toggled between **ON** and **OFF** states.

## Overview

The example demonstrates:

- TFT display initialization
- Touchscreen initialization
- Backlight control
- SPI communication
- Touch coordinate mapping
- Touch button detection
- Button state management
- ON/OFF state visualization
- Touch event handling
- Serial Monitor debugging

## Output

The example displays a simple HMI control interface with four touchscreen buttons.

Each button can be pressed to toggle its state:

- **Red** → OFF
- **Green** → ON

![2x4 Button HMI](./2x4_button.png)

The image above shows the touchscreen button interface running on the CrowPanel display.

## Hardware

- Elecrow CrowPanel 2.4-inch ESP32 HMI
- ESP32-WROOM-32
- 2.4-inch 320×240 ILI9341 TFT Display
- XPT2046 resistive touchscreen

## TFT Configuration

| Function | GPIO |
|---|---:|
| TFT CS | GPIO 15 |
| TFT DC | GPIO 2 |
| TFT SCLK | GPIO 14 |
| TFT MOSI | GPIO 13 |
| TFT MISO | GPIO 4 |
| TFT Backlight | GPIO 27 |
| TFT Reset | ESP32 EN / RESET |

## Touch Configuration

| Function | GPIO |
|---|---:|
| Touch CS | GPIO 33 |
| Touch IRQ | GPIO 36 |

## Touch Calibration

The example uses the following touchscreen calibration values:

| Parameter | Value |
|---|---:|
| TS_MIN_X | 200 |
| TS_MAX_X | 3900 |
| TS_MIN_Y | 200 |
| TS_MAX_Y | 3900 |

The touch coordinate conversion uses an **inverted X-axis** and a **normal Y-axis** mapping.

## Required Libraries

- Adafruit GFX Library
- Adafruit ILI9341
- XPT2046_Touchscreen
- SPI

## Button Layout

The interface contains four buttons:

| Button | Position | Default State |
|---|---|---|
| BUTTON 1 | Top Left | OFF |
| BUTTON 2 | Top Right | OFF |
| BUTTON 3 | Bottom Left | OFF |
| BUTTON 4 | Bottom Right | OFF |

Each button has a size of approximately **130 × 60 pixels**.

## Button Operation

When a button is touched:

1. The touchscreen coordinates are read.
2. Raw coordinates are converted to screen coordinates.
3. The program checks which button was pressed.
4. The button state is toggled.
5. The button is redrawn.
6. The new state is printed to the Serial Monitor.
7. The system waits for the finger to be released.

### Button States

```text
OFF → Red
ON  → Green