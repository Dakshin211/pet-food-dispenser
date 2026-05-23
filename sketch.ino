#include "thingProperties.h"
#include <ESP8266WiFi.h>
#include <time.h>
#include <Servo.h>

#define D2_PIN D2
#define D7_PIN D7
#define SERVO_PIN D4

Servo myServo;

void setup() {

  Serial.begin(115200);

  pinMode(D2_PIN, OUTPUT);
  digitalWrite(D2_PIN, LOW);

  pinMode(D7_PIN, OUTPUT);
  digitalWrite(D7_PIN, LOW);
  myServo.attach(SERVO_PIN);   
  myServo.write(0);           
  delay(1500);

  initProperties();

  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  configTime(0, 0, "pool.ntp.org", "time.nist.gov");

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}


void onLedChange() {
  digitalWrite(D2_PIN, led ? HIGH : LOW);
}


void onServoChange() {

  if (servo) {
    Serial.println("Servo ON → 150 degrees");
    myServo.write(150);
  } else {
    Serial.println("Servo OFF → 0 degrees");
    myServo.write(0);
  }

}


void onLed2Change()  {
  digitalWrite(D7_PIN, led2 ? HIGH : LOW);
}
