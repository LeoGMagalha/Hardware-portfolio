#include <defines.h>
#include <Arduino.h>
#include <display.h>
#include <measures.h>


Measures medidas;
display LCD;
unsigned long currentMillis;
unsigned long prev_millis = millis();
void setup()
{
  Serial.begin(9600);
  medidas.initialize();
  LCD.initialize();
}

void loop()
{
  currentMillis = millis();
  if (currentMillis - prev_millis >= 700)
  {
    prev_millis = millis();
    medidas.update_measures();
    LCD.refresh(medidas);
  }
  medidas.update_acts();
  delay(200);
}