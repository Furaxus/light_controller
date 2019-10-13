#include "light.h"
#include <stdlib.h>
#include <time.h>



//srand(time(NULL));


Color set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t luminosity){
    Color rgbl;
    rgbl._red = red;
    rgbl._green = green;
    rgbl._blue = blue;
    rgbl._luminosity = luminosity;

    return rgbl;
}

#define RGBL(red, green, blue, luminosity) set_color(red, green, blue, luminosity)


uint8_t select_random_mode(void){
    uint8_t slct = rand()%4 +1;
    return slct;
}


uint8_t adjust(uint8_t color, int delta){
    int tmp_color = color + delta;
    if (tmp_color < 0)
        return 0;
    else if (tmp_color > 255)
        return 255;
    else
        return (uint8_t) tmp_color;
}


void set_all_led(Ribbon *ribbon, Color color){
    for (uint8_t i = 0; i < NB_LED; i++){
        ribbon->tab_led[i] = RGBL(color._red, color._green, color._blue, color._luminosity);
    }
}


Ribbon set_ribbon(){
    Ribbon ribbon;
    ribbon.mode = RANDOM;
    ribbon.fix_color._red = 255;
    ribbon.fix_color._green = 255;
    ribbon.fix_color._luminosity = 255;
    set_all_led(&ribbon, RGBL(255, 255, 255, 255));
    
    return ribbon;
}


Color adjust_color(Color color, int d_red, int d_green, int d_blue){
    color._red = adjust(color._red, d_red);
    color._green = adjust(color._green, d_green);
    color._blue = adjust(color._blue, d_blue);

    return color;
}


Color adjust_luminosity(Color color, int d_luminosity){
    color._luminosity = adjust(color._luminosity, d_luminosity);

    return color;
}


void play_mode(Ribbon *ribbon){
    //TODO
    switch (ribbon->mode){
        case RANDOM :
            ribbon->mode = select_random_mode();
            for (int i=0; i<RANDOM_ITERATION; i++){
                play_mode(ribbon);
            }
            ribbon->mode = RANDOM;
            break;
        case FLASH :
            set_all_led(ribbon, ribbon->fix_color);
            break;
        case STROBE :
            break;
        case FADE :
            break;
        case SMOOTH :
            break;
    }
    //print light
}


void change_mode(Ribbon *ribbon, uint8_t mode){
    if (0 <= mode && mode <= 4)
        ribbon->mode = mode;
    else
        ribbon->mode = RANDOM;
}


void change_color(Ribbon *ribbon, Color color){
    //TODO
}
