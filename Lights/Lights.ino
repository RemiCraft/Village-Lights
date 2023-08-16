#include <Arduino_FreeRTOS.h>
#include <FastLED.h>
#include "Building.h"

void TestPattern( void *pvParameters );
void BlinkPattern( void *pvParameters );

#define NUM_LEDS 5
#define DATA_PIN 5
#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];

Building buildings[] = {Building("house1", 0, 1), Building("house2", 1, 0), Building("house3", 2, 0)};

void setup()
{
  Serial.begin(9600);
  
  while (!Serial) {;}

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  xTaskCreate(TaskBlink, "BlinkPattern", 128, NULL, 2, NULL);
  xTaskCreate(TaskFastBlink, "FastBlinkPattern", 128, NULL, 2, NULL);
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
    for (int i = 0; i < NUM_LEDS - 2; i++)
    {
      if (buildings[i].GetPattern() == 0)
      {
        leds[i] = CRGB::Red;
        FastLED.show();
        delay(500);
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(500);
      }
    }
  }
}

void TaskFastBlink(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    for (int i = 0; i < NUM_LEDS - 2; i++)
    {
      if (buildings[i].GetPattern() == 1)
      {
        leds[i] = CRGB::Red;
        FastLED.show();
        delay(250);
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(250);
      }
    }
  }
}