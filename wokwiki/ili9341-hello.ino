/*
  Simple "Hello World" for ILI9341 LCD

  https://wokwi.com/arduino/projects/308024602434470466
*/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10
#define readTempFrom(port) 1 / (log(1 / (1023. / analogRead(A0) - 1)) / BETA + 1.0 / 298.15) - 273.15

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

const float BETA = 3950;

void setup() {
  tft.begin();

  tft.setCursor(26, 120);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Hello, TFT!");

  tft.setCursor(20, 160);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("I can has colors?");

  // Meme reference: https://english.stackexchange.com/questions/20356/origin-of-i-can-haz
}

void loop() {
  //int analogValue = analogRead(A0);
  //float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  float cpuTemp = readTempFrom(A0);
  float intakeTemp = readTempFrom(A1);

  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);  
  
  tft.setCursor(0, 0);
  tft.print("CPU: ");
  tft.println(cpuTemp);

  // tft.setCursor(0, 0);
  tft.print("INTAKE: ");
  tft.println(intakeTemp);
  
  delay(1000);
}