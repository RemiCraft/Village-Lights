#include <Arduino_FreeRTOS.h>
#include <FastLED.h>
#include "Building.h"

void TestPattern( void *pvParameters );
void BlinkPattern( void *pvParameters );

#define NUM_LEDS 3
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

Building *buildings[] = {("house1", 0, 0), ("house2", 1, 0), ("house3", 2, 0)};

void setup()
{
  Serial.begin(9600);
  
  while (!Serial) {;}

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  xTaskCreate(TaskBlink, "BlinkPattern", 128, NULL, 2, NULL);
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
      if (buildings[i]->GetPattern() == 0)
      {
        leds[0] = CRGB::Red;
        FastLED.show();
        delay(500);
        leds[0] = CRGB::Black;
        FastLED.show();
        delay(500);
      }
    }
  }
}