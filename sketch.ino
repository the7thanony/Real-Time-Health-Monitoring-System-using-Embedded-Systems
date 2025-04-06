#include <LiquidCrystal_I2C.h>

#define LED 2
#define buzzer 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pulse = 80;  // Starting pulse
int temp = 370;  // 37.0°C

bool dangerMode = false;
int dangerTimer = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  lcd.init();
  lcd.backlight();

  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(LED, LOW);

  randomSeed(analogRead(0));
}

void check(int pulse, int temp) {
  if (pulse >= 100 || temp >= 380) {
    digitalWrite(LED, HIGH);
    tone(buzzer, 1030);  // buzzer ON
  } else {
    digitalWrite(LED, LOW);
    noTone(buzzer);      // buzzer OFF
  }
}

void loop() {
  // Random chance to trigger danger mode
  if (!dangerMode && random(0, 100) < 5) {  // 5% chance per loop
    dangerMode = true;
    dangerTimer = random(3, 6);  // Stay in danger mode for 3–5 loops
    Serial.println("🚨 Entering Danger Mode");
  }

  // Update pulse and temp based on mode
  if (dangerMode) {
    pulse = random(100, 131);  // Dangerous pulse
    temp = random(380, 396);   // Dangerous temp (38.0–39.5)
    dangerTimer--;
    if (dangerTimer <= 0) {
      dangerMode = false;
      Serial.println("✅ Exiting Danger Mode");
    }
  } else {
    pulse += random(-3, 4);
    temp += random(-1, 2);
    pulse = constrain(pulse, 60, 99);
    temp = constrain(temp, 360, 379);
  }

  // Display
  lcd.setCursor(0, 0);
  lcd.print("Pulse: ");
  lcd.print(pulse);
  lcd.print(" bpm");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp / 10.0);
  lcd.print((char)223);
  lcd.print("C");

  Serial.print("Pulse: ");
  Serial.print(pulse);
  Serial.print(" bpm, Temp: ");
  Serial.print(temp / 10.0);
  Serial.println(" C");

  check(pulse, temp);

  delay(1000);
  lcd.clear();
}
