/*
 * HC-SR501_API.c
 * Copyright (C) 2020 Antonio Carlos da Anuncia��o <antonioanunciacao@gmail.com>
 * Copyright (C) 2020 Guilherme Henrique de Almeida Leles <guilhermehaleles@hotmail.com>
 *
 * Version 1.0 - API with the following implemented functions:
 * void Init_HC_API(GPIO_Port port, GPIO_Pin pin, Trigger trigger);
 * void Output_Event();
 * State Get_State();
 * bool Ready_To_Use();
 *
 * This API was developed as a work of the Embedded Systems Programming
 * discipline from UFMG - Prof. Ricardo de Oliveira Duarte - Department
 * of Electronic Engineering.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 *  with this program; if not, If not, see <https://www.gnu.org/licenses/>
 *
 * Created on: 22 de feb de 2021
 * Institution: UFMG
 *
 * This API contains functions to deal with the HC-SR501 PIR.
 */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "HC-SR501_API.h"

/* USER CODE END Includes */

GPIO_Port hc_port;
GPIO_Pin hc_pin;

uint32_t startup_time = 0;

uint32_t detection_blocked_time = 0;

HCSensor hc_sensor;


/*
 * This function return if sensor is read to use.
 * The device requires nearly a minute to initialize.
 * Return: True if the sensor is ready to use
 * 		   False if the sensor is not ready to use
*/
  bool Ready_To_Use(void)
  {

    if( (HAL_GetTick() - startup_time) > 60000)
    {
  		return true;
    }

    return false;
  }

/*
 * This function receives the GPIO used by the sensor and the trigger type to initializes the API
 * port: GPIOX
 * pin: GPIO_PIN_X
 * Triger: SINGLE, REPEATABLE
 */
 void Init_HC_API(GPIO_Port port, GPIO_Pin pin, Trigger trigger)
 {

   hc_port = port;
   hc_pin = pin;

   hc_sensor.state = INITIALIZING;
   hc_sensor.trigger = trigger;
   hc_sensor.output = false;

   startup_time = HAL_GetTick();
 }


/*
 * The input pin of the stm must be configured for External Interrupt Mode with
 * Rising/Falling edge trigger detection, and in its interrupt call this function.
 * This function set the blocked_time paramenter, that will be used in other functions
 *
*/

 void Output_Event()
 {

   if(Ready_To_Use())
   {
	   if(!hc_sensor.output)
	   {
		   hc_sensor.state = TIME_DELAY;
		   hc_sensor.output = true;

		   detection_blocked_time = 0;
	   }
	   else
	   {
		   hc_sensor.state = DETECTION_BLOCKED;
		   hc_sensor.output = false;

		   detection_blocked_time = HAL_GetTick();

	   }

   }

 }


 /*
  * This function get the current state of the sensor.
  * Return: State (INITIALIZING, TIME_DELAY, DETECTION_BLOCKED, NO_MOTION, UNDEFINED)  *
  */

 State Get_State()
 {
	 if(Ready_To_Use())
	 {
		 Set_State();
	 }

	 return hc_sensor.state;

 }

 /*
  * This function set the current state to NO_MOTION if necessary.
  */

 void Set_State()
 {
	 hc_sensor.output = HAL_GPIO_ReadPin(hc_port, hc_pin);

	 if(HAL_GetTick() > (detection_blocked_time + 3000) && hc_sensor.output == false)
	 {
		 hc_sensor.state = NO_MOTION;
	 }

 }



/*
 *
 *
 */
