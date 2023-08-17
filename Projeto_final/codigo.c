/** Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // biblioteca para comunicacao serial

#define TAMANHO 10

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
      
      //   INICIA COLETA
      if ((count = write(file, "i", 1))<0){             // transmite a frase
            perror("Falha ao escrever na saida\n");
            return -1;
      }
      usleep(100000);                     // Espera 10ms pela resposta do Arduino
      
      // LE DADOS
      unsigned char receive[2];         // cria um buffer para receber os dados
      float lista_valores[TAMANHO];         // cria um buffer para receber os dados
      for(int nn = 0; nn < TAMANHO; nn++){
            if ((count = read(file, (void*)receive, 1))<0){        // recebe os dados
                  perror("Falha ao ler da entrada\n");
                  return -1;
            }
            lista_valores[nn] = ((receive[0])*5.0/1023.0)/0.01;
            printf("Valores \t[%f]\t[%d]\t[%d]\n", lista_valores[nn],receive[0],receive[1]);
            usleep(220000);
      }

      //   INTERROMPE COLETA
      if ((count = write(file, "p", 1))<0){             // transmite a frase
            perror("Falha ao escrever na saida\n");
            return -1;
      }
      usleep(10000);                     // Espera 10ms pela resposta do Arduino

      
   
      
      // GRAVA VALORES
      FILE *fp_saida;
      fp_saida = fopen ("/home/pi/ufabcESZB026-17-3-1/Projeto_final/Projeto.txt", "w");
      for (int ii=0; ii<TAMANHO; ii++){
            fprintf(fp_saida, "%f %f\n", ii/10.0, lista_valores[ii]);
      }
      fclose(fp_saida);
}
