#include <Arduino.h>
#include <unity.h>
#include <measures.h>
#include <display.h>
#include "../../../include/defines.h"
Measures medidas;
display LCD;

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_Measures_initialize_pin_number(void)
{
    TEST_ASSERT_EQUAL(A7, V_POS_AD);
    TEST_ASSERT_EQUAL(A0, V_NEG_AD);
    TEST_ASSERT_EQUAL(A2, CURR_AD);
    TEST_ASSERT_EQUAL(6, V_POS_OUT_STATE_PIN);
    TEST_ASSERT_EQUAL(10, V_NEG_OUT_STATE_PIN);
    TEST_ASSERT_EQUAL(7, V_POS_ACT_PIN);
    TEST_ASSERT_EQUAL(8, V_NEG_ACT_PIN);
}
void test_Measures_initialize_output_states(void)
{
    TEST_ASSERT_EQUAL(LOW, digitalRead(V_POS_ACT_PIN));
    TEST_ASSERT_EQUAL(LOW, digitalRead(V_NEG_ACT_PIN));
}
void test_Measures_change_state_acts_on(void)
{
    TEST_ASSERT_EQUAL(HIGH, digitalRead(V_POS_ACT_PIN));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(V_NEG_ACT_PIN));
}
    
void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);
  Serial.begin(9600);
  medidas.initialize();
  LCD.initialize();
}


void loop()
{
    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_Measures_initialize_pin_number);
    RUN_TEST(test_Measures_initialize_output_states);
    medidas.Output_neg_on_read = true;
    medidas.Output_pos_on_read = true;
    medidas.change_outputs();
    RUN_TEST(test_Measures_change_state_acts_on);
    UNITY_END(); // stop unit testing
}