
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHT_PIN 15
#define DHT_TYPE DHT22

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* apiKey = "YOUR_WRITE_API_KEY";
const char* universityID = "12219777";

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("University ID: ");
  Serial.println(universityID);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22 sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = "https://api.thingspeak.com/update?api_key=";
    url += apiKey;
    url += "&field1=" + String(temperature, 1);
    url += "&field2=" + String(humidity, 1);

    http.begin(url);
    int httpCode = http.GET();

    Serial.print("ThingSpeak response: ");
    Serial.println(httpCode);

    if (httpCode > 0) {
      Serial.print("Entry ID: ");
      Serial.println(http.getString());
    }

    http.end();
  }

  delay(20000);
}
