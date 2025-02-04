#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

volatile int state = 0; // Estado do semáforo (0 = vermelho, 1 = amarelo, 2 = verde)

// Função de callback do temporizador
bool traffic_light_callback(struct repeating_timer *t) {
    switch (state) {
        case 0: // Vermelho
            gpio_put(RED_LED, 1);
            gpio_put(YELLOW_LED, 0);
            gpio_put(GREEN_LED, 0);
            break;
        case 1: // Amarelo
            gpio_put(RED_LED, 1);
            gpio_put(YELLOW_LED, 0);
            gpio_put(GREEN_LED, 1);
            break;
        case 2: // Verde
            gpio_put(RED_LED, 0);
            gpio_put(YELLOW_LED, 0);
            gpio_put(GREEN_LED, 1);
            break;
    }
    
    state = (state + 1) % 3; // Alterna entre 0, 1 e 2
    return true; // Continua repetindo
}

int main() {
    stdio_init_all();
    
    gpio_init(RED_LED);
    gpio_init(YELLOW_LED);
    gpio_init(GREEN_LED);
    
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, traffic_light_callback, NULL, &timer);
    
    while (1) {
        printf("Semáforo operando...\n");
        sleep_ms(1000); // Imprime a cada segundo
    }
}
