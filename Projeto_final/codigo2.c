/** Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // biblioteca para comunicacao serial

#define TAMANHO 100

int main(){
   int file, count;
   int valores[TAMANHO];
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
   unsigned char lista_valores[TAMANHO];  // cria uma frase (\0 indica o final da mensagem)
       if ((count = write(file,"1" , 1))<0){             // transmite a frase
          perror("Falha ao escrever na saida\n");
          return -1;
       }
       usleep(10000);                     // Espera 10ms pela resposta do Arduino
       unsigned char receive[TAMANHO];         // cria um buffer para receber os dados
       if ((count = read(file, (void*)receive, TAMANHO))<0){        // recebe os dados
          perror("Falha ao ler da entrada\n");
          return -1;
       }
       
       if (count==0) printf("Nao houve resposta!\n");
       else {
         valores[nn] = receive[0];
       }
   
   close(file);
   return 0;
}
