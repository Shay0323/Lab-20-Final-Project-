#include <U8g2lib.h>

// OLED Display setup (I2C)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Button pin 
const int buttonPin = 4;

// 8-Ball responses
const char* responses[] = {
  "Yes", "No", "Maybe", "Definitely", "Ask again",
};
const int numResponses = sizeof(responses) / sizeof(responses[0]);

void setup() {
  pinMode(buttonPin, INPUT);
  u8g2.begin();
  randomSeed(analogRead(0)); // Seed for randomness

  displayMessage("Press Button");
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Button is active LOW
    int randomIndex = random(0, numResponses);
    displayMessage(responses[randomIndex]);
    delay(5000); // Show response for 5 seconds
    displayMessage("Press again");
  }
}
void displayMessage(const char* msg) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(10, 30, msg);
  u8g2.sendBuffer();
}