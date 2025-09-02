#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// PCA9685のI2Cアドレスを指定 (2つ目のドライバ定義は不要なら削除)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// サーボのパルス幅と周波数を設定
#define SERVOMIN 102  // 最小パルス幅 
#define SERVOMAX 491  // 最大パルス幅 
#define SERVO_FREQ 50 // サーボ用の周波数 (通常は50Hz)

int Servo_Pin = 0;
int angle;

void setup() {
  Serial.begin(9600);
  
  // ドライバを初期化
  pwm.begin();
  // PWM周波数を設定
  pwm.setPWMFreq(SERVO_FREQ);
  
  delay(1000);
}

void loop() {
  
  angle = 0;
  angle = map(angle, 0, 180, SERVOMIN, SERVOMAX);

    // 3つのサーボ (チャンネル0, 1, 2) を同時に動かす
    pwm.setPWM(Servo_Pin, 0, angle);
    pwm.setPWM(1, 0, angle);
    pwm.setPWM(2, 0, angle);
    
    // 動作の速さを調整
    delay(30);
  
  // 180度の位置で1秒待機
  delay(1000);

  // 180度から0度へ移動
  angle = 180;
  angle = map(angle, 0, 180, SERVOMIN, SERVOMAX);

    // 3つのサーボを同時に動かす
    pwm.setPWM(0, 0, angle);
    pwm.setPWM(1, 0, angle);
    pwm.setPWM(2, 0, angle);
    
    delay(30);

  // 0度の位置で1秒待機
  delay(1000);
}