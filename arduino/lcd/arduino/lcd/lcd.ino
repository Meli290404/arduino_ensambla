#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String input = "";
bool messageReady = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Esperando...");
}

void loop() {

  // Leer texto completo
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\n') {
      messageReady = true;
      break;
    } else {
      input += c;
    }
  }

  // Mostrar el mensaje en LCD
  if (messageReady) {
    lcd.clear();

    if (input.length() <= 16) {
      lcd.setCursor(0, 0);
      lcd.print(input);
    }
    else {
      lcd.setCursor(0, 0);
      lcd.print(input.substring(0, 16));
      lcd.setCursor(0, 1);
      lcd.print(input.substring(16, 32));
    }

    input = "";
    messageReady = false;
  }
}
