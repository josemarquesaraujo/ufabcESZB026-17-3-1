const int potPin = A0;   // Pino do potenciômetro
const int ledPin = 9;    // Pino do LED (pode variar dependendo do modelo do Arduino)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Inicia a comunicação serial com uma taxa de 9600 bps
}

void loop() {
  int potValue = analogRead(potPin);  // Lê o valor analógico do potenciômetro
  int brightness = map(potValue, 0, 1023, 0, 255);  // Mapeia o valor para a faixa de brilho (0 a 255)

  analogWrite(ledPin, brightness);  // Define o brilho do LED

  float voltage = brightness * (5.0 / 255.0);  // Calcula a tensão fornecida ao LED (supondo uma alimentação de 5V)

  Serial.print("Tensão LED: ");
  Serial.print(voltage, 2);  // Exibe a tensão com 2 casas decimais
  Serial.println(" V");

  delay(10);  // Pequena pausa para estabilidade
}
