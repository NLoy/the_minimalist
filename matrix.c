#include "matrix.h"
#include "quantum.h"

//static const char cap_pins_colors[5][3]  = {"WHI",       "YEL",      "GRN",      "RED",      "BLU"};
static const uint32_t cap_pins_list[5]   = {LINE_PIN26,  LINE_PIN25, LINE_PIN24, LINE_PIN12, LINE_PIN11};
static const uint32_t cap_pins_values[5] = {0b100000000, 0b10000000, 0b1000000,  0b100000,   0b10000};

void matrix_init_custom(void) {
    for (int count = 0; count <5; ++count)
    {        
        int pin = cap_pins_list[count];
        setPinInputLow(pin); //Enable pin as input with builtin pull-down resister
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;
    for (int count = 0; count <5; ++count)
    {        
        int pin = cap_pins_list[count];
        bool reading = readPin(pin);
        if (reading == 1)
        {
            current_matrix[9] |= cap_pins_values[count];
        }
    }
    matrix_has_changed = true;
    return matrix_has_changed;
}
