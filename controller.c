/*
 * Main program for light controller
 */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>



#include "light.h"

#define RIBBON              // pin of the led ribbon
#define IR_SENSOR           // pin of infrared sensor 


Ribbon leds_ribbon;         // the led_ribbon


void *ribbon_activity(void *arg){
    //TODO
    (void) arg;
    return 0;
}




int main(int argc, const char* argv[]){
    pthread_t light_activity;
    
    leds_ribbon = set_ribbon();
    
    //start activity 
    if(pthread_create(&light_activity, NULL, ribbon_activity, NULL) == -1) {
	fprintf(stderr, "[ERREUR] controller.c : main -> pthread_create");
	return 1;
    }
    
    //wait for event
    //TODO
    
    return 0;
}
