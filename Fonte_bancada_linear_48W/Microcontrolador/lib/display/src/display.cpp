#include <display.h>
#include "../../../include/defines.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(
    RESET_PIN_DISPLAY,
    ENABLE_PIN_DISPLAY,
    D4_PIN_DISPLAY,
    D5_PIN_DISPLAY,
    D6_PIN_DISPLAY,
    D7_PIN_DISPLAY);

display::display(/* args */)
{
}

void display::refresh(Measures measures)
{
    Serial.println("[display][refresh] INFO - Atualizando display");
    lcd.setCursor(0, 0);
    lcd.print("V+:" + String(measures.Voltag_pos_output) + 
              " V-:" + String(measures.Voltag_neg_output) + "V");
    lcd.setCursor(0, 1);
    lcd.print("I:" + String(measures.Current_output) + "A");
}

void display::initialize()
{
    Serial.println("[display][refresh] INFO - Inicializando display");
    lcd.begin(LCD_COLS, LCD_LINES);
}