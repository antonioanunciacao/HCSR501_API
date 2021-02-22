## Projeto de Programacao de Sistemas Embarcados
### API para o sensor de presença HCSR501
#### Nome: Antonio Carlos da Anunciação
#### Nome: Guilherme Henrique de Almeida Leles
---

  Neste trabalho foi construida uma API para uso do sensor de presença. O objetivo é, dada uma detecção de sinal no sensor de movimento o dispositivo gera uma saida, neste caso a saida escolhida foi um alarme sonoro.
  
  Microcontrolador: Nucleo STMG474RE, https://www.st.com/resource/en/user_manual/dm00556337-stm32g4-nucleo-64-boards-mb1367-stmicroelectronics.pdf
  
  Sensor: HC-SR501 PIR, https://www.epitran.it/ebayDrive/datasheet/44.pdf
  
  Buzzer: Buzzer Active, https://components101.com/misc/buzzer-pinout-working-datasheet


#### Configurando o Nucleo-G474RE:

Neste projeto vai ser preciso configurar três portas:

- Porta de entrada para o sinal do sensor SR501.

- Porta de saída para sinal PWM do Buzzer.

- Porta de saída LED Luninoso verde da placa (pré-configurada).

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/blob/main/API_PIR_HCSR501/imagens/GPIOPORT.PNG?raw=true)


#### Layout da pinagem:

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/blob/main/API_PIR_HCSR501/imagens/pinout.PNG?raw=true)

#### Configuração do clock no TIMMER1(ABP1):

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/blob/main/API_PIR_HCSR501/imagens/CLOCK_TREE.PNG?raw=true)

---
#### Funcionamento:

O microcontrolador fica no loop principal detectando se existe uma leitura no PIN_1, enquanto houver sinal ele alterna entre ligar e desligar o buzzer.

    while (1) {
      if( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) ) {

        turnOnBuzzer();
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0); //led verde da placa
        while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1));
        turnOffBuzzer();

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1); //led verde da placa
        }
    }

Acionamento do Buzzer:

    void turnOffBuzzer(void) {
      TIM1->CCR1 = 0; // 0% duty cycle
    }

    void turnOnBuzzer(void) {
      TIM1->CCR1 = 80; //80% duty cycle
    }

---
### Montagem do circuito:

![alt text](https://github.com/antonioanunciacao/Programa-o-de-Sistemas-Embarcados/blob/main/API_PIR_HCSR501/imagens/montagem.png?raw=true)
