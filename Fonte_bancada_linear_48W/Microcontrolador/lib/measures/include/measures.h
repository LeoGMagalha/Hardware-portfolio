#ifndef MEASURES_H
#define MEASURES_H

#include <Arduino.h>

class Measures
{
    public:
        Measures();
        float Voltag_pos_output;
        float Voltag_neg_output;
        float Current_output;
        bool Output_pos_on = false;
        bool Output_neg_on = false;
        bool Output_neg_on_read = false;
        bool Output_pos_on_read = false;
        void change_outputs();
        void update_measures();
        void update_acts();
        void initialize();
};

#endif