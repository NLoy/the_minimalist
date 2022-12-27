#include "matrix.h"
#include "quantum.h"
#define IRQ_PIN LINE_PIN26
#define MY_I2C_ADDRESS (0x5A << 1)

    
    
void i2c_init(void) {
    setPinInput(LINE_PIN24);
    setPinInput(LINE_PIN25);
    wait_ms(10);
    
    palSetPadMode(GPIOB, 6, PAL_MODE_ALTERNATE(4)
    
    

}

i2c_status_t i2c_start(uint8_t address, uint16_t timeout)


void matrix_init_custom(void) {
    
    setPinInputHigh(IRQ_PIN); //Enable pin as input with builtin pull-up resister    
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;
    if(readPin(IRQ_PIN != 1){
        
    }
    
    // TODO: add matrix scanning routine here
    return matrix_has_changed;
}
