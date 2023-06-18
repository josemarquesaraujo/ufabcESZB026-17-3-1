/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include <stdio.h> /**inclui bibliotecas*/
#include <stdlib.h> /**inclui bibliotecas*/
#include <string.h> /**inclui bibliotecas*/
#include <unistd.h> // Added for usleep function

#define GPIO_AMARELO "16" /**define o pino 16 da gpio*/
#define GPIO4_PATH_AMARELO "/sys/class/gpio/gpio16/" /**define o caminho até o pino*/

#define GPIO_VERMELHO "20"/**define o pino 20 da gpio*/
#define GPIO4_PATH_VERMELHO "/sys/class/gpio/gpio20/"/**define o caminho até o pino*/

#define GPIO_VERDE "21"/**define o pino 21 da gpio*/
#define GPIO4_PATH_VERDE "/sys/class/gpio/gpio21/"/**define o caminho até o pino*/

#define GPIO_SYSFS "/sys/class/gpio/"

/**função utilizada para escrever um valor específico em um arquivo de uma gpio*/
void writeGPIO(char filename[], char value[]){
   FILE* fp;
   fp = fopen(filename, "w+");
   fprintf(fp, "%s", value);
   fclose(fp);
}

int main(int argc, char* argv[]){
   int cont;
   /**loop a ser executado 5 vezes*/
   for (cont = 0; cont < 5; cont++) {
      printf("Habilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "export", GPIO_VERMELHO);/**exporta o gpio*/
      usleep(100000);/**pausa para garantir importação*/
      writeGPIO(GPIO4_PATH_VERMELHO "direction", "out");/**define o pino como saída*/
      writeGPIO(GPIO4_PATH_VERMELHO "value", "1");/**define o valor para 1, acende o led*/
      usleep(2000000);/**aguarda 2 segundos*/
      writeGPIO(GPIO4_PATH "value", "0"); /**define o valor como 0, apaga o led*/
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_VERMELHO);/**desexporta a gpio*/

      writeGPIO(GPIO_SYSFS "export", GPIO_VERDE);/**exporta o gpio*/
      usleep(100000);/**pausa para garantir importação*/
      writeGPIO(GPIO4_PATH_VERDE "direction", "out");/**define o pino como saída*/
      usleep(1000000);/**pausa de 1 segundo*/
      writeGPIO(GPIO4_PATH "value", "0"); /**define o valor como 0, apaga o led*/
      printf("Desabilitando a gpio\n");/***/
      writeGPIO(GPIO_SYSFS "unexport", GPIO_VERDE);/**desexporta a gpio*/

      writeGPIO(GPIO_SYSFS "export", GPIO_AMARELO);/**exporta o gpio*/
      usleep(100000);/**pausa para garantir a importação*/
      writeGPIO(GPIO4_PATH_AMARELO "direction", "out");/**define o pino como saída*/
      usleep(1000000);/**pausa de 1 segundo*/
      writeGPIO(GPIO4_PATH "value", "0"); /**define o valor como 0, apaga o led*/
      printf("Desabilitando a gpio\n");/***/
      writeGPIO(GPIO_SYSFS "unexport", GPIO_AMARELO);/**desexporta a gpio*/
   }
   
   return 0;
}
