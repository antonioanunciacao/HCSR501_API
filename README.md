# API PIR sensor HCSR501
##### -Developed by: Antonio Carlos da Anunciação, Guilherme Henrique de Almeida Leles
---
## Introduction

  This API was developed as a project of the discipline of Embedded Systems Programming at UFMG - Prof. Ricardo de Oliveira Duarte - Department of Electronic Engineering

  The Library is developed and tested with Stm32F401RE (Nucleo 64 board)
  
  - Microcontroler: Nucleo STMF401RE, https://www.st.com/resource/en/user_manual/dm00556337-stm32g4-nucleo-64-boards-mb1367-stmicroelectronics.pdf
  - Sensor: HC-SR501 PIR, https://www.epitran.it/ebayDrive/datasheet/44.pdf


### Quick Start

```c
#include "HC-SR501_API.h"
```
```c
Init_API(GPIOA, GPIO_PIN_1);
```


## API functions:

### Wait_To_Use()
 Return if sensor is read to use.
 The device requires nearly a minute to initialize.
 ### Init_API(GPIO_Port port, GPIO_Pin pin)
  This function receives the GPIO used by the sensor and initializes the API
#### Setting Nucleo-F401RE:

In this project you will need to configure three ports:

- Input port for the SR501 sensor signal.
- Output port for Buzzer PWM signal.
- Output port for Green LED output on the board (pre-configured).

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/tree/main/Example/images/GPIOPORT.PNG?raw=true)


#### Pinout Layout:

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/tree/main/Example/images/pinout.PNG?raw=true)

#### Setting Clock Configuration(ABP1):

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/tree/main/Example/images/CLOCK_TREE.PNG?raw=true)

---
#### Operation:

The microcontroller is in the main loop detecting if there is a reading on PIN_1, while there is a signal it alternates between turning the buzzer on and off.

    while (1) {
      if( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) ) {

        turnOnBuzzer();
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0); //turn on Green LED on the board
        while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1));
        turnOffBuzzer();

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1); //turn off //Green LED on the board
        }
    }

Buzzer Activation:

    void turnOffBuzzer(void) {
      TIM1->CCR1 = 0; // 0% duty cycle
    }

    void turnOnBuzzer(void) {
      TIM1->CCR1 = 80; //80% duty cycle
    }

---
### Circuit Assembly:

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/tree/main/Example/images/montagem.png?raw=true)
