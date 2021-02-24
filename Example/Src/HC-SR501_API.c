/*
 * HC-SR501_API.c
 *
 *  Created on: 23 de fev de 2021
 *      Author: guilherme.leles
 */


/*
 * HC-SR501_API.c
 * Copyright (C) 2020 Antonio Carlos da Anunciação <antonioanunciacao@gmail.com>
 * Copyright (C) 2020 Guilherme Henrique de Almeida Leles <guilhermehaleles@hotmail.com>
 * Version 1.0 - API with the following implemented functions:
 * void Init_API(GPIO_Port port, GPIO_Pin pin);
 * bool Return_Motion_Detected();
 * void Wait_To_Use();
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
 * This API contains functions to read and deal with data from the
 * HC-SR501 PIR.
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
 * Return if sensor is read to use
 * The device requires nearly a minute to initialize.
*/
  bool Ready_To_Use(void)
  {

    if( (HAL_GetTick() - startup_time) > 6000)
    {
  		return true;
    }

    return false;
  }

/*
 * This function receives the GPIO used by the sensor and the trigger type to initializes the API
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
 * This function gets the value read by the sensor.
 * Return if is motion was detected
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


 State Get_State()
 {
	 if(Ready_To_Use())
	 {
		 Set_State();
	 }

	 return hc_sensor.state;

 }

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
