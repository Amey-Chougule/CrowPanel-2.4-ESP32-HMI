#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

// =====================================================
// TFT PINS
// =====================================================

#define TFT_CS    15
#define TFT_DC     2
#define TFT_RST   -1

#define TFT_SCLK  14
#define TFT_MOSI  13
#define TFT_MISO   4

#define TFT_BL    27

// =====================================================
// TOUCH PINS
// =====================================================

#define TOUCH_CS   33
#define TOUCH_IRQ  36

// =====================================================
// TOUCH CALIBRATION
// =====================================================

#define TS_MIN_X   200
#define TS_MAX_X  3900

#define TS_MIN_Y   200
#define TS_MAX_Y  3900

// =====================================================
// OBJECTS
// =====================================================

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(115200);

  // Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // SPI
  SPI.begin(
    TFT_SCLK,
    TFT_MISO,
    TFT_MOSI,
    TFT_CS
  );

  // TFT
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  // Touch
  touch.begin();
  touch.setRotation(1);

  // Header
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);

  tft.setCursor(80, 20);
  tft.println("TOUCH TEST");

  tft.setTextSize(1);

  tft.setCursor(75, 50);
  tft.println("X inverted / Y normal");

  tft.drawRect(
    0,
    0,
    tft.width(),
    tft.height(),
    ILI9341_BLUE
  );

  Serial.println("Touch test started...");
}

// =====================================================
// LOOP
// =====================================================

void loop()
{
  if (touch.touched())
  {
    TS_Point p = touch.getPoint();

    // =================================================
    // X AXIS INVERTED
    // =================================================

    int x = map(
      p.x,
      TS_MIN_X,
      TS_MAX_X,
      tft.width() - 1,
      0
    );

    // =================================================
    // Y AXIS NORMAL
    // =================================================

    int y = map(
      p.y,
      TS_MIN_Y,
      TS_MAX_Y,
      0,
      tft.height() - 1
    );

    // Limit values
    x = constrain(
      x,
      0,
      tft.width() - 1
    );

    y = constrain(
      y,
      0,
      tft.height() - 1
    );

    // Serial output
    Serial.print("RAW X: ");
    Serial.print(p.x);

    Serial.print("  RAW Y: ");
    Serial.print(p.y);

    Serial.print("  -> SCREEN X: ");
    Serial.print(x);

    Serial.print("  Y: ");
    Serial.println(y);

    // Clear touch area
    tft.fillRect(
      0,
      70,
      tft.width(),
      tft.height() - 70,
      ILI9341_BLACK
    );

    // Draw touch point
    tft.fillCircle(
      x,
      y,
      7,
      ILI9341_RED
    );

    // Draw crosshair
    tft.drawLine(
      x - 15,
      y,
      x + 15,
      y,
      ILI9341_YELLOW
    );

    tft.drawLine(
      x,
      y - 15,
      x,
      y + 15,
      ILI9341_YELLOW
    );

    // Display coordinates
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.setCursor(15, 80);
    tft.print("X: ");
    tft.println(x);

    tft.setCursor(15, 110);
    tft.print("Y: ");
    tft.println(y);

    delay(50);
  }
}