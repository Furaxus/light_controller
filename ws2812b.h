/* 
 * Library for the two command of a ws2812* ribbon
 * 
 * WARNING the different time constant may be different depending on the ws2812 ribbon type
 * 
 */


#ifndef __WS2812B_H__
#define __WS2812B_H__


//define time constant (in ns) (from datasheet)
#define MAX_TIME            900     //time for out value we need
#define MIN_TIME            350     //time for complete the cycle
#define RESET_TIME          10000   //minimal time for reset

/* Sending '1'
 * 
 * <-- MAX_TIME --> <-- MIN_TIME -->
 * ________________
 *                 |________________
 * 
 * 
 * Sending '0'
 * 
 * <-- MIN_TIME --> <-- MAX_TIME -->
 * ________________
 *                 |________________
 * 
 */


/* Write a 24 bits sequence representing the GRB colors for one led
 * Sequence : GGGG GGGG RRRR RRRR BBBB BBBB
 */
void write_grb(uint8_t green, uint8_t red, uint8_t blue, uint8_t pin);


/* Send a reset signal */
void reset(uint8_t pin);


#endif
