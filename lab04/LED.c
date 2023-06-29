#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <softPwm.h>

int main(){
	int pino_PWM = 23;                         // pwm por software na GPIO23
	int brilho;
	int range = 100;                           // periodo do PWM = 100us*range
	wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
	pinMode(pino_PWM,OUTPUT);	           // configura GPIO23 como saida
	softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software

  if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;             // cria estruturas para configurar a comunicacao
   tcgetattr(file, &options);          // ajusta os parametros do arquivo
    // Configura a comunicacao
   // 115200 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;   // ignora erros de paridade
   tcflush(file, TCIFLUSH);            // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente
  
   unsigned char receive[100];         // cria um buffer para receber os dados
	
  while (1) {
    if ((count = read(file, (void*)receive, 100))>0){        // recebe os dados
      perror("Falha ao ler da entrada\n");
      return -1;
   }
    if  (brilho>0){
      softPwmWrite (pino_PWM, brilho); // altera o duty cycle do PWM
		  usleep (1000) ;  
    }
		
	}
}
