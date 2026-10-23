//Get the ultrasonic sensor values
void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  long distance = duration * 0.034 / 2;
  Blynk.virtualWrite(V1, distance);

  if (distance < 25) {
    Blynk.notify("Warning! Obstacle Found");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Danger!Obstacle");
    digitalWrite(Buzzer, HIGH);
    delay(5000);
    lcd.clear();

  }
  else {

    lcd.setCursor(8, 1);
    lcd.print("DIST:");
    lcd.print(distance);
    lcd.print("  ");
  }
}
