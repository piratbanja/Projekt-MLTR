#include <Arduino.h>


#define LED_R 7
#define LED_G 10
#define LED_B 4

#define BTN 9

#define LX_A 1
#define LX_B 3
#define LX_OUT 0


// Konfiguracija PWM
const int led_R_channel = 0;
const int led_G_channel = 1;
const int led_B_channel = 2;
const int pwm_frequency = 5000;   // Hz
const int pwm_resolution = 12;    // bit (0–4095)

int brightness = 0;
int fadeAmount = 20;

unsigned long lastSensorRead = 0;
int delayTime = 20;
int currentColor = 0;

int lastBtnState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  pinMode(BTN, INPUT_PULLUP);

  ledcSetup(led_R_channel, pwm_frequency, pwm_resolution);
  ledcAttachPin(LED_R, led_R_channel);

  ledcSetup(led_G_channel, pwm_frequency, pwm_resolution);
  ledcAttachPin(LED_G, led_G_channel);

  ledcSetup(led_B_channel, pwm_frequency, pwm_resolution);
  ledcAttachPin(LED_B, led_B_channel);

  pinMode(LX_A, INPUT);
  pinMode(LX_B, INPUT);
  pinMode(LX_OUT, INPUT);

  Serial.begin(9600);
  delay(500);

  digitalWrite(LED_R, HIGH);
  delay(100);
}

void loop() {
  // Debounce gumba za menjavo barve
  int btnState = digitalRead(BTN);
  if (btnState != lastBtnState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (btnState == LOW && lastBtnState == HIGH) {
      currentColor = (currentColor + 1) % 3;
    }
  }
  lastBtnState = btnState;

  // Dihanje jakosti
  brightness += fadeAmount;
  if (brightness >= 4095 || brightness <= 0) {
    fadeAmount = -fadeAmount;
  }

  // Nastavi trenutno barvo
  switch (currentColor) {
    case 0:
      rgb(brightness, 0, 0); break;
    case 1:
      rgb(0, brightness, 0); break;
    case 2:
      rgb(0, 0, brightness); break;
  }

  // Branje senzorja svetlosti in prilagoditev hitrosti
  if (millis() - lastSensorRead > 300) {
    int light = lx(1);
    delayTime = map(constrain(light, 200, 3000), 200, 3000, 60, 5);
    lastSensorRead = millis();
    Serial.print("LX = ");
    Serial.println(light);
  }

  delay(delayTime);
}

// Nastavi barvo preko PWM
void rgb(int R, int G, int B) {
  ledcWrite(led_R_channel, R);
  ledcWrite(led_G_channel, G);
  ledcWrite(led_B_channel, B);
}

// Funkcija za branje svetlobnega senzorja
int lx(int mode) {
  switch (mode) {
    case 0:
      pinMode(LX_A, INPUT);
      pinMode(LX_B, INPUT);
      break;
    case 1:
      pinMode(LX_A, INPUT);
      pinMode(LX_B, OUTPUT);
      digitalWrite(LX_B, LOW);
      break;
    case 2:
      pinMode(LX_A, OUTPUT);
      digitalWrite(LX_A, LOW);
      pinMode(LX_B, INPUT);
      break;
    default:
      pinMode(LX_A, INPUT);
      pinMode(LX_B, INPUT);
  }
  return analogRead(LX_OUT);
}
