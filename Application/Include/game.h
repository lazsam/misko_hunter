/*
 * game.h
 *
 *  Created on: May 14, 2022
 *      Author: Gasper
 */

#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_



// ----------- Include other modules (for public) -------------


// -------------------- Public definitions --------------------


// ---------------- Public function prototypes ----------------

void 		Game();
uint8_t 	Intro();
uint8_t 	GamePlay();
uint8_t 	GameOver();
void GamePlay_Update_Aiming_LED_Indicator(void);





#endif /* INCLUDE_GAME_H_ */
