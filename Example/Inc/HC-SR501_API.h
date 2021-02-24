/*
 * HC-SR501_API.h
 * Copyright (C) 2020 Antonio Carlos da Anunciação <antonioanunciacao@gmail.com>
 * Copyright (C) 2020 Guilherme Henrique de Almeida Leles <guilhermehaleles@hotmail.com>
 * Version 1.0 - API with the following implemented functions:
 * void Init_HC_API(GPIO_Port port, GPIO_Pin pin, Trigger trigger);
 * void Output_Event();
 * State Get_State();
 * bool Ready_To_Use();
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HC-SR501_API_H
#define HC-SR501_API_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stdbool.h"

/************************************** HC typedefs **************************************/
typedef GPIO_TypeDef* GPIO_Port;
typedef uint16_t GPIO_Pin;

typedef enum {
	INITIALIZING,
	TIME_DELAY,
	DETECTION_BLOCKED,
	NO_MOTION,
	UNDEFINED
} State;

typedef enum {
	SINGLE,
	REPEATABLE
} Trigger ;

typedef struct {
	State state;
	Trigger trigger;
	bool output;
} HCSensor;

/************************************** Public functions **************************************/
void Init_HC_API(GPIO_Port port, GPIO_Pin pin, Trigger trigger);
void Output_Event();
State Get_State();
bool Ready_To_Use();

#endif /* HC-SR501_API_H */
