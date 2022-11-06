#include "DHT.h"
#define DHTPIN 0
#define DHTTYPE DHT11
int led1 = 5;
int led2 = 12;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  
  //DHT part
  // Wait a few seconds between measurements.
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity(); // Celsius
  float t = dht.readTemperature(); //Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  return;
  }
  
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  Serial.println("");

  //------------------------------------------------------------------------
  //ldr part
  int ldr = analogRead(A0);
//  Serial.println(ldr);
  float v = 3.3*ldr/1024;
//  Serial.println(v);
  float R = (v*10000.0)/(3.3-v);
  Serial.printf("%f ohm", R);
  Serial.println("");

  if ((int)t > 31 && (int)R > 20000) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
  } else if ((int)t <= 31 && (int)R > 20000) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
  } else {
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
  }
}
