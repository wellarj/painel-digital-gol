// Defina os pinos dos sensores
const int pinVelocidade = A0;
const int pinContaGiros = A1;
const int pinNivelCombustivel = A2;
const int pinTemperaturaMotor = A3;

void setup() {
  Serial.begin(9600);  // Inicia a comunicação Serial
}

void loop() {
  // Lê os valores dos sensores
  int velocidade = analogRead(pinVelocidade);
  int contaGiros = analogRead(pinContaGiros);
  int nivelCombustivel = analogRead(pinNivelCombustivel);
  int temperaturaMotor = analogRead(pinTemperaturaMotor);

  // Converte os valores para uma escala desejada (opcional)
  velocidade = map(velocidade, 0, 1023, 0, 200);  // mapeia para 0-200 km/h
  contaGiros = map(contaGiros, 0, 1023, 0, 8000);  // mapeia para 0-8000 rpm
  nivelCombustivel = map(nivelCombustivel, 0, 1023, 0, 100);  // mapeia para 0-100%
  temperaturaMotor = map(temperaturaMotor, 0, 1023, 0, 120);  // mapeia para 0-120°C

  // Envia os dados para o painel (Serial)
  Serial.print("velocidade:");
  Serial.print(velocidade);
  Serial.print(",contaGiros:");
  Serial.print(contaGiros);
  Serial.print(",nivelCombustivel:");
  Serial.print(nivelCombustivel);
  Serial.print(",temperaturaMotor:");
  Serial.println(temperaturaMotor);

  delay(1000);  // Atualiza a cada 1000 milissegundos (1 segundo)
}
