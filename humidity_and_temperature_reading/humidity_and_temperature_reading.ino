#include <LiquidCrystal.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_PIN 7
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("H: ");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(temperature);
  lcd.print("C");

  delay(5000);
}
