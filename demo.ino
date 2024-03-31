#include "HomeSpan.h"  // HomeSpan sketches always begin by including the HomeSpan library

void setup() {  // Your HomeSpan code should be placed within the standard Arduino setup() function

  Serial.begin(115200);                                      // Start a serial connection so you can receive HomeSpan diagnostics and control the device using HomeSpan's Command-Line Interface (CLI)
  homeSpan.begin(Category::Lighting, "HomeSpan LightBulb");  // initializes a HomeSpan device named "HomeSpan Lightbulb" with Category set to Lighting
  new SpanAccessory();                                       // Begin by creating a new Accessory using SpanAccessory(), no arguments needed
  new Service::AccessoryInformation();                       // HAP requires every Accessory to implement an AccessoryInformation Serviceguments:
  new Characteristic::Identify();                            // Create the required Identify Characteristic
  new Service::LightBulb();                                  // Create the Light Bulb Service
  new Characteristic::On();                                  // This Service requires the "On" Characterstic to turn the light on and off

}  // end of setup()
void loop() {
  homeSpan.poll();  // run HomeSpan!
}  // end of loop()