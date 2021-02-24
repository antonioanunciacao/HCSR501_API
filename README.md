# API PIR sensor HCSR501
##### -Developed by: Antonio Carlos da Anunciação, Guilherme Henrique de Almeida Leles
---
## Introduction

  This API was developed as a project of the discipline of Embedded Systems Programming at UFMG - Prof. Ricardo de Oliveira Duarte - Department of Electronic Engineering

  The Library is developed and tested with STM32F401RE (Nucleo 64 board) with HAL library functions.
  
  - Microcontroler: Nucleo STMF401RE, https://www.st.com/resource/en/user_manual/dm00556337-stm32g4-nucleo-64-boards-mb1367-stmicroelectronics.pdf
  - Sensor: HC-SR501 PIR, https://www.epitran.it/ebayDrive/datasheet/44.pdf


## API functions:

 ###  Init_HC_API(GPIOA,GPIO_PIN_1, SINGLE)
 This function receives the GPIO used by the sensor and the trigger type to initializes the API

### bool Ready_To_Use(void)
 This function return if sensor is ready to use after starting the api .
 The device requires nearly a minute to initialize.
 Return: True if the sensor is ready to use.
     	   False if the sensor is not ready to use.

### State Get_State()
 This function get the current state of the sensor.
 Return: State (INITIALIZING, TIME_DELAY, DETECTION_BLOCKED, NO_MOTION, UNDEFINED)  *

### Void Output_Event()
 The input pin must be configured for External Interrupt Mode with
 Rising/Falling edge trigger detection, and in its interrupt call this function.
 This function set the blocked_time parameter in the output event of HC SR501 , and that will be used in other functions..

## Example
### Pinout STM32F401RE:

![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/pin_configuration.PNG?raw=true)


### Timer1 Configuration:
![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/timer.PNG?raw=true)
### Circuit Assembly:

![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/assembly_.jpeg?raw=true=100x20)
