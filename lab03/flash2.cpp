<<<<<<< HEAD:lab03/flash.cpp
<<<<<<< HEAD
/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/
// Nao otimize este codigo usando -O3

#include <wiringPi.h>
#include <iostream>
using namespace std;
#define LED_GPIO  23                   // Usando LED na GPIO23, pino 16

int main() {
   wiringPiSetupGpio();                // usar a numeracao GPIO, nao WPi
   cout << "Iniciando o chaveamento do LED" << LED_GPIO << endl;
   pinMode(LED_GPIO, OUTPUT);          // ajusta a GPIO23 como saida
   for(int x = 0; x < 2000000; x++){     // 2000000 iteracoes
      digitalWrite(LED_GPIO, HIGH);    // LED ligado
      for(int i=0; i<50; i++) { }      // incluindo atraso
      digitalWrite(LED_GPIO, LOW);     // LED desligado
      for(int i=0; i<49; i++) { }      // incluindo atraso
   }
   return 0;                           // saindo
}
=======
/** Programa baseado no có digo disponibilizado em :
=======
** Programa baseado no có digo disponibilizado em :
>>>>>>> c38c09b177cc2533ab2d787aca6b88ca787b1d75:lab03/flash2
* Derek Molloy , Exploring Raspberry Pi : Interfacing to the Real World with Embedded Linux ,
* Wiley 2016 , ISBN 978 -1 -119 -1868 -1 , http :// www . exploringrpi . com /
*/

# include <wiringPi .h>
# include <iostream >
using namespace std ;
# define LED_GPIO 23 // Usando LED na GPIO23 , pino 16

int main () {
wiringPiSetupGpio () ; // usar a numeracao GPIO , nao WPi
cout << " Iniciando o chaveamento do LED " << LED_GPIO << endl ;
pinMode ( LED_GPIO , OUTPUT ) ; // ajusta a GPIO23 como saida
for ( int x = 0; x < 2000000; x ++) { // 20000 iteracoes
digitalWrite ( LED_GPIO , HIGH ); // LED ligado
for ( int i =0; i <50; i ++) { } // incluindo atraso
digitalWrite ( LED_GPIO , LOW ); // LED desligado
for ( int i =0; i <49; i ++) { } // incluindo atraso
}
return 0; // saindo
 }
>>>>>>> 2584d0cdd0f84cdc19737958c375f77368490166
