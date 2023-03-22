#include <DHT.h>

#define DHTPIN 2     // El pin digital conectado al sensor
#define DHTTYPE DHT11   // Tipo de sensor utilizado (DHT11 o DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Lectura de la humedad relativa y la temperatura en grados Celsius
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verificación si la lectura fue correcta o no
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer el sensor DHT11");
    return;
  }

  // Imprimir los valores en el monitor serie
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println("°C");

  delay(2000);  // Esperar 2 segundos antes de volver a leer el sensor
}

