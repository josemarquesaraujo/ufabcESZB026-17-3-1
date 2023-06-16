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
   
      writeGPIO(string(GPIO_SYSFS), "export", GPIO_NUMBER);
      usleep(100000);
      writeGPIO(string(GPIO_PATH), "value", "1");
      usleep(100000);
      writeGPIO(string(GPIO_PATH), "direction", "out");
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_NUMBER);
   }
   
