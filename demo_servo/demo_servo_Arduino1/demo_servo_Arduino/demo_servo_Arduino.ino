#include <Wire.h>                     // ライブラリのインクルード
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);  // PCA9685のI2Cアドレスを指定
 
#define SERVOMIN 500    // 最小パルス幅(μs)
#define SERVOMAX 2400   // 最大パルス幅(μs)
 
 
int Servo_pin = 0;      // サーボ接続ピンを0番に
int angle;
 
void setup() {
 
  pwm.begin();         // 初期設定
  pwm.setPWMFreq(50);  // PWM周期を50Hzに設定
  delay(1000);
  
}
 
void loop() {
  
  angle = 0;
  angle = map(angle,0, 180, SERVOMIN, SERVOMAX);  // 角度(0~180)をパルス幅(500~2400μs)に変換
  pwm.writeMicroseconds(Servo_pin, angle);        // サーボを動作させる
  delay(1000);
 
  angle = 180;
  angle = map(angle,0, 180, SERVOMIN, SERVOMAX);
  pwm.writeMicroseconds(Servo_pin, angle);
  delay(1000);
 
}