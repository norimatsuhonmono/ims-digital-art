#include <ESP32Servo.h>

// サーボのインスタンス作成
Servo servo1;

// GPIOピン
const int ServoPin = 5;


void setup() {
  Serial.begin(115200);
  // 0.5ms ~ 2.5ms
  servo1.attach(ServoPin, 500, 2500);
  // 50Hz
  servo1.setPeriodHertz(50);
}

void loop() {
  servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo1.write(90);
  delay(1000);
}