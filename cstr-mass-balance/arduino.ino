#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 3
#define DHTTYPE DHT22
#define MQ3_PIN A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  pinMode(MQ3_PIN, INPUT);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Sensors ready");
  display.display();
  delay(1000);
}

void loop() {
  float tempC = dht.readTemperature();
  float hum = dht.readHumidity();
  int alcoholRaw = analogRead(MQ3_PIN);

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" C, Hum: ");
  Serial.print(hum);
  Serial.print(" %, Alcohol Raw: ");
  Serial.println(alcoholRaw);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temperature: ");
  display.print(tempC);
  display.println(" C");

  display.print("Humidity: ");
  display.print(hum);
  display.println(" %");

  display.print("Alcohol: ");
  display.println(alcoholRaw);

  display.display();

  delay(1000);
}
