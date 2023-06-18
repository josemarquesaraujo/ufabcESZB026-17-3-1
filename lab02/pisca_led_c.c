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
   
   for (cont = 0; cont < 5; cont++) {
      printf("Habilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "export", GPIO_VERMELHO);
      usleep(100000);
      writeGPIO(GPIO4_PATH_VERMELHO "direction", "out");
      usleep(2000000);
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_VERMELHO);

      writeGPIO(GPIO_SYSFS "export", GPIO_VERDE);
      usleep(100000);
      writeGPIO(GPIO4_PATH_VERDE "direction", "out");
      usleep(1000000);
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_VERDE);

      writeGPIO(GPIO_SYSFS "export", GPIO_AMARELO);
      usleep(100000);
      writeGPIO(GPIO4_PATH_AMARELO "direction", "out");
      usleep(1000000);
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_AMARELO);
   }
   
   return 0;
}
