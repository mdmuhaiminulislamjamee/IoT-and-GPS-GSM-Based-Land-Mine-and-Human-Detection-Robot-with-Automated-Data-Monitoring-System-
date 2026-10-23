//Get the MQ2 sensor values
void gassensor() {
  int value = analogRead(MQ2);
  Serial.println(value);
  value = map(value, 0, 1024, 0, 100);
  Blynk.virtualWrite(V5, value);
  if (value <= 55) {
    digitalWrite(Buzzer, LOW);
  }
  else if (value > 55) {
    Blynk.notify("Warning! Gas leak detected");
    lcd.clear();
    lcd.print("Air Polluted");
    digitalWrite(Buzzer, HIGH);
    delay(2000);
    lcd.clear();
  }

  lcd.setCursor(0, 0);
  lcd.print("GAS:");
  lcd.print(" ");
  lcd.print(value);
  delay(2000);

}
