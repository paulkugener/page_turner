#include <BleKeyboard.h>

#define BUTTON_UP 17
#define BUTTON_DOWN 18
// Variables will change:
//int lastStateUp = HIGH; 
int currentStateUp;
//int lastStateDown = HIGH; 
int currentStateDown;

BleKeyboard bleKeyboard;

void setup() {
  //Serial.begin(115200);
  //Serial.println("Starting BLE work!");picadilly
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  bleKeyboard.begin();
  //Serial.println("setup done");
}

void loop() {
  if(bleKeyboard.isConnected()) {
    currentStateUp = digitalRead(BUTTON_UP); 
    currentStateDown = digitalRead(BUTTON_DOWN);

    if (currentStateUp == LOW) {
      //Serial.println("Scroll Up");
      bleKeyboard.write(218); // up button
      delay(500);
    }
    if (currentStateDown == LOW) {
      //Serial.println("Scroll Down");
      bleKeyboard.write(217); // down button
      delay(500);
    }
    bleKeyboard.releaseAll();
  }
  delay(100);
}
