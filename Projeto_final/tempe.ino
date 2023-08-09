const int speakerPin = 9;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int analogInPin = A0;  

// Frequências das notas musicais (C4 até B4)
const float freqs[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};

// Durações das notas (em milissegundos)
const int duracao[] = {400, 400, 400, 400, 400, 400, 400, 800, 400, 400, 400, 400, 400, 400, 400, 800};

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(analogInPin, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  digitalWrite(led4, HIGH);
  int valor = analogRead(analogInPin);
  temp = (((valor*256.0)*5.0)/1023.0)/0.01;
  if (temp >= 25) {
    digitalWrite(led2, HIGH);
    digitalWrite(led4, LOW);
    for (int i = 0; i < sizeof(freqs) / sizeof(freqs[0]); i++) {
      tone(speakerPin, freqs[i]);
      delay(duracao[i]);
      noTone(speakerPin);
      delay(50); // Pequeno atraso entre as notas
    }
  }
}
