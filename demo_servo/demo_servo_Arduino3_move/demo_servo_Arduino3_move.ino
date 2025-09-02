#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// PCA9685のI2Cアドレスを指定
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// サーボのパルス幅と周波数を設定
#define SERVOMIN 102  // 最小パルス幅 (0度に対応)
#define SERVOMAX 491  // 最大パルス幅 (180度に対応)
#define SERVO_FREQ 50 // サーボ用の周波数 (通常は50Hz)

void setup() {
  // シリアル通信を開始 (ボーレート: 9600)
  Serial.begin(9600);
  Serial.println("サーボ制御を開始します。");
  Serial.println("「1」を入力: 最大位置 (180度)");
  Serial.println("「2」を入力: 最小位置 (0度)");
  
  // ドライバを初期化
  pwm.begin();
  // PWM周波数を設定
  pwm.setPWMFreq(SERVO_FREQ);
  delay(1000);
}

void loop() {
  // シリアルポートにデータが送信されているか確認
  if (Serial.available() > 0) {
    // 送信された文字を読み込む
    char command = Serial.read();

    // コマンドが '1' の場合
    if (command == '1') {
      Serial.println("最大位置へ移動します。");
      // 3つのサーボ (チャンネル0, 1, 2) を同時に最大値へ動かす
      pwm.setPWM(0, 0, SERVOMAX);
      pwm.setPWM(1, 0, SERVOMAX);
      pwm.setPWM(2, 0, SERVOMAX);
    }
    // コマンドが '2' の場合
    else if (command == '2') {
      Serial.println("最小位置へ移動します。");
      // 3つのサーボ (チャンネル0, 1, 2) を同時に最小値へ動かす
      pwm.setPWM(0, 0, SERVOMIN);
      pwm.setPWM(1, 0, SERVOMIN);
      pwm.setPWM(2, 0, SERVOMIN);
    }
  }
}