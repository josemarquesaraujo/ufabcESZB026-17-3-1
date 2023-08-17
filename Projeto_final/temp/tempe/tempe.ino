const int speakerPin = 9;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
float temp = 0.0;
const int analogInPin = A0;  
int enviaColeta = 0;

// Frequências das notas musicais (C4 até B4)
const float freqs1[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
const float freqs2[] = {50, 75, 100, 125, 150, 175, 200};
const float freqs3[] = {100, 200, 250, 275, 300, 312.5, 325};

// Durações das notas (em milissegundos)
const int duracao1[] = {400, 400, 400, 400, 400, 400, 400, 800, 400, 400, 400, 400, 400, 400, 400, 800};
const int duracao2[] = {200, 200, 200, 200, 200, 200, 200, 400, 200, 200, 200, 200, 200, 200, 200, 400};
const int duracao3[] = {800, 800, 800, 800, 800, 800, 800, 1200, 800, 800, 800, 800, 800, 800, 800, 1200};

unsigned long ini1;
unsigned long ini2;
unsigned long ini3;

boolean t1 = false;
boolean t2 = false;
boolean t3 = false;


void setup() {
  Serial.begin(115200, SERIAL_8N1);
  pinMode(speakerPin, OUTPUT);
  pinMode(analogInPin, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  enviaColeta = 0;
}

void toca1(unsigned long tempo){
    for (int i = 0; i < sizeof(freqs1) / sizeof(freqs1[0]); i++) {
      int posicao = floor(tempo-ini1)/200;
      if(posicao == i){
        tone(speakerPin, freqs1[i]);
        //delay(duracao1[i]);
        //noTone(speakerPin);
      }
    }
    if (floor(tempo-ini1)/200 > (sizeof(freqs1) / sizeof(freqs1[0])) + 1) noTone(speakerPin);
    /*Serial.print(tempo);
    Serial.print(" ");
    Serial.println(ini1);*/
}

void toca2(unsigned long tempo){
    for (int i = 0; i < sizeof(freqs2) / sizeof(freqs2[0]); i++) {
      int posicao = floor(tempo-ini1)/200;
      if(posicao == i){
        tone(speakerPin, freqs2[i]);
//        delay(duracao2[i]);
//        noTone(speakerPin);
      }
    }
    if (floor(tempo-ini1)/200 > (sizeof(freqs2) / sizeof(freqs2[0])) + 1) noTone(speakerPin);
}

void toca3(unsigned long tempo){
    for (int i = 0; i < sizeof(freqs3) / sizeof(freqs3[0]); i++) {
      int posicao = floor(tempo-ini1)/200;
      if(posicao == i){
        tone(speakerPin, freqs3[i]);
//        delay(duracao3[i]);
//        noTone(speakerPin);
      }
    }
    if (floor(tempo-ini1)/200 > (sizeof(freqs3) / sizeof(freqs3[0])) + 1) noTone(speakerPin);
}



void loop() {
    char charRecebido;
    if (Serial.available()){            // verifica se recebeu algum comando
        charRecebido = Serial.read();    // le o caractere recebido
        switch ( charRecebido ){
            case 'i':                    // inicia coleta
             enviaColeta = 1;
             break;
             
            case 'p':                    // para a coleta
             enviaColeta = 0;
             break;
             
            default:                     // outro comando, ignora...
             break;
        }
    }
    int valor = analogRead(analogInPin);
    temp = (((valor)*5.0)/1023.0)/0.01;
    if ( enviaColeta == 1 ){
        byte valor_byte = valor;
        Serial.write(valor_byte);
    }
    if (temp < 24) {
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        if (t1 == false){
          t1 = true;
          ini1 = millis();
        }
        t2 = false;
        t3 = false;
//            toca1();
    }
    else if (temp >= 24 && temp <= 26){
        digitalWrite(led4, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        t1  =false;
        if (t2 == false){
          t2 = true;
          ini2 = millis();
        }
        t3 = false;
//            toca2();
    }
    else if (temp > 26){
        digitalWrite(led4, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        t1 = false;
        t2 = false;
        if (t3 == false){
          t3 = true;
          ini3 = millis();
        }
//            toca3();
    }
    else {
        t1 = false;
        t2 = false;
        t3 = false;
    }
    
    if(t1) toca1(millis());
    if(t2) toca2(millis());
    if(t3) toca3(millis());
    
    delay(200);
}
