// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
#define LED_PIN 2
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // turn the LED on
  delay(500);             // wait for 500 milliseconds
  digitalWrite(LED_PIN, LOW);  // turn the LED off
  delay(500);             // wait for 500 milliseconds
} 