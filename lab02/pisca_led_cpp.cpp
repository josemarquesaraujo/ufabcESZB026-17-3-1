/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;

#define GPIO_AMARELO "16"
#define GPIO_VERMELHO "20"
#define GPIO_VERDE "21"

#define GPIO_PATH_AMARELO "/sys/class/gpio/gpio16/"
#define GPIO_PATH_VERMELHO "/sys/class/gpio/gpio20/"
#define GPIO_PATH_VERDE "/sys/class/gpio/gpio21/"

#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(string path, string filename, string value){
   fstream fs;
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

int main(int argc, char* argv[]){
   string cmd(argv[1]);
   int cont;
   for (cont = 0; cont<= 5; cont++){
      writeGPIO(string(GPIO_SYSFS), "export", GPIO_VERMELHO);
      usleep(100000);
      writeGPIO(string(GPIO_VERMELHO), "direction", "out");
      writeGPIO(string(GPIO_VERMELHO), "value", "1");
      usleep(2000000);   
      writeGPIO(string(GPIO_PATH_VERMELHO), "value", "0");
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_VERMELHO);

      writeGPIO(string(GPIO_SYSFS), "export", GPIO_VERDE);
      usleep(100000);
      writeGPIO(string(GPIO_VERDE), "direction", "out");
      writeGPIO(string(GPIO_VERDE), "value", "1");
      usleep(1000000);   
      writeGPIO(string(GPIO_PATH_VERDE), "value", "0");
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_VERDE);
      
      writeGPIO(string(GPIO_SYSFS), "export", GPIO_AMARELO);
      usleep(100000);
      writeGPIO(string(GPIO_AMARELO), "direction", "out");
      writeGPIO(string(GPIO_AMARELO), "value", "1");
      usleep(2000000);   
      writeGPIO(string(GPIO_PATH_AMARELO), "value", "0");
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_AMARELO);
      
      
   }
      
      
}
   
