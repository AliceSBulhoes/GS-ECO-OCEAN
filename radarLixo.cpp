// Importando as bibliotecas necessárias
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Inicializa o objeto para controlar o display LCD I2C
LiquidCrystal_I2C lcd(0x27, 20, 4);

int ledR = 13;
int ledG = 12;

float distancia_cm;

// Função para medir a distância usando o sensor ultrassônico
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Define o ledG como pino de saída;
  pinMode(ledG, OUTPUT);
  // Define o ledR como pino de saída;
  pinMode(ledR, OUTPUT);

  // Inicializa o display LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Calcula a distância em centímetros
  distancia_cm = 0.0344 / 2 * readUltrasonicDistance(3, 2);

  // Se a distância for maior ou igual a 15 cm
  if (distancia_cm > 20){
    // Exibe que nada foi encontrado próximo ao sensor
    lcd.print("Nada detectado!");
    
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);

  }else{
    // Exibe que foi encontrado um objeto próximo ao sensor
    lcd.print("Lixo detectado!");
    
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);

    // Exibe a mensagem no display LCD
    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.print(distancia_cm);
    lcd.print("cm");
  }

  // Aguarda 2 segundos
  delay(2000);

  // Limpa o display LCD
  lcd.clear();
}
