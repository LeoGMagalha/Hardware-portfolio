#include <measures.h>
#include <Arduino.h>
#include "../../../include/defines.h"

Measures::Measures(/* args */)
{
}

void Measures::initialize()
{
    Serial.println("[measures][initialize] Iniciando Pinos");
    pinMode(V_POS_AD, INPUT);
    pinMode(V_NEG_AD, INPUT);
    pinMode(CURR_AD, INPUT);
    pinMode(V_POS_OUT_STATE_PIN, INPUT);
    pinMode(V_NEG_OUT_STATE_PIN, INPUT);
    pinMode(V_POS_ACT_PIN, OUTPUT);
    pinMode(V_NEG_ACT_PIN, OUTPUT);
    digitalWrite(V_POS_ACT_PIN, Measures::Output_pos_on);
    digitalWrite(V_NEG_ACT_PIN, Measures::Output_neg_on);
}

void Measures::change_outputs()
{
    if (Measures::Output_pos_on_read != Measures::Output_pos_on)
    {
        Measures::Output_pos_on = Measures::Output_pos_on_read;
        digitalWrite(V_POS_ACT_PIN, Measures::Output_pos_on);
        Serial.println("[measures][change_outputs] INFO - Estado Ouput positivo:" + String(Measures::Output_pos_on));
    }
    if (Measures::Output_neg_on_read != Measures::Output_neg_on)
    {
        Measures::Output_neg_on = Measures::Output_neg_on_read;
        digitalWrite(V_NEG_ACT_PIN, Measures::Output_neg_on);
        Serial.println("[measures][change_outputs] INFO - Estado Ouput negativo:" + String(Measures::Output_neg_on));
    }
}

void Measures::update_acts()
{
    Measures::Output_pos_on_read = digitalRead(V_POS_OUT_STATE_PIN);
    Measures::Output_neg_on_read = digitalRead(V_NEG_OUT_STATE_PIN);
    Serial.println("[measures][update_acts] INFO: ");
    Serial.println("V+ON: " + String(Measures::Output_pos_on));
    Serial.println("V-ON: " + String(Measures::Output_neg_on));
    Measures::change_outputs();

}

void Measures::update_measures()
{
    Measures::Voltag_pos_output = ((analogRead(V_POS_AD) * 5.00 / 1023)/0.203) - 0.0179;
    Measures::Voltag_neg_output = ((analogRead(V_NEG_AD) * 5.00 / 1023)/0.2094);
    if (Measures::Output_pos_on == true)
    {
        Measures::Current_output = (((analogRead(CURR_AD) * 5.00 / 1023)-0.015)/(14.468*2))/(0.12639*0.68);
    }
    else
    {
        Measures::Current_output = 0.00;
    }
    
    Serial.println("[measures][update_measures] INFO: ");
    Serial.println("V+: " + String(Measures::Voltag_pos_output) + "(V)");
    Serial.println("V-: " + String(Measures::Voltag_neg_output) + "(V)");
    Serial.println("I: " + String(Measures::Current_output)+ "(A)");

}