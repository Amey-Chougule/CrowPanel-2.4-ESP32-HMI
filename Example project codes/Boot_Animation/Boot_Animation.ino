#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

// =====================================================
// TFT PIN CONFIGURATION
// =====================================================

#define TFT_CS    15
#define TFT_DC     2
#define TFT_RST   -1

#define TFT_SCLK  14
#define TFT_MOSI  13
#define TFT_MISO   4

#define TFT_BL    27

// =====================================================
// TOUCH PIN CONFIGURATION
// =====================================================

#define TOUCH_CS   33
#define TOUCH_IRQ  36

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
// SYSTEM INFORMATION
// =====================================================

const char* PRODUCT_NAME   = "HMI CONTROL UNIT"; // Change as per required //
const char* SOFTWARE_VER   = "SW VERSION 1.0.0"; // Change as per required //
const char* HARDWARE_VER   = "HW VERSION 1.0"; // Change as per required //
const char* BUILD_DATE     = "BUILD 2026.09"; // Change as per required //
const char* COMPANY_NAME   = "Amey Chougule"; // Change as per required //

// =====================================================
// COLORS
// =====================================================

#define BG_COLOR       ILI9341_BLACK
#define TEXT_COLOR     ILI9341_WHITE
#define ACCENT_COLOR   ILI9341_CYAN
#define SUCCESS_COLOR  ILI9341_GREEN
#define WARNING_COLOR  ILI9341_YELLOW
#define ERROR_COLOR    ILI9341_RED
#define BAR_BG         0x39E7

// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(115200);

  // ---------------------------------------------------
  // BACKLIGHT
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
  tft.fillScreen(BG_COLOR);

  // ---------------------------------------------------
  // TOUCH
  // ---------------------------------------------------

  touch.begin();
  touch.setRotation(1);

  // ---------------------------------------------------
  // START BOOT SEQUENCE
  // ---------------------------------------------------

  bootAnimation();

  // ---------------------------------------------------
  // MAIN SCREEN
  // ---------------------------------------------------

  mainScreen();
}

// =====================================================
// BOOT ANIMATION
// =====================================================

void bootAnimation()
{
  Serial.println();
  Serial.println("======================================");
  Serial.println("        SYSTEM BOOT SEQUENCE");
  Serial.println("======================================");

  // ---------------------------------------------------
  // BOOT LOGO
  // ---------------------------------------------------

  tft.fillScreen(BG_COLOR);

  // Small top line
  tft.drawFastHLine(
    20,
    20,
    280,
    ACCENT_COLOR
  );

  // Product name
  tft.setTextColor(ACCENT_COLOR);
  tft.setTextSize(2);

  centerText(
    PRODUCT_NAME,
    45,
    2
  );

  // SYSTEM BOOT
  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(3);

  centerText(
    "SYSTEM BOOT",
    85,
    3
  );

  // Loading dots
  tft.setTextColor(ACCENT_COLOR);
  tft.setTextSize(2);

  centerText(
    "...",
    125,
    2
  );

  // Version
  tft.setTextColor(ILI9341_LIGHTGREY);
  tft.setTextSize(1);

  centerText(
    SOFTWARE_VER,
    155,
    1
  );

  centerText(
    HARDWARE_VER,
    170,
    1
  );

  centerText(
    COMPANY_NAME,
    185,
    1
  );

  delay(1000);

  // ---------------------------------------------------
  // INITIALIZATION STEPS
  // ---------------------------------------------------

  bootStep(
    "Initializing hardware",
    10
  );

  bootStep(
    "Initializing display",
    25
  );

  bootStep(
    "Initializing touch",
    40
  );

  bootStep(
    "Initializing communication",
    55
  );

  bootStep(
    "Loading system configuration",
    70
  );

  bootStep(
    "Running diagnostics",
    85
  );

  bootStep(
    "Starting application",
    100
  );

  // ---------------------------------------------------
  // SYSTEM READY
  // ---------------------------------------------------

  tft.fillScreen(BG_COLOR);

  // Top line
  tft.drawFastHLine(
    20,
    25,
    280,
    SUCCESS_COLOR
  );

  // Check mark circle
  tft.drawCircle(
    160,
    80,
    25,
    SUCCESS_COLOR
  );

  // Check mark
  tft.drawLine(
    148,
    80,
    157,
    89,
    SUCCESS_COLOR
  );

  tft.drawLine(
    157,
    89,
    174,
    68,
    SUCCESS_COLOR
  );

  // SYSTEM READY
  tft.setTextColor(SUCCESS_COLOR);
  tft.setTextSize(3);

  centerText(
    "SYSTEM READY",
    120,
    3
  );

  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(1);

  centerText(
    "All systems operational",
    160,
    1
  );

  centerText(
    SOFTWARE_VER,
    180,
    1
  );

  centerText(
    BUILD_DATE,
    195,
    1
  );

  delay(1800);
}

// =====================================================
// BOOT STEP
// =====================================================

void bootStep(
  const char* message,
  int percentage
)
{
  Serial.print("[BOOT] ");
  Serial.print(message);
  Serial.print(" ... ");

  // ---------------------------------------------------
  // Clear status area
  // ---------------------------------------------------

  tft.fillRect(
    20,
    210,
    280,
    25,
    BG_COLOR
  );

  // Status text
  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(1);

  tft.setCursor(
    20,
    212
  );

  tft.print(message);

  // ---------------------------------------------------
  // Progress bar
  // ---------------------------------------------------

  int barX = 20;
  int barY = 195;
  int barW = 280;
  int barH = 8;

  // Background
  tft.drawRect(
    barX,
    barY,
    barW,
    barH,
    BAR_BG
  );

  // Progress
  int progressWidth =
    map(
      percentage,
      0,
      100,
      0,
      barW - 2
    );

  tft.fillRect(
    barX + 1,
    barY + 1,
    progressWidth,
    barH - 2,
    ACCENT_COLOR
  );

  // Percentage
  tft.fillRect(
    245,
    170,
    55,
    15,
    BG_COLOR
  );

  tft.setTextColor(ACCENT_COLOR);
  tft.setTextSize(1);

  tft.setCursor(
    250,
    173
  );

  tft.print(percentage);
  tft.print("%");

  // ---------------------------------------------------
  // Animated dots
  // ---------------------------------------------------

  for (int i = 0; i < 3; i++)
  {
    delay(120);

    tft.fillCircle(
      270 + i * 8,
      215,
      2,
      ACCENT_COLOR
    );
  }

  delay(250);

  Serial.println("OK");
}

// =====================================================
// MAIN SCREEN
// =====================================================

void mainScreen()
{
  tft.fillScreen(BG_COLOR);

  // ---------------------------------------------------
  // HEADER
  // ---------------------------------------------------

  tft.fillRect(
    0,
    0,
    320,
    40,
    0x18C3
  );

  tft.setTextColor(ACCENT_COLOR);
  tft.setTextSize(2);

  tft.setCursor(
    15,
    12
  );

  tft.println("HMI CONTROL");

  // Status indicator
  tft.fillCircle(
    295,
    20,
    6,
    SUCCESS_COLOR
  );

  // ---------------------------------------------------
  // SYSTEM STATUS
  // ---------------------------------------------------

  tft.setTextColor(SUCCESS_COLOR);
  tft.setTextSize(2);

  tft.setCursor(
    20,
    60
  );

  tft.println("SYSTEM ONLINE");

  // ---------------------------------------------------
  // INFORMATION
  // ---------------------------------------------------

  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(1);

  tft.setCursor(20, 100);
  tft.println("Software:");

  tft.setTextColor(ACCENT_COLOR);
  tft.setCursor(100, 100);
  tft.println(SOFTWARE_VER);

  tft.setTextColor(TEXT_COLOR);
  tft.setCursor(20, 120);
  tft.println("Hardware:");

  tft.setTextColor(ACCENT_COLOR);
  tft.setCursor(100, 120);
  tft.println(HARDWARE_VER);

  tft.setTextColor(TEXT_COLOR);
  tft.setCursor(20, 140);
  tft.println("Build:");

  tft.setTextColor(ACCENT_COLOR);
  tft.setCursor(100, 140);
  tft.println(BUILD_DATE);

  // ---------------------------------------------------
  // READY MESSAGE
  // ---------------------------------------------------

  tft.drawRoundRect(
    20,
    165,
    280,
    45,
    6,
    SUCCESS_COLOR
  );

  tft.setTextColor(SUCCESS_COLOR);
  tft.setTextSize(2);

  centerText(
    "READY",
    180,
    2
  );

  // Footer
  tft.setTextColor(ILI9341_DARKGREY);
  tft.setTextSize(1);

  centerText(
    "Touch screen to continue",
    225,
    1
  );
}

// =====================================================
// CENTER TEXT
// =====================================================

void centerText(
  const char* text,
  int y,
  int size
)
{
  tft.setTextSize(size);

  int16_t x1;
  int16_t y1;
  uint16_t w;
  uint16_t h;

  tft.getTextBounds(
    text,
    0,
    y,
    &x1,
    &y1,
    &w,
    &h
  );

  int x =
    (tft.width() - w) / 2;

  tft.setCursor(
    x,
    y
  );

  tft.println(text);
}

// =====================================================
// LOOP
// =====================================================

void loop()
{
  // Main application can be added here.

  delay(100);
}