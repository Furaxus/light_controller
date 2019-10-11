/*
 * Controller for light ribon
 */

#include <type.h>

#define NB_LED 50

/* ========== RIBBON MODE ========== */
#define RANDOM      0
#define FLASH       1       // set one color
#define STROBE      2       // blink with all color
#define FADE        3       // smooth transition between one color
#define SMOOTH      4       // smooth transition between all color

typedef struct rgbl_t Color;
typedef struct ribbon_t *Ribbon;


/* Init the ribbon with default parameters */
void set_ribbon(Ribbon ribbon);


/* Set the color for the Color type
 * return the color made with the RGBL value given in argument
 */
Color set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t luminosity);


/* Adjust the given color with the delta RGB value (positive or negative)
 * return the adjusted color
 */
Color adjust_color(Color color, uint8_t d_red, uint8_t d_green, uint8_t d_blue);


/* Adjust the given color's luminosity with the delta luminosity you give
 * return the adjusted color
 */
Color adjust_luminosity(Color color, uint8_t d_luminosity);


/* Change the Ribbon animation mode 
 * Following modes need a Color in third argument
 *  FLASH
 *  FADE
 */
void change_mode(Ribbon ribbon, uint8_t mode = RANDOM, Color fix_color = {0,0,0,0});


/* Play the animation */
void play_mode();


/* Stop the animation */
void stop_mode();