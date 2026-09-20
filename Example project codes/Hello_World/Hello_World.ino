#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// -------------------------
// TFT Pin Configuration
// -------------------------
#define TFT_CS    15
#define TFT_DC     2
#define TFT_RST  -1       // TFT reset is connected to ESP32 EN/reset
#define TFT_SCLK  14
#define TFT_MOSI  13

#define TFT_BL    27      // Backlight control

// Create TFT object
Adafruit_ILI9341 tft = Adafruit_ILI9341(
  TFT_CS,
  TFT_DC,
  TFT_RST
);

void setup()
{
  Serial.begin(115200);

  // Turn ON TFT backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // Start SPI with the pins from your schematic
  SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);

  // Initialize display
  tft.begin();

  // Landscape orientation
  tft.setRotation(1);

  // Clear screen
  tft.fillScreen(ILI9341_BLACK);

  // -------------------------
  // Display HELLO WORLD
  // -------------------------

  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);

  tft.setCursor(45, 100);
  tft.println("HELLO");

  tft.setCursor(45, 140);
  tft.println("WORLD");

  Serial.println("TFT initialized!");
}

void loop()
{
}