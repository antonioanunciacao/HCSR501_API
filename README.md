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


### Pinout STM32G474-Nucleo:

![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/pinout.PNG?raw=true)


### Clock Configuration to use of Buzzer:
- Frequency target ~250Hz
- Output Frequency 64MHz:
    prescalar= 64MHz/(255*255) = 985
- Prescalar 958, Duty Cycle [0,255]

### Clock Tree:
![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/clock_tree_output_~250hz.PNG?raw=true)
### Timer2 Configuration:
![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/timer2_configuration_~250hz.PNG?raw=true)
### Circuit Assembly:

![alt text](https://github.com/antonioanunciacao/HCSR501_API/blob/main/others/assembly.jpg?raw=true)
