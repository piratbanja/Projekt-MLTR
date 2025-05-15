#include <Arduino.h>

// Definicija pinov za RGB LED (skupna katoda)
const int LED_R = 7;    // Rdeča
const int LED_G = 10;   // Zelena
const int LED_B = 4;    // Modra

// Definicija pina za gumb
const int BTN = 9;

// Trenutna barva LED
int currentColor = 0;   // 0 = rdeča, 1 = zelena, 2 = modra


void setup() {
  // Nastavimo pine za LED kot izhodne
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // Nastavimo gumb kot vhod z notranjim pull-up uporom
  pinMode(BTN, INPUT_PULLUP);

  // Nastavimo začetno barvo LED
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}

void loop() {
  int btnState = digitalRead(BTN);    // Preberemo stanje gumba

  if (btnState == LOW) {    // Gumb je pritisnjen
    currentColor = (currentColor + 1) % 3;    // Spremenimo barvo

    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);

    if (currentColor == 0) {
      digitalWrite(LED_R, HIGH);    // Rdeča
    } else if (currentColor == 1) {
      digitalWrite(LED_G, HIGH);    // Zelena
    } else if (currentColor == 2) {
      digitalWrite(LED_B, HIGH);    // Modra
    }

    delay(200); // Debounce delay
  }
}
