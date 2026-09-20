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
// DISPLAY OBJECTS
// =====================================================

Adafruit_ILI9341 tft(
  TFT_CS,
  TFT_DC,
  TFT_RST
);

XPT2046_Touchscreen touch(
  TOUCH_CS,
  TOUCH_IRQ
);

// =====================================================
// BUTTON STRUCTURE
// =====================================================

struct Button
{
  int x;
  int y;
  int width;
  int height;

  const char* name;

  bool state;
};

// =====================================================
// BUTTON DEFINITIONS
// =====================================================

Button buttons[4] =
{
  { 20,  70, 130, 60, "BUTTON 1", false },
  { 170, 70, 130, 60, "BUTTON 2", false },

  { 20,  150, 130, 60, "BUTTON 3", false },
  { 170,150, 130, 60, "BUTTON 4", false }
};

// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(115200);

  delay(500);

  Serial.println();
  Serial.println("================================");
  Serial.println(" ESP32 2.4 INCH HMI BUTTON TEST");
  Serial.println("================================");

  // ---------------------------------------------------
  // Backlight
  // ---------------------------------------------------

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // ---------------------------------------------------
  // SPI
  // ---------------------------------------------------

  SPI.begin(
    TFT_SCLK,
    TFT_MISO,
    TFT_MOSI,
    TFT_CS
  );

  // ---------------------------------------------------
  // TFT
  // ---------------------------------------------------

  tft.begin();

  tft.setRotation(1);

  tft.fillScreen(ILI9341_BLACK);

  // ---------------------------------------------------
  // TOUCH
  // ---------------------------------------------------

  touch.begin();

  touch.setRotation(2);

  // ---------------------------------------------------
  // DRAW SCREEN
  // ---------------------------------------------------

  drawInterface();

  Serial.println("System ready.");
}

// =====================================================
// DRAW COMPLETE INTERFACE
// =====================================================

void drawInterface()
{
  tft.fillScreen(ILI9341_BLACK);

  // Title
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);

  tft.setCursor(80, 20);
  tft.println("HMI CONTROL");

  // Draw buttons
  for (int i = 0; i < 4; i++)
  {
    drawButton(i);
  }
}

// =====================================================
// DRAW INDIVIDUAL BUTTON
// =====================================================

void drawButton(int index)
{
  Button &b = buttons[index];

  uint16_t buttonColor;

  if (b.state)
  {
    // ON
    buttonColor = ILI9341_GREEN;
  }
  else
  {
    // OFF
    buttonColor = ILI9341_RED;
  }

  // Button background
  tft.fillRoundRect(
    b.x,
    b.y,
    b.width,
    b.height,
    8,
    buttonColor
  );

  // Border
  tft.drawRoundRect(
    b.x,
    b.y,
    b.width,
    b.height,
    8,
    ILI9341_WHITE
  );

  // Text
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);

  // Center text approximately
  int textX = b.x + 20;
  int textY = b.y + 22;

  tft.setCursor(textX, textY);
  tft.println(b.name);
}

// =====================================================
// TOUCH COORDINATE CONVERSION
// =====================================================

void getTouchCoordinates(int &x, int &y)
{
  TS_Point p = touch.getPoint();

  // ---------------------------------------------------
  // X = INVERTED
  // ---------------------------------------------------

  x = map(
    p.x,
    TS_MIN_X,
    TS_MAX_X,
    tft.width() - 1,
    0
  );

  // ---------------------------------------------------
  // Y = NORMAL
  // ---------------------------------------------------

  y = map(
    p.y,
    TS_MIN_Y,
    TS_MAX_Y,
    0,
    tft.height() - 1
  );

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

  // Serial debug
  Serial.print("Touch X = ");
  Serial.print(x);

  Serial.print("  Y = ");
  Serial.println(y);
}

// =====================================================
// CHECK WHICH BUTTON WAS PRESSED
// =====================================================

void checkButtonPress(int x, int y)
{
  for (int i = 0; i < 4; i++)
  {
    Button &b = buttons[i];

    if (
      x >= b.x &&
      x <= b.x + b.width &&
      y >= b.y &&
      y <= b.y + b.height
    )
    {
      // Toggle state
      b.state = !b.state;

      // Redraw button
      drawButton(i);

      // Serial output
      Serial.print(b.name);

      if (b.state)
      {
        Serial.println(" -> ON");
      }
      else
      {
        Serial.println(" -> OFF");
      }

      Serial.println("--------------------");

      // Small delay to prevent multiple triggers
      delay(250);

      return;
    }
  }
}

// =====================================================
// LOOP
// =====================================================

void loop()
{
  if (touch.touched())
  {
    int x;
    int y;

    getTouchCoordinates(x, y);

    checkButtonPress(x, y);

    // Wait until finger is released
    while (touch.touched())
    {
      delay(10);
    }
  }
}