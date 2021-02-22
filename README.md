## Embedded Systems Programming - UFMG
### API PIR sensor HCSR501
#### - Antonio Carlos da Anunciação
#### - Guilherme Henrique de Almeida Leles
---

  In this work, an API was developed to use the presence sensor. The purpose is to trigger an alarm if you check the signal coming from the motion sensor.
  
  - Microcontroler: Nucleo STMG474RE, https://www.st.com/resource/en/user_manual/dm00556337-stm32g4-nucleo-64-boards-mb1367-stmicroelectronics.pdf
  - Sensor: HC-SR501 PIR, https://www.epitran.it/ebayDrive/datasheet/44.pdf
  - Buzzer: Buzzer Active, https://components101.com/misc/buzzer-pinout-working-datasheet


#### Setting Nucleo-G474RE:

In this project you will need to configure three ports:

- Input port for the SR501 sensor signal.
- Output port for Buzzer PWM signal.
- Output port for Green LED output on the board (pre-configured).

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/Example/imagens/GPIOPORT.PNG?raw=true)


#### Pinout Layout:

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/Example/imagens/pinout.PNG?raw=true)

#### Setting Clock Configuration(ABP1):

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/Example/imagens/CLOCK_TREE.PNG?raw=true)

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

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/Example/imagens/montagem.png?raw=true)
