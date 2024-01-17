//
//  RPi_Cycle_4xGPIO_Out_01.c
//
//  https://www.youtube.com/watch?v=jlM9KoWyPv0&list=PL-6WIzdGN7xQdIvyCtQUhmflKNsidxfwX&index=5
//
//
#include <bcm2835.h>  // https://www.airspayce.com/mikem/bcm2835/ 
#include <stdio.h>
#include <stdbool.h>

# define GPIO5 RPI_BPLUS_GPIO_J8_29 // GPIO 5 - Defines variable GPIO5 (physical header pin #29) for bcm2835.h
# define GPIO6 RPI_BPLUS_GPIO_J8_31 // GPIO 6 - Defines variable GPIO6 (physical header pin #31) for bcm2835.h
# define GPIO12 RPI_BPLUS_GPIO_J8_32 // GPIO 12 - Defines variable GPIO12 (physical header pin #32) for bcm2835.h
# define GPIO13 RPI_BPLUS_GPIO_J8_33 // GPIO 13 - Defines variable GPIO13 (physical header pin #33) for bcm2835.h

bool ON = 1;
bool OFF = 0;

int main (int argc, char **argv){
    // This next line initializes the bcm2835 library.
    // This is another way of saying setting up options or
    // configuring the registers of the BCM2835.
    if (!bcm2835_init()) return 1; //  If BCM2835 is initialized, return a 1 (true).

    /* ************** Set Pin Direction *****************
       * This next line of cose sets the direction of
       * the GPIO29 pin, which we defined earlier as RPI_GPIO_P1_29
       * to an output. This functionis explained in the support website
       * the BCM2835 library
       * *************************************************
    */
    bcm2835_gpio_fsel(GPIO5, BCM2835_GPIO_FSEL_OUTP); // Sets GPIO5 / physical pin 29 as an output.
    bcm2835_gpio_fsel(GPIO6, BCM2835_GPIO_FSEL_OUTP); // Sets GPIO6 / physical pin 31 as an output.
    bcm2835_gpio_fsel(GPIO12, BCM2835_GPIO_FSEL_OUTP); // Sets GPIO12 / physical pin 32 as an output.
    bcm2835_gpio_fsel(GPIO13, BCM2835_GPIO_FSEL_OUTP); // Sets GPIO13 / physical pin 33 as an output.
       
    unsigned int delay = 400;      /*  Sets the delay time for a 50% duty cycle. */
    printf("Initialized the GPIO pins as outputs and starting the loop... \n");
    
    while (1){                      /* Loop forever */
        bcm2835_gpio_set (GPIO5);  /* GPIO5 on physical pin 29 Output is SET / ON / High / One / True */
        printf("GPIO 5 on physical pin #29 went True \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        bcm2835_gpio_clr (GPIO5);  /* GPIO5 on physical pin 29 Output is CLEAR / OFF / Low / 0 / False */
        printf("GPIO 5 on physical pin #29 went False \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        
        bcm2835_gpio_set (GPIO6);  /* GPIO6 on physical pin 31 Output is SET / ON / High / One / True */
        printf("GPIO 6 on physical pin #31 went True \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        bcm2835_gpio_clr (GPIO6);  /* GPIO6 on physical pin 31 Output is CLEAR / OFF / Low / 0 / False */
        printf("GPIO 6 on physical pin #31 went False \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        
        bcm2835_gpio_set (GPIO12);  /* GPIO12 on physical pin 32 Output is SET / ON / High / One / True */
        printf("GPIO 12 on physical pin #32 went True \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        bcm2835_gpio_clr (GPIO12);  /* GPIO12 on physical pin 32 Output is CLEAR / OFF / Low / 0 / False */
        printf("GPIO 12 on physical pin #32 went False \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        
        bcm2835_gpio_set (GPIO13);  /* GPIO13 on physical pin 33 Output is SET / ON / High / One / True */
        printf("GPIO 13 on physical pin #33 went True \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        bcm2835_gpio_clr (GPIO13);  /* GPIO13 on physical pin 33 Output is CLEAR / OFF / Low / 0 / False */
        printf("GPIO 13 on physical pin #33 went False \n");
        bcm2835_delay (delay);      /* Pause for the duration of the "delay" in miliseconds */ 
        
        
        
    }

}
