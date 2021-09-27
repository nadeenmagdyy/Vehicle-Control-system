/*
 * functions.c
 *
 *  Created on: Sep 7, 2021
 *      Author: HERO
 */

#include <stdio.h>

char system_state()
{
	unsigned char state;
	printf("Please select one of those options: \n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c", &state);
	return state;
}

char sensors_set_menu()
{
	unsigned char sensor;
	printf("Please select one of those options: \n");
	printf("a. Turn off the vehicle engine.\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor).\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor).\n\n");

	scanf(" %c", &sensor);
	return sensor;
}

char traffic_light_data(char data)
{
	unsigned char speed;
	if(data == 'G')
	{
		speed = 100;
	}
	else if(data == 'O')
	{
		speed = 30;
	}
	else if(data == 'R')
	{
		speed = 0;
	}
	return speed;
}

int room_temperature_data(unsigned int temp, unsigned int *AC)
{
	*AC = 0;
	temp = 0;
	if ( temp < 10 )
	{
		*AC = 1;
		temp = 20;
	}

	else if (temp > 30)
	{
		*AC = 1;
		temp = 20;
	}
	else
	{
		*AC = 0;
	}
	return temp;
}

int engine_temperature_data (unsigned int temp, unsigned int *controller)
{
	if ( temp < 100 )
	{
		*controller = 1;
		temp = 125;
	}

	else if (temp > 150)
	{
		*controller = 1;
		temp = 125;
	}
	else
	{
		*controller = 0;
	}
	return temp;
}

void display_state(int AC, int speed, int room_temp, int  controller, int engine_temp)
{
	if(AC == 1)
	{
		printf("AC: ON \n");
	}
	else
	{
		printf("AC: OFF \n");
	}

	printf("The vehicle speed equals %d Km/h \n", speed);
	printf("Room Temperature: %d C \n", room_temp);
	if(controller == 1)
	{
		printf("Engine Temperature Controller State: ON \n");
	}
	else
	{
		printf("Engine Temperature Controller State: OFF \n");
	}
	printf("Engine Temperature: %d C \n \n", engine_temp);

}

