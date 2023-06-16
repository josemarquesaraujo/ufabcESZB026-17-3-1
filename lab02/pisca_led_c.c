/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GPIO_AMARELO "16"
#define GPIO4_PATH_AMARELO "/sys/class/gpio/gpio16/"

#define GPIO_VERMELHO "20"
#define GPIO4_PATH_VERMELHO "/sys/class/gpio/gpio20/"

#define GPIO_VERDE "21"
#define GPIO4_PATH_VERDE "/sys/class/gpio/gpio21/"

#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // cria um ponteiro fp
   fp = fopen(filename, "w+");         // abre o arquivo para escrita
   fprintf(fp, "%s", value);           // grava o valor no arquivo
   fclose(fp);                         // fecha o arquivo
}

int main(int argc, char* argv[]){
   int cont;
   
    for (cont=0; cont<=5; cont++){
      printf("Habilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "export", GPIO_VERMELHO);
      usleep(100000);                  // aguarda 100ms
      writeGPIO(GPIO4_VERMELHO "direction", "out");
      usleep(2000000);
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_VERMELHO);

      writeGPIO(GPIO_SYSFS "export", GPIO_VERDE);
      usleep(100000);                  // aguarda 100ms
      writeGPIO(GPIO4_VERDE "direction", "out");
      usleep(1000000);
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_VERDE);

       writeGPIO(GPIO_SYSFS "export", GPIO_AMARELO);
      usleep(100000);                  // aguarda 100ms
      writeGPIO(GPIO4_AMARELO "direction", "out");
      usleep(1000000);
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_AMARELO);

       
    }
      
}
   

   
   


