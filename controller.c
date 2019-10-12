/*
 * Main program for light controller
 */

#include <pthread.h>



#include "light.h"

#define RIBBON              // pin of the led ribbon
#define IR_SENSOR           // pin of infrared sensor 



void *ribbon_activity(void *arg){
    //TODO
    (void) arg;
}




int main(void){
    pthread_t light_activity;
    Ribbon leds_ribbon;
    
    set_ribbon(leds_ribbon);
    
    //start activity 
    if(pthread_create(&light_activity, NULL, ribbon_activity, NULL) == -1) {
	perror("[ERREUR] controller.c : main -> pthread_create");
	return EXIT_FAILURE;
    }
    
    //wait for event
    //TODO
    
    return EXIT_SUCCESS;
}
