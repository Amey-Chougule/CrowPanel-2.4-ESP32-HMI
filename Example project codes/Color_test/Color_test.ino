#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// ===============================
// TFT PIN CONFIGURATION
// ===============================

#define TFT_CS    15
#define TFT_DC     2
#define TFT_RST   -1       // Connected to ESP32 EN/RESET
#define TFT_SCLK  14
#define TFT_MOSI  13

#define TFT_BL    27       // Backlight

// ===============================
// TFT OBJECT
// ===============================

Adafruit_ILI9341 tft(
  TFT_CS,
  TFT_DC,
  TFT_RST
);

// ===============================
// SETUP
// ===============================

void setup()
{
  Serial.begin(115200);

  // Backlight ON
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // SPI pins
  SPI.begin(
    TFT_SCLK,   // SCLK
    -1,         // MISO not used
    TFT_MOSI,   // MOSI
    TFT_CS
  );

  // Initialize TFT
  tft.begin();

  // Landscape
  tft.setRotation(1);

  Serial.println("TFT Color Test Started");
}

// ===============================
// DISPLAY COLOR
// ===============================

void showColor(uint16_t color, const char *name)
{
  tft.fillScreen(color);

  delay(1000);

  // Text in opposite color
  if (color == ILI9341_WHITE ||
      color == ILI9341_YELLOW ||
      color == ILI9341_CYAN)
  {
    tft.setTextColor(ILI9341_BLACK);
  }
  else
  {
    tft.setTextColor(ILI9341_WHITE);
  }

  tft.setTextSize(3);

  // Center-ish position
  tft.setCursor(95, 105);
  tft.println(name);

  delay(1500);
}

// ===============================
// MAIN LOOP
// ===============================

void loop()
{
  // -------------------------------
  // Basic colors
  // -------------------------------

  showColor(ILI9341_BLACK, "BLACK");

  showColor(ILI9341_WHITE, "WHITE");

  showColor(ILI9341_RED, "RED");

  showColor(ILI9341_GREEN, "GREEN");

  showColor(ILI9341_BLUE, "BLUE");

  // -------------------------------
  // Secondary colors
  // -------------------------------

  showColor(ILI9341_YELLOW, "YELLOW");

  showColor(ILI9341_CYAN, "CYAN");

  showColor(ILI9341_MAGENTA, "MAGENTA");

  // -------------------------------
  // Additional colors
  // -------------------------------

  showColor(0xF800, "RED");

  showColor(0x07E0, "GREEN");

  showColor(0x001F, "BLUE");

  showColor(0xFFE0, "YELLOW");

  showColor(0x07FF, "CYAN");

  showColor(0xF81F, "MAGENTA");

  // -------------------------------
  // Gray
  // -------------------------------

  showColor(0x8410, "GRAY");

  // -------------------------------
  // Color bars
  // -------------------------------

  colorBars();

  delay(2000);
}

// ===============================
// COLOR BAR TEST
// ===============================

void colorBars()
{
  int w = tft.width();
  int h = tft.height();

  int barWidth = w / 8;

  uint16_t colors[] =
  {
    ILI9341_RED,
    ILI9341_GREEN,
    ILI9341_BLUE,
    ILI9341_YELLOW,
    ILI9341_CYAN,
    ILI9341_MAGENTA,
    ILI9341_WHITE,
    ILI9341_BLACK
  };

  for (int i = 0; i < 8; i++)
  {
    tft.fillRect(
      i * barWidth,
      0,
      barWidth,
      h,
      colors[i]
    );
  }

  delay(3000);
}