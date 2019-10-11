#include "light.h"


typedef struct rgbl_t {
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;
    uint8_t _luminosity;
};


typedef struct ribbon_t {
    uint8_t mode;
    rgbl_t fix_color;
    rgbl_t tab_led[NB_LED];
};

uint8_t adjust(uint8_t color, int delta){
    int tmp_color = color + delta;
    if (tmp_color < 0)
        return 0;
    else if (tmp_color > 255)
        return 255;
    else
        return (uint8_t) tmp_color;
}


void set_all_led(Ribbon ribbon, uint8_t red, uint8_t green, uint8_t blue, uint8_t luminosity){
    for (uint8_t i = 0; i < NB_LED; i++){
        ribbon->tab_led[i] = {red, green, blue, luminosity};
    }
}


void set_ribbon(Ribbon ribbon){
    ribbon->mode = RANDOM;
    ribbon->fix_color._red = 255;
    ribbon->fix_color._green = 255;
    ribbon->fix_color._blue = 255;
    ribbon->fix_color._luminosity = 255;
    set_all_led(ribbon, 255, 255, 255, 255);
}


Color set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t luminosity){
    Color rgbl;
    rgbl._red = red;
    rgbl._green = green;
    rgbl._blue = blue;
    rgbl._luminosity = luminosity;

    return rgbl;
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


