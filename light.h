/*
 * Controller for light ribon
 */

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <stdint.h>

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
    uint8_t _luminosity;
} Color;


typedef struct ribbon_t {
    uint8_t mode;
    Color fix_color;
    Color tab_led[NB_LED];
} Ribbon;


/* Return a ribbon with default parameters */
Ribbon set_ribbon();


/* Set the color for the Color type
 * return the color made with the RGBL value given in argument
 */
Color set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t luminosity);


/* Adjust the given color with the delta RGB value (positive or negative)
 * return the adjusted color
 */
Color adjust_color(Color color, int d_red, int d_green, int d_blue);


/* Adjust the given color's luminosity with the delta luminosity you give
 * return the adjusted color
 */
Color adjust_luminosity(Color color, int d_luminosity);


/* Change the Ribbon animation mode */
void change_mode(Ribbon *ribbon, uint8_t mode);


/* Change the starting color of the animation */
void change_color(Ribbon *ribbon, Color color);


/* Play the animation once */
void play_mode(Ribbon *ribbon);


#endif
