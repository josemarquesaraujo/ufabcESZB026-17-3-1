// Ajustando o PWM por HARDWARE na Raspberry Pi

#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 10kHz com 128 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 261,6 = 19200000 / (divisor * 128) => divisor = 15
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(3495);                    // passos do duty cycle (max=4096)
   pwmSetClock(21);                     // fornece uma frequencia de 10kHz (max=4096)
   printf("Iniciando...\n");
   for(ciclos = 0; ciclos < 2; ciclos++){  // variando o duty cycle
    for(dc = 0; dc < 5; dc++){
        pwmWrite(pino_PWM0, 3494/2);	
        usleep(150000);
	      pwmWrite(pino_PWM0, 0);
	      usleep(100000);
      if (dc == 2) {
      usleep(250000);
      }
 }usleep(2000000);
   }

   printf("Fim.\n");
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
