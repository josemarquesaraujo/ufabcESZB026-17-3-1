const int analogInPin = A0;            // o potenciômetro esta ligado ao pino A0
int iniciaColeta = 0;
char charRecebido;                     // cria uma variavel para armazenar o caractere recebido
int led2 = 2; // Led temperatura abaixo de 25 ºC
int led3 = 3; // Led temperatura acima de 30 ºC
int led4 = 4; //Led temperatura entre 25 ºC e 30 ºC

void setup(){
   // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}

void loop(){
   if (Serial.available()){            // verifica se recebeu algum comando
      charRecebido = Serial.read();    // le o caractere recebido
      switch ( charRecebido ){
          case 'i':                    // inicia coleta
             iniciaColeta = 1;
             break;
             
          case 'p':                    // para a coleta
             iniciaColeta = 0;
             break;
             
          default:                     // outro comando, ignora...
             break;
      }
   }
   if ( iniciaColeta == 1 ){
       int valor = analogRead(analogInPin); // le valor no pino A0 usando conversor ADC de 10-bit
       Serial.write(valor & 0xFF);          // envia byte menos significativo
       Serial.write(valor >> 8);            // envia byte mais significativo
       temp = (((valor*256.0)*5.0)/1023.0)/0.01;
     if (temp > 25 && temp <30){
       digitalWrite(led4, HIGH)
       digitalWrite(led3, LOW)
       digitalWrite(led2, LOW)

         else if (temp <= 25){
         digitalWrite(led4, LOW)
         digitalWrite(led2, HIGH)
         digitalWrite(led3, LOW)
     }
         else if (temp >= 30){
         digitalWrite(led4, LOW)
         digitalWrite(led2, LOW)
         digitalWrite(led3, HIGH)
         }
  
     }
   }
   delay(100);                          // aguarda 100ms
}
