const int speakerPin = 9;
const bool executarPrograma = true; // Altere para false se não quiser executar o programa

// Frequências das notas musicais (C4 até B4)
const float freqs[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};

// Durações das notas (em milissegundos)
const int duracao[] = {400, 400, 400, 400, 400, 400, 400, 800, 400, 400, 400, 400, 400, 400, 400, 800};

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  if (executarPrograma) {
    for (int i = 0; i < sizeof(freqs) / sizeof(freqs[0]); i++) {
      tone(speakerPin, freqs[i]);
      delay(duracao[i]);
      noTone(speakerPin);
      delay(50); // Pequeno atraso entre as notas
    }
  }
}
