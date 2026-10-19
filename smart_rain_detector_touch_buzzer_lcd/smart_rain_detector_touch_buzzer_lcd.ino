#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (Address 0x27 is common, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int rainSensorPin = 2;
const int touchSensorPin = 3;
const int buzzerPin = 4;

// Variables to keep track of the system state
bool alarmActive = false;

void setup() {
  // Initialize Serial Monitor (optional, for debugging)
  Serial.begin(9600);

  // Initialize Pins
  pinMode(rainSensorPin, INPUT);
  pinMode(touchSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Welcome screen on startup
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensor values (LOW usually means rain detected on digital rain sensors)
  int rainDetected = digitalRead(rainSensorPin);
  int touchDetected = digitalRead(touchSensorPin);

  // Check if rain is detected (Adjust to HIGH if your sensor outputs HIGH when wet)
  if (rainDetected == LOW && !alarmActive) {
    alarmActive = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rain is falling");
  }

  // If the alarm is triggered, keep the buzzer sounding
  if (alarmActive) {
    digitalWrite(buzzerPin, HIGH); 
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Check if the touch sensor is pressed to turn off the alarm
  if (touchDetected == HIGH && alarmActive) {
    alarmActive = false;         // Reset the alarm state
    digitalWrite(buzzerPin, LOW); // Turn off buzzer immediately
    
    // Display "You're welcome"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You're welcome");
    
    delay(3000); // Keep message on screen for 3 seconds
    lcd.clear();
  }
}