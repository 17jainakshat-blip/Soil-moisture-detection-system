#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensor pins
#define SOIL_PIN A0
#define RAIN_PIN A1
#define LIGHT_PIN A2
#define WATER_PIN A3

// Button pins
#define BTN_NEXT 2
#define BTN_PREV 3

// Buzzer pin
#define BUZZER_PIN 4

// Relay pin
#define RELAY_PIN 8

// Calibration values
const int SOIL_DRY = 800;
const int SOIL_WET = 350;

const int RAIN_THRESHOLD = 500;
const int WATER_MINIMUM = 300;

// Relay settings
const bool RELAY_ACTIVE_LOW = true;

// Screen timing
const unsigned long SCREEN_INTERVAL = 4000;

// Crop group structure
struct CropGroup {
  const char* name;
  const char* crops;
  int pumpOnBelow;
  int pumpOffAbove;
};

// Crop groups
CropGroup crops[] = {
  {"LOW WATER", "Chickpea-Lentil", 25, 40},
  {"LOW-MODER", "Wheat-Tomato", 30, 45},
  {"MODERATE", "Maize-Soybean", 35, 50},
  {"HIGH WATER", "Pigeonpea-Rice", 40, 55},
  {"VERY HIGH", "Sugarcane-Banana", 45, 60}
};

const int totalCrops = 5;

// Variables
int cropIndex = 0;
int screenIndex = 0;

int soilRaw, rainRaw, lightRaw, waterRaw;
int moisture;

bool pumpState = false;
bool rainDetected = false;
bool waterAvailable = false;

unsigned long lastScreenChange = 0;

// Button debounce variables
unsigned long lastNextPress = 0;
unsigned long lastPrevPress = 0;

const unsigned long debounceDelay = 200;

// ---------------- BUZZER ----------------

void beep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
}

// ---------------- PUMP CONTROL ----------------

void setPump(bool state) {
  pumpState = state;

  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, state ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, state ? HIGH : LOW);
  }
}

// ---------------- SENSOR READING ----------------

void readSensors() {

  soilRaw = analogRead(SOIL_PIN);
  rainRaw = analogRead(RAIN_PIN);
  lightRaw = analogRead(LIGHT_PIN);
  waterRaw = analogRead(WATER_PIN);

  moisture = map(soilRaw, SOIL_DRY, SOIL_WET, 0, 100);
  moisture = constrain(moisture, 0, 100);

  rainDetected = (rainRaw < RAIN_THRESHOLD);

  waterAvailable = (waterRaw >= WATER_MINIMUM);
}

// ---------------- AUTOMATIC PUMP CONTROL ----------------

void controlPump() {

  if (!waterAvailable || rainDetected) {
    setPump(false);
    return;
  }

  if (moisture < crops[cropIndex].pumpOnBelow) {
    setPump(true);
  }

  else if (moisture >= crops[cropIndex].pumpOffAbove) {
    setPump(false);
  }
}

// ---------------- LCD SCREENS ----------------

void updateLCD() {

  lcd.clear();

  switch (screenIndex) {

    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Crop Group:");
      lcd.setCursor(0, 1);
      lcd.print(crops[cropIndex].name);
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Soil:");
      lcd.print(moisture);
      lcd.print("%");

      lcd.setCursor(0, 1);
      lcd.print("Pump:");
      lcd.print(pumpState ? "ON" : "OFF");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Rain:");
      lcd.print(rainDetected ? "YES" : "NO");

      lcd.setCursor(0, 1);
      lcd.print("Light:");
      lcd.print(lightRaw);
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Water:");
      lcd.print(waterRaw);

      lcd.setCursor(0, 1);
      if (waterAvailable) {
        lcd.print("TANK AVAILABLE");
      } else {
        lcd.print("TANK LOW! PUMP OFF");
      }
      break;
  }
}

// ---------------- BUTTON CHECKING ----------------

void checkButtons() {

  unsigned long currentTime = millis();

  // NEXT button
  if (digitalRead(BTN_NEXT) == LOW &&
      currentTime - lastNextPress >= debounceDelay) {

    lastNextPress = currentTime;

    cropIndex++;
    if (cropIndex >= totalCrops) {
      cropIndex = 0;
    }

    beep();

    screenIndex = 0;
    lastScreenChange = millis();
    updateLCD();

    Serial.print("Selected crop: ");
    Serial.println(crops[cropIndex].name);
  }

  // PREVIOUS button
  if (digitalRead(BTN_PREV) == LOW &&
      currentTime - lastPrevPress >= debounceDelay) {

    lastPrevPress = currentTime;

    cropIndex--;
    if (cropIndex < 0) {
      cropIndex = totalCrops - 1;
    }

    beep();

    screenIndex = 0;
    lastScreenChange = millis();
    updateLCD();

    Serial.print("Selected crop: ");
    Serial.println(crops[cropIndex].name);
  }
}

// ---------------- SETUP ----------------

void setup() {

  Serial.begin(9600);

  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_PREV, INPUT_PULLUP);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  pinMode(RELAY_PIN, OUTPUT);

  // Keep pump OFF at startup
  setPump(false);

  Wire.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("SMART IRRIGATION");

  lcd.setCursor(0, 1);
  lcd.print("System Starting");

  delay(2000);

  readSensors();
  updateLCD();

  lastScreenChange = millis();

  Serial.println("Smart Irrigation Started");
}

// ---------------- MAIN LOOP ----------------

void loop() {

  readSensors();

  checkButtons();

  controlPump();

  // Change LCD screen every 4 seconds
  if (millis() - lastScreenChange >= SCREEN_INTERVAL) {

    screenIndex++;

    if (screenIndex >= 4) {
      screenIndex = 0;
    }

    lastScreenChange = millis();
    updateLCD();
  }

  // Serial monitor readings
  static unsigned long lastSerial = 0;

  if (millis() - lastSerial >= 1000) {

    lastSerial = millis();

    Serial.print("Soil: ");
    Serial.print(moisture);
    Serial.print("% | Rain: ");
    Serial.print(rainRaw);
    Serial.print(" | Light: ");
    Serial.print(lightRaw);
    Serial.print(" | Water: ");
    Serial.print(waterRaw);
    Serial.print(" | Pump: ");
    Serial.println(pumpState ? "ON" : "OFF");
  }
}
