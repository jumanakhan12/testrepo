#include <DHT.h>

#define DHTPIN 5         // Change to the pin you’re testing (e.g., 5 for D1 on ESP8266)
#define DHTTYPE DHT11    // Change to DHT22 if you have a DHT22 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting DHT sensor test...");
  dht.begin();
  delay(3000); // Increased delay to allow sensor to stabilize
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print for Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" °C, Humidity: ");
    Serial.print(hum);
    Serial.println(" %");

    // Print for Serial Plotter
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print("\t");       // Tab-separated values for easy plotting
    Serial.print("Humidity: ");
    Serial.println(hum);
  }
  delay(3000); // Wait 3 seconds before the next reading
}
