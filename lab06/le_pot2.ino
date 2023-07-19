#include <Wire.h>                  
const byte enderecoEscravo = 0x40; 
const int PinoPotenciometro = A0;  
const int pinoLED = LED_BUILTIN;  
int dadoRecebido;                
int limiteAlarme = 0;             
int valorPot = 0;                
byte buffer[9];                    // Adicionamos mais duas posições para armazenar o valor em volts

void setup(){
  pinMode(pinoLED, OUTPUT);        
  TWBR = 10000L;                     
  Wire.begin(enderecoEscravo);
  Wire.onReceive(funcaoDadoRecebido); 
  Wire.onRequest(funcaoResposta);  
  Serial.begin(9600, SERIAL_8N1);     
  Serial.println("Fim da configuracao!"); 
}

void enviaDadosPelaSerial(){              
  Serial.print("Valor lido: "); Serial.print(valorPot);
  Serial.print("; limite do alarme: "); Serial.print(limiteAlarme);
  Serial.print("; e buffer = 0x");
  for (int i = 0; i < 7; i++) {
    Serial.print(buffer[i], HEX); Serial.print(" ");
  }
  Serial.println();
}

void loop(){                       
  valorPot = analogRead(PinoPotenciometro); 
  buffer[0] = valorPot & 0xFF;     
  buffer[1] = valorPot >> 8;      
  if (valorPot >= limiteAlarme) { 
     digitalWrite(pinoLED, HIGH);  
     buffer[4] = 0x01;
  }
  else {
     digitalWrite(pinoLED, LOW);   
     buffer[4] = 0x00;
  }
  enviaDadosPelaSerial();          
  delay(1000);
  float Volts = 5.0 * valorPot / 1023.0;
  buffer[5] = floor(Volts);
  buffer[6] = (((int)(Volts * 100)) % 100);
}

void funcaoDadoRecebido(int x){    
  dadoRecebido = Wire.read();      
  
  if (dadoRecebido == 0x02 && x == 3) {  
    byte dado1 = Wire.read();      
    byte dado2 = Wire.read();      
    int valorRecebido =  dado1 | (dado2 << 8 );
    if (valorRecebido >= 0 && valorRecebido <= 1023) {
      buffer[2] = dado1;
      buffer[3] = dado2;
      limiteAlarme = valorRecebido;
    }
  }
  if (dadoRecebido == 0x10) {
    limiteAlarme = valorPot; 
    buffer[2] = buffer[0]; 
    buffer[3] = buffer[1];
  }
}

void funcaoResposta(){             
  byte resposta = 0x00;
  if (dadoRecebido >= 0x00 && dadoRecebido <= 0x04){
    resposta = buffer[dadoRecebido];
  } else if (dadoRecebido == 0x10) { // Novo comando para enviar o valor em volts
    resposta = 0x05; // Indica que serão enviados 5 bytes (A, ., B, 0x00, 0x00)
  }
  delay(1);                       
  Wire.write(resposta);           
  if (dadoRecebido == 0x10) {
    Wire.write(buffer[5]); // Enviamos a parte inteira da tensão (A)
    Wire.write('.'); // Enviamos o ponto decimal
    if (buffer[6] < 10) {
      Wire.write('0'); // Se a parte decimal for menor que 10, enviamos um 0 à esquerda (B < 10)
    }
    Wire.write(buffer[6]); // Enviamos a parte decimal da tensão (B)
  }
}
