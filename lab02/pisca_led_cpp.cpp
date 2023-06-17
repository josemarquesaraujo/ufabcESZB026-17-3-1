/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

#define GPIO_AMARELO "16"
#define GPIO_VERMELHO "20"
#define GPIO_VERDE "21"

#define GPIO_PATH_AMARELO "/sys/class/gpio/gpio16/"
#define GPIO_PATH_VERMELHO "/sys/class/gpio/gpio20/"
#define GPIO_PATH_VERDE "/sys/class/gpio/gpio21/"

#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(const string& path, const string& filename, const string& value) {
    ofstream fs((path + filename).c_str());
    fs << value;
    fs.close();
}

int main(int argc, char* argv[]) {
    string cmd(argv[1]);
    int cont;
    for (cont = 0; cont <= 5; cont++) {
        writeGPIO(GPIO_SYSFS, "export", GPIO_VERMELHO);
        usleep(100000);
        writeGPIO(GPIO_VERMELHO, "direction", "out");
        writeGPIO(GPIO_VERMELHO, "value", "1");
        usleep(2000000);
        writeGPIO(GPIO_PATH_VERMELHO, "value", "0");
        writeGPIO(GPIO_SYSFS, "unexport", GPIO_VERMELHO);

        writeGPIO(GPIO_SYSFS, "export", GPIO_VERDE);
        usleep(100000);
        writeGPIO(GPIO_VERDE, "direction", "out");
        writeGPIO(GPIO_VERDE, "value", "1");
        usleep(1000000);
        writeGPIO(GPIO_PATH_VERDE, "value", "0");
        writeGPIO(GPIO_SYSFS, "unexport", GPIO_VERDE);

        writeGPIO(GPIO_SYSFS, "export", GPIO_AMARELO);
        usleep(100000);
        writeGPIO(GPIO_AMARELO, "direction", "out");
        writeGPIO(GPIO_AMARELO, "value", "1");
        usleep(2000000);
        writeGPIO(GPIO_PATH_AMARELO, "value", "0");
        writeGPIO(GPIO_SYSFS, "unexport", GPIO_AMARELO);
    }

    return 0;
}
