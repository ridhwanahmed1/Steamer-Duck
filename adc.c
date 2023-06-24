#include "adc.h"
#include "utils.h"
#include "board.h"
#include <stdio.h>

void setupSerial() {
    // Code to initialize serial communication, configure baud rate, etc.
    // Refer to your specific microcontroller or library documentation for details.
}

int main(void) {
    LED_Initialize();
    setupADC();
    setupSerial();

    while (1) {
        int valx = getFirstADCValue();
        int valy = getSecondADCValue();

//        printf("valx: %d, valy: %d\n", valx, valy);

        if (valx >=190 && valy ==0) { // Condition for right movement
        	LEDRed_On();
        }
        else if (valx >=190 && valy==255) { // Condition for left movement
        	LEDGreen_On();
        }
        else if(valx==0 && valy >= 180){
        	LEDGreen_On();
        	LEDRed_On();
        }

        else {
            LED_Off();
        }

    }
}
