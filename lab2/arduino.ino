#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int ldrPin = A0;

void setup() {
  Serial.begin(9600);

  sensors.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Sensors ready");
  display.display();
  delay(1000);
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float tempK = tempC + 273.15;

  int lightValue = analogRead(ldrPin);  // 0–1023

  Serial.print("Temp:");
  Serial.print(tempC);
  Serial.print(",Light:");
  Serial.println(lightValue);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(tempC);
  display.println(" C");
  display.print("Light: ");
  display.println(lightValue);
  display.display();

  delay(1000);
}
