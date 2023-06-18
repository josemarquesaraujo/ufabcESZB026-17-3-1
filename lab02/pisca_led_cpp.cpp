/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include <iostream>/**inclui bibliotecas*/
#include <fstream>/**inclui bibliotecas*/
#include <string>/**inclui bibliotecas*/
#include <unistd.h>/**inclui bibliotecas*/
using namespace std;

#define GPIO_AMARELO "16"/**define o pino 16 da gpio*/
#define GPIO_VERMELHO "20"/**define o pino 20 da gpio*/
#define GPIO_VERDE "21"/**define o pino 21 da gpio*/

#define GPIO_PATH_AMARELO "/sys/class/gpio/gpio16/"/**define o caminho do pino 16*/
#define GPIO_PATH_VERMELHO "/sys/class/gpio/gpio20/"/**define o caminho do pino 20*/
#define GPIO_PATH_VERDE "/sys/class/gpio/gpio21/"/**define o caminho do pino 21*/

#define GPIO_SYSFS "/sys/class/gpio/"/***/

/**função para atribuir valor em um arquivo da gpio*/
void writeGPIO(const string& path, const string& filename, const string& value) {
    ofstream fs((path + filename).c_str());
    fs << value;
    fs.close();
}
/**inicia o programa*/
int main(int argc, char* argv[]) {
    int cont;
    /**loop que irá se repetir por 5 vezes*/
    for (cont = 0; cont <= 5; cont++) {
        writeGPIO(GPIO_SYSFS, "export", GPIO_VERMELHO);/**exporta o pino 20 da gpio*/
        usleep(100000);/**pausa de 0,1 segundo para garantir importação*/
        writeGPIO(GPIO_VERMELHO, "direction", "out");/**define o pino 20 como saída*/
        writeGPIO(GPIO_VERMELHO, "value", "1");/**atribui o valor 1, acende o led*/
        usleep(2000000);/**mantém o led aceso por 2 segundos*/
        writeGPIO(GPIO_PATH_VERMELHO, "value", "0");/**atribui o valor 0, apaga o led*/
        writeGPIO(GPIO_SYSFS, "unexport", GPIO_VERMELHO);/**exporta o pino 20 da gpio*/

        writeGPIO(GPIO_SYSFS, "export", GPIO_VERDE);/**exporta o pino 21 da gpio*/
        usleep(100000);/**pausa de 0,1 segundo para garantir importação*/
        writeGPIO(GPIO_VERDE, "direction", "out");/**define o pino 21 como saída*/
        writeGPIO(GPIO_VERDE, "value", "1");/**atribui o valor 1, acende o led*/
        usleep(1000000);/**mantém o led aceso por 1 segundo*/
        writeGPIO(GPIO_PATH_VERDE, "value", "0");/**atribui o valor 0, apaga o led*/
        writeGPIO(GPIO_SYSFS, "unexport", GPIO_VERDE);/**exporta o pino 21 da gpio*/

        writeGPIO(GPIO_SYSFS, "export", GPIO_AMARELO);/**exporta o pino 16 da gpio*/
        usleep(100000);/**pausa de 0,1 segundo para garantir importação*/
        writeGPIO(GPIO_AMARELO, "direction", "out");/**define o pino 16 como saída*/
        writeGPIO(GPIO_AMARELO, "value", "1");/**atribui o valor 1, acende o led*/
        usleep(1000000);/**mantém o led aceso por 1 segundo*/
        writeGPIO(GPIO_PATH_AMARELO, "value", "0");/**atribui o valor 0, apaga o led*/
        writeGPIO(GPIO_SYSFS, "unexport", GPIO_AMARELO);/**desexporta o pino 16 da gpio*/
    }

    return 0;
}
