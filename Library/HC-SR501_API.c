/*
 * HC-SR501_API.c
 * Copyright (C) 2020 Antonio Carlos da Anunciação <antonioanunciacao@gmail.com>
 * Copyright (C) 2020 Guilherme Henrique de Almeida Leles <guilhermehaleles@hotmail.com>
 * Version 1.0 - API with the following implemented functions:

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


 /*
 * Return if sensor is read to use
 * The device requires nearly a minute to initialize.
*/
  void Wait_To_Use(){
    // To do
    HAL_Delay(1000);
  }
  
/*
 * This function receives the GPIO used by the sensor
 */
 void Init_API(GPIO_Port port, GPIO_Pin pin){
   hc_port = port;
   hc_pin = pin; 
   Wait_To_Use();
 }

/*
 * This function gets the value read by the sensor.
 * Return if is moving or not
*/
 bool Return_Motion_Detected(){
   return HAL_GPIO_ReadPin(port,pin);
 }