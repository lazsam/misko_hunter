/*
 * periodic_services.h
 *
 *  Created on: Apr 11, 2022
 *      Author: uporabnik
 */

#ifndef INCLUDE_PERIODIC_SERVICES_H_
#define INCLUDE_PERIODIC_SERVICES_H_




// Pri implementaciji sistemskih funkcij za delo s tipkovnico bomo potrebovali sledeče nizko-nivojske funkcije:
//      - void LL_TIM_EnableCounter (TIM_TypeDef * TIMx)
//      - void LL_TIM_EnableIT_UPDATE (TIM_TypeDef * TIMx)
//      - void LL_TIM_DisableIT_UPDATE (TIM_TypeDef * TIMx)
//      - uint32_t LL_TIM_IsEnabledUpdateEvent (TIM_TypeDef * TIMx)
//      - uint32_t LL_TIM_IsEnabledIT_UPDATE (TIM_TypeDef * TIMx)
//      - void LL_TIM_ClearFlag_UPDATE (TIM_TypeDef * TIMx)




// ---------------- Public function prototypes ----------------

void PSERV_init(void);
void PSERV_enable(void);
void PSERV_disable(void);
void PSERV_run_services_Callback(void);
void KBD_demo_toggle_LEDs_if_buttons_pressed(void);




#endif /* INCLUDE_PERIODIC_SERVICES_H_ */
