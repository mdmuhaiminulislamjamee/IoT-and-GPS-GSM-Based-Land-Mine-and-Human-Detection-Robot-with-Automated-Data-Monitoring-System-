#include <Servo_ESP32.h>
#include <LiquidCrystal_I2C.h>
#include <WiFiClient.h>
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = "FpLDj9dn0zE9Kbewmzwg6kPCTdMarhsE";//Enter your Auth token
char ssid[] = "Open Wifi";//Enter your WIFI name
char pass[] = "ahn@5514";//Enter your WIFI password

// Define component pins
DHT dht(13, DHT11); //(sensor pin,sensor type)
BlynkTimer timer;
Servo_ESP32 servo1;
bool pirbutton = 0;
static const int servoPin = 4;
#define Buzzer 12
#define MQ2 34
#define trig 25
#define echo 26
#define PIR 27

//Get buttons values
BLYNK_WRITE(V0) {
  pirbutton = param.asInt();
}
BLYNK_WRITE(V4) {
  servo1.write(param.asInt());
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  servo1.attach(servoPin);
  pinMode(Buzzer, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(MQ2, INPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Robot Data");
  lcd.setCursor(0, 1);
  lcd.print("Manage System");
  delay(4000);
  lcd.clear();

  //Call the functions
  timer.setInterval(100L, gassensor);
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(100L, pirsensor);
  timer.setInterval(100L, ultrasonic);
}



void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
  //  for (int i = 0; i <= 90; i = i + 3) {
  //    servo1.write(i);
  //    delay(100);
  //  }
  //
  //  for (int i = 90; i >= 0; i = i - 3) {
  //    servo1.write(i);
  //
  //    delay(100);
  //  }
}
