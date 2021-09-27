/*
 * project1.c
 *
 *  Created on: Sep 7, 2021
 *      Author: HERO
 */

#include <stdio.h>
#include "prototypes.h"

#define ON 1
#define OFF 0
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	unsigned char state;
	unsigned char sensor;
	unsigned char data;
	unsigned char speed = 20;
	unsigned int room_temp = 35;
	unsigned int AC = 0;
	unsigned int engine_temp = 90;
	unsigned int controller = 0;

	do
	{
		state = system_state();
	}while(state == 'b');


	if (state == 'c')
	{
		printf("Quit the system...");
		return 0;
	}

	else if(state == 'a')
	{
		sensor = sensors_set_menu();
		while(1)
		{
			if (sensor == 'a')
			{
				do
				{
					state = system_state();
				}while(state == 'b');
				if (state == 'c')
				{
					printf("Quit the system...");
					return 0;
				}
				else if (state == 'a')
				{
					sensor = sensors_set_menu();
					if (sensor == 'a')
					{
						continue;

					}
				}

			}
			else if (sensor == 'b')  //traffic light
			{

				printf("Enter the traffic light data: \n");
				scanf(" %c", &data);
				speed = traffic_light_data(data);
				printf("The speed of the vehicle is %d km/h \n\n", speed);
				if (speed == 30)
				{
					AC = 1;
					room_temp = room_temp * (5/4) + 1;
					controller = 1;
					engine_temp = engine_temp * (5/4) + 1;
				}
				display_state(AC, speed, room_temp, controller, engine_temp);

				sensor = sensors_set_menu();
			}
			else if (sensor == 'c')   //room temp
			{
				printf("Enter the room temperature data: \n");
				scanf("%d", &room_temp);
				room_temp = room_temperature_data(room_temp, &AC);
				printf("The room temperature is %d and AC is %d \n\n", room_temp, AC);

				display_state(AC, speed, room_temp, controller, engine_temp);
				sensor = sensors_set_menu();

			}

			else if (sensor == 'd')  //engine temp
			{
				printf("Enter the engine temperature data: \n");
				scanf("%d", &engine_temp);
				engine_temp = engine_temperature_data(engine_temp, &controller);
				printf("The engine temperature is %d and Engine Temperature Controller is %d \n\n", engine_temp, controller);

				display_state(AC, speed, room_temp, controller, engine_temp);
				sensor = sensors_set_menu();
			}

		}


	}


	return 0;

}
