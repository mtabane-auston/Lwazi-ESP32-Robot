#include <Arduino.h>
#include <Wire.h>

#define MOTOR_A_IN1 25
#define MOTOR_A_IN2 26
#define MOTOR_B_IN3 27
#define MOTOR_B_IN4 14

#define PWM_FREQ    5000
#define PWM_RES     8
#define CH_A1       0
#define CH_A2       1
#define CH_B1       2
#define CH_B2       3

void scanI2c(){
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknow error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }

}


void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  
  ledcSetup(CH_A1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_A2, PWM_FREQ, PWM_RES);
  ledcSetup(CH_B1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_B2, PWM_FREQ, PWM_RES);

  ledcAttachPin(MOTOR_A_IN1, CH_A1);
  ledcAttachPin(MOTOR_A_IN2, CH_A2);
  ledcAttachPin(MOTOR_B_IN3, CH_B1);
  ledcAttachPin(MOTOR_B_IN4, CH_B2);

  Serial.println("Motors ready");

  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");

  scanI2c();

}

void motorA(int speed) {

  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    ledcWrite(CH_A1, speed);
    ledcWrite(CH_A2, 0);
  } else if (speed < 0) {
    ledcWrite(CH_A1, 0);
    ledcWrite(CH_A2, -speed);
  } else {
    ledcWrite(CH_A1, 0);
    ledcWrite(CH_A2, 0);
  }
}

void motorB(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    ledcWrite(CH_B1, speed);
    ledcWrite(CH_B2, 0);
  } else if (speed < 0) {
    ledcWrite(CH_B1, 0);
    ledcWrite(CH_B2, -speed);
  } else {
    ledcWrite(CH_B1, 0);
    ledcWrite(CH_B2, 0);
  }
}

void loop() {
  digitalWrite(2,HIGH);
  Serial.println("Forward");
  motorA(250);
  motorB(250);
  delay(2000);

  Serial.println("Stop");
  motorA(0);
  motorB(0);
  delay(3000);

  Serial.println("Reverse");
  motorA(-250);
  motorB(-250);
  delay(2000);

  Serial.println("Stop");
  motorA(0);
  motorB(0);
  delay(3000);

  Serial.println("Turn left");
  motorA(-250);
  motorB(250);
  delay(1000);

  Serial.println("Stop");
  motorA(0);
  motorB(0);
  delay(5000);
}