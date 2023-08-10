const int speakerPin = 9;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
float temp = 0.0;
const int analogInPin = A0;  

// Frequências das notas musicais (C4 até B4)
const float freqs1[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
const float freqs2[] = {50, 75, 100, 125, 150, 175, 200};
const float freqs3[] = {100, 200, 250, 275, 300, 312.5, 325};

// Durações das notas (em milissegundos)
const int duracao[] = {400, 400, 400, 400, 400, 400, 400, 800, 400, 400, 400, 400, 400, 400, 400, 800};

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  pinMode(speakerPin, OUTPUT);
  pinMode(analogInPin, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int valor = analogRead(analogInPin);
  temp = (((valor)*5.0)/1023.0)/0.01;
  Serial.read(valor);
  if (temp < 24) {
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    for (int i = 0; i < sizeof(freqs1) / sizeof(freqs1[0]); i++) {
      tone(speakerPin, freqs1[i]);
      delay(duracao[i]);
      noTone(speakerPin);
    }
  }
  else if (temp >= 24 && temp <= 26){
    digitalWrite(led4, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    for (int i = 0; i < sizeof(freqs2) / sizeof(freqs2[0]); i++) {
      tone(speakerPin, freqs2[i]);
      delay(duracao[i]);
      noTone(speakerPin);
    }
  }
   else if (temp > 26){
    digitalWrite(led4, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    for (int i = 0; i < sizeof(freqs3) / sizeof(freqs3[0]); i++) {
      tone(speakerPin, freqs3[i]);
      delay(duracao[i]);
      noTone(speakerPin);
    }
   }
  delay(1000);
}
