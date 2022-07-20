/*
 * periodic_services.c
 *
 *  Created on: Apr 11, 2022
 *      Author: uporabnik
 */




// ----------- Include other modules (for private) -------------

#include "periodic_services.h"
#include "stm32g4xx_ll_tim.h"
#include "LED.h"
#include "kbd.h"




// ---------------------- Private definitions ------------------

typedef struct
{

    TIM_TypeDef*   TIMx;

} periodic_services_handle_t;




// In sedaj na podlagi zgoraj definiranega tipa definiramo še globalno strukturno spremenljivko "TIM".

periodic_services_handle_t periodic_services;




void PSERV_init(void)
{
    periodic_services.TIMx = TIM6;

    LL_TIM_EnableCounter(periodic_services.TIMx);
}



void PSERV_enable(void)
{
    //LL_TIM_EnableUpdateEvent(periodic_services.TIMx);
    LL_TIM_EnableIT_UPDATE(periodic_services.TIMx);
}



void PSERV_disable(void)
{
    //LL_TIM_DisableUpdateEvent(periodic_services.TIMx);
    LL_TIM_DisableIT_UPDATE(periodic_services.TIMx);
}



void PSERV_run_services_Callback(void)
{
    KBD_scan();

    //KBD_demo_toggle_LEDs_if_buttons_pressed();
}



// Funkcija KBD_demo_toggle_LEDs_if_buttons_pressed() je namenjena testiranju
// delovanja tipkovnice. Deluje tako, da ugotovi, katere tipke so bile pritisnjene
// in se na te pritiske odzove s spremembo stanja ustrezne LEDice ("toggle").
//
// PAZITE: demo funkcija ne izvaja skeniranja tipkovnice! To je potrebno
// izvesti zunaj te funkcije.
void KBD_demo_toggle_LEDs_if_buttons_pressed(void)
{

    // Pomožna spremenljivka, kjer bomo hranili informacijo o nazadnje
    // pritisnjeni tipki.
    buttons_enum_t pressed_key;


    // Preberemo, katera tipka je bila pritisnjena nazadnje
    // (uporabite ustrezno KBD_ funkcijo).
    pressed_key = KBD_get_pressed_key();


    // Če je v pomožni spremenljivki informacija o pritisku dejanske tipke,
    while (pressed_key != BTN_NONE)
    {
        // spremenimo stanje ustrezne LEDice glede na to, katera tipka
        // je bila pritisnjena.
        switch ( pressed_key )
        {
          case BTN_OK:
              LED_toggle(LED2);
              break;
          case BTN_ESC:
              LED_toggle(LED3);
              break;
          case BTN_UP:
              LED_toggle(LED5);
              break;
          case BTN_DOWN:
              LED_toggle(LED6);
              break;
          case BTN_RIGHT:
              LED_toggle(LED4);
              break;
          case BTN_LEFT:
              LED_toggle(LED7);
              break;
          default:
              break;
        }


        // Preberemo, če je bila morda pritisnjena še kaka tipka,
        // ki še ni bila obdelana.
        pressed_key = KBD_get_pressed_key();

    }

}
