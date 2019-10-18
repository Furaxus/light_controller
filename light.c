#include "light.h"
#include "ws2812b.h"
#include <stdlib.h>
#include <time.h>



//srand(time(NULL));

Color set_color(uint8_t red, uint8_t green, uint8_t blue);
#define RGB(red, green, blue, luminosity) set_color(red, green, blue)


/* Internal functions */
void _play_mode(Ribbon *ribbon);
uint8_t _select_random_mode(void);
uint8_t _adjust(uint8_t color, int delta);
void _set_all_led(Ribbon *ribbon, Color color);

/* Definition mode function */
void _flash_function(Ribbon *ribbon);
void _strobe_function(Ribbon *ribbon);
void _fade_function(Ribbon *ribbon);
void _smooth_function(Ribbon *ribbon);




Color set_color(uint8_t red, uint8_t green, uint8_t blue){
    Color rgbl;
    rgbl._red = red;
    rgbl._green = green;
    rgbl._blue = blue;

    return rgbl;
}


uint8_t _select_random_mode(void){
    uint8_t slct = rand()%4 +1;
    return slct;
}


uint8_t _adjust(uint8_t color, int delta){
    int tmp_color = color + delta;
    if (tmp_color < 0)
        return 0;
    else if (tmp_color > 255)
        return 255;
    else
        return (uint8_t) tmp_color;
}


void _set_all_led(Ribbon *ribbon, Color color){
    for (uint8_t i = 0; i < NB_LED; i++){
        ribbon->tab_led[i] = RGB(color._red, color._green, color._blue);
    }
}


void _print_ribbon(Ribbon *ribbon){
    uint8_t i;
    uint8_t pin;
    
    pin = ribbon->pin;
    for (i=0; i<NB_LED; i++){
        write_grb(ribbon->tab_led[i]._green, ribbon->tab_led[i]._red, ribbon->tab_led[i]._blue, pin);
    }
}


Ribbon set_ribbon(uint8_t pin){
    Ribbon ribbon;
    ribbon.pin = pin;
    ribbon.fix_color._red = 255;
    ribbon.fix_color._green = 255;
    _set_all_led(&ribbon, RGB(255, 255, 255, 255));
    ribbon.mode = _flash_function;
    
    
    //TODO launch thread
    if (pthread_create(&ribbon.thd, NULL, _play_mode, ribbon) != 0){
        
    }
    else
        return ribbon;
}


Color adjust_color(Color color, int d_red, int d_green, int d_blue){
    color._red = _adjust(color._red, d_red);
    color._green = _adjust(color._green, d_green);
    color._blue = _adjust(color._blue, d_blue);

    return color;
}


void change_color(Ribbon *ribbon, Color color){
    //TODO
}


/* **************************************************** */
/* *************** ANIMATION MANAGEMENT *************** */
void _play_mode(Ribbon *ribbon){
    ribbon->mode(ribbon);
}


void change_mode(Ribbon *ribbon, uint8_t mode){
    switch (mode){
        case RANDOM :
            change_mode(ribbon, _select_random_mode());
            break;
        case FLASH :
            ribbon->mode = _flash_function;
            break;
        case STROBE :
            ribbon->mode = _strobe_function;
            break;
        case FADE :
            ribbon->mode = _fade_function;
            break;
        case SMOOTH :
            ribbon->mode = _smooth_function;
            break;
    }
}


/* **************************************************** */
/* ****************** MODE FUNCTIONS ****************** */

void _flash_function(Ribbon *ribbon){
    _set_all_led(ribbon, ribbon->fix_color);
    //TODO
}

void _strobe_function(Ribbon *ribbon){
    _set_all_led(ribbon, ribbon->fix_color);
    _print_ribbon(ribbon);
    
    //TODO
}

void _fade_function(Ribbon *ribbon){
    //TODO
}

void _smooth_function(Ribbon *ribbon){
    //TODO
}


/* **************************************************** */
