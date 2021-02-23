# API PIR sensor HCSR501
##### -Developed by: Antonio Carlos da Anunciação, Guilherme Henrique de Almeida Leles
---
## Introduction

  This API was developed as a project of the discipline of Embedded Systems Programming at UFMG - Prof. Ricardo de Oliveira Duarte - Department of Electronic Engineering

  The Library is developed and tested with Stm32F401RE (Nucleo 64 board)
  
  - Microcontroler: Nucleo STMF401RE, https://www.st.com/resource/en/user_manual/dm00556337-stm32g4-nucleo-64-boards-mb1367-stmicroelectronics.pdf
  - Sensor: HC-SR501 PIR, https://www.epitran.it/ebayDrive/datasheet/44.pdf


#### Quick Start

```c
#include "HC-SR501_API.h"
```
```c
Init_API(GPIOA, GPIO_PIN_1);
```


## API functions:

### Wait_To_Use()
 The device requires nearly a minute to initialize.
 ### Init_API(GPIO_Port port, GPIO_Pin pin)
  This function receives the GPIO used by the sensor and initializes the API

### Return_Motion_Detected()
 This function gets the value read by the sensor.
 Return if the motion was detected.

