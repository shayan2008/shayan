#include "IRSENSOR.h"

void IRSENSOR() {
  int s_value_analog[8];
  int s_value_digital[8];
  int HT = 900;
  int LT = 300;
  for (int i = 0; i < 8; i++) {
    digitalWrite(2, i % 2);
    digitalWrite(3, int(i / 2) % 2);
    digitalWrite(4, int(i / 4));
    s_value_analog[i] = analogRead(A0);
  }
  for (int i = 0; i < 8; i++) {
    int T = (HT + LT) / 2;
    if (s_value_analog[i] > T) {
      s_value_digital[i] = 1;
    }
    else {
      s_value_digital[i] = 0;
    }
  }
  for (int i = 0; i < 8 ; i++) {
    Serial.print(s_value_analog[i]);
    Serial.print("|");
    Serial.print(s_value_digital[i]);
    Serial.print("\t");
  }
  Serial.println();
}
