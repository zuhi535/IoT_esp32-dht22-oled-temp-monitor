#include "DHT.h"
#include "Adafruit_Sensor.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN      25
#define DHTTYPE     DHT22
DHT dht(DHTPIN, DHTTYPE);

// LCD/ OLED kijelző beállítások
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // ha nincs reset láb
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LED_GREEN   14
#define LED_YELLOW  27
#define LED_RED     26

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 + OLED + LED vezérlés");

  dht.begin();

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C az I2C cím
    Serial.println(F("SSD1306 kijelző nem inicializálható"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Kezdetben
  display.setCursor(0,0);
  display.println("Kezdes...");
  display.display();
}

void loop() {
  delay(2000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Hőmérséklet: "); Serial.print(t); Serial.println(" °C");
  Serial.print("Páratartalom: "); Serial.print(h); Serial.println(" %");

  // LED vezérlés:
  if (t < 20) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  }
  else if (t >= 20 && t <= 30) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
  }
  else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }

  // Kijelző frissítés:
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(t);
  display.println(" C");
  display.print("Hum:  ");
  display.print(h);
  display.println(" %");
  display.display();
}
