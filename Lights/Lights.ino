#include <Arduino_FreeRTOS.h>
#include <FastLED.h>
#include <List.hpp>
#include "Building.h"

void TestPattern( void *pvParameters );
void BlinkPattern( void *pvParameters );
void FastBlinkPattern( void *pvParameters );
void FireplacePattern( void *pvParameters );
List<Building> fireplaceBuildings;
List<Building> fastBlinkBuildings;
List<Building> blinkBuildings;
List<Building> newBlinkBuildings;

#define NUM_LEDS 20
#define DATA_PIN 5

#define LED_TYPE WS2812B
#define COLOR_ORDER RGB


CRGB leds[NUM_LEDS];
// Building("name", position, patternID)
Building buildings[] = {
  Building("house1", 0, 2),
  Building("house2", 1, 2),
  Building("house3", 2, 2),
  Building("house4", 3, 2),
  Building("house5", 4, 2),
  Building("house6", 5, 2),
  Building("house7", 6, 2),
  Building("house8", 7, 2),
  Building("house9", 8, 2),
  Building("house10", 9, 2),
  Building("house11", 10, 2),
  Building("house12", 11, 2),
  Building("house13", 12, 2),
  Building("house14", 13, 2),
  Building("house15", 14, 2),
  Building("house16", 15, 2),
  Building("house17", 16, 2),
  Building("house18", 17, 2),
  Building("house19", 18, 2),
  Building("house20", 19, 2),
};

void setup()
{
  Serial.begin(9600);
  
  while (!Serial) {;}

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++)
    {
      if (buildings[i].GetPattern() == 0)
      {
        blinkBuildings.add(buildings[i]);
      }

      if (buildings[i].GetPattern() == 1)
      {
        fastBlinkBuildings.add(buildings[i]);
      }

      if (buildings[i].GetPattern() == 2)
      {
        fireplaceBuildings.add(buildings[i]);
      }

      if (buildings[i].GetPattern() == 3)
      {
        newBlinkBuildings.add(buildings[i]);
      }
    }

  xTaskCreate(TaskBlink, "BlinkPattern", 128, NULL, 2, NULL);
  xTaskCreate(TaskFastBlink, "FastBlinkPattern", 128, NULL, 2, NULL);
  xTaskCreate(Fireplace, "FireplacePattern", 128, NULL, 2, NULL);
  xTaskCreate(TaskNewBlink, "NewBlinkPattern", 128, NULL, 2, NULL);
  //xTaskCreate(TaskTest, "TestPattern", 128, NULL, 2, NULL);
}

void loop()
{
  
}

void TaskTest(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    Serial.println("Pog");
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    Serial.println("Champ");
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}

void TaskBlink(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      if (buildings[i].GetPattern() == 0)
      {
        leds[i] = CRGB::Red;
        FastLED.show();
      }
    }
    vTaskDelay( 500 / portTICK_PERIOD_MS );
    for (int i = 0; i < NUM_LEDS; i++)
    {
      if (buildings[i].GetPattern() == 0)
      {
        leds[i] = CRGB::Black;
        FastLED.show();
      }
    }
    vTaskDelay( 500 / portTICK_PERIOD_MS );
  }
}

void TaskFastBlink(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      if (buildings[i].GetPattern() == 1)
      {
        leds[i] = CRGB::Red;
        FastLED.show();
      }
    }
    vTaskDelay( 250 / portTICK_PERIOD_MS );
    for (int i = 0; i < NUM_LEDS; i++)
    {
      if (buildings[i].GetPattern() == 1)
      {
        leds[i] = CRGB::Black;
        FastLED.show();
      }
    }
    vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}

void TaskNewBlink(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    for(int i = 0; i < newBlinkBuildings.getSize(); i++)
    {
      leds[i] = CRGB::Red;
      FastLED.show();
    }
    vTaskDelay( 500 / portTICK_PERIOD_MS );
    for(int i = 0; i < newBlinkBuildings.getSize(); i++)
    {
      leds[i] = CRGB::Black;
      FastLED.show();
    }
    vTaskDelay( 500 / portTICK_PERIOD_MS );
  }
}

void Fireplace(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    for(int i = 0; i < fireplaceBuildings.getSize(); i++)
    {
      leds[i] = CRGB::Orange;
      FastLED.setBrightness(random(120)+135);
      FastLED.show();
    }
    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}