/*
 * Controller for light ribon
 */

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <stdint.h>
#include <pthread.h>

#define NB_LED                  50      // number of led in the ribbon
#define RANDOM_ITERATION        10      // number of iteration of each selected random mode

/* ========== RIBBON MODE ========== */
#define RANDOM      0
#define FLASH       1       // set one color
#define STROBE      2       // blink with all color
#define FADE        3       // smooth transition between one color
#define SMOOTH      4       // smooth transition between all color

typedef struct rgbl_t {
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;
} Color;


typedef struct ribbon_t {
    uint8_t pin;
    Color fix_color;
    Color tab_led[NB_LED];
    void *mode;
    pthread_t thd;
} Ribbon;


/* Return a ribbon with default parameters
 * WARNING launch thread for executing the animation
 */
Ribbon set_ribbon(uint8_t pin);


/* Set the color for the Color type
 * return the color made with the RGBL value given in argument
 */
Color set_color(uint8_t red, uint8_t green, uint8_t blue);


/* Adjust the given color with the delta RGB value (positive or negative)
 * return the adjusted color
 */
Color adjust_color(Color color, int d_red, int d_green, int d_blue);


/* Change the Ribbon animation mode */
void change_mode(Ribbon *ribbon, uint8_t mode);


/* Change the starting color of the animation */
void change_color(Ribbon *ribbon, Color color);


#endif
