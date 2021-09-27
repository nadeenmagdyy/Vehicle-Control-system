/*
 * prototypes.h
 *
 *  Created on: Sep 7, 2021
 *      Author: HERO
 */

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

char system_state();
char sensors_set_menu();
char traffic_light_data(char data);
int room_temperature_data(unsigned int temp, unsigned int *AC);
int engine_temperature_data (unsigned int temp, unsigned int *controller);
void display_state(int AC, int speed, int room_temp, int  controller, int engine_temp);

#endif /* PROTOTYPES_H_ */
