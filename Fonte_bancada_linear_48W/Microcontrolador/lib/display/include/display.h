#ifndef DISPLAY_H
#define DISPLAY_H


#include "Arduino.h"
#include <measures.h>

class display

{
    public:
        display(/* args */);
        void refresh(Measures measures);
        void initialize();

};

#endif