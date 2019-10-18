#include "ws2812b.h"
#include <linux/gpio.h>
#include <linux/delay.h>
#include <pthread.h>




/* Write the 'HIGH' bit sequence on the given pin */
void _write_high(uint8_t pin){
    gpio_set_value(pin, HIGH);
    udelay(MAX_TIME/1000);
    gpio_set_value(pin, LOW);
    udelay(MIN_TIME/1000);
}


/* Write the 'LOW' bit sequence on the given pin */
void _write_low(uint8_t pin){
    gpio_set_value(pin, HIGH);
    udelay(MIN_TIME/1000);
    gpio_set_value(pin, LOW);
    udelay(MAX_TIME/1000);
}


/* Write one byte one the ribbon */
void _write_byte(uint8_t byte, uint8_t pin){
    uint8_t i;
    //send the 8 bits of the "byte"
    for(i = 0; i<8; i++){
        if (byte & 0x80)    //if it's a '1'
            _write_high(pin);
        else                //if it's a '0'
            _write_low(pin);
    }
}


void write_grb(uint8_t green, uint8_t red, uint8_t blue, uint8_t pin){
    //Write each byte
    _write_byte(green, pin);
    _write_byte(red, pin);
    _write_byte(blue, pin);
}


void reset(uint8_t pin){
    gpio_set_value(pin, LOW);
    udelay(RESET_TIME/1000);
}

