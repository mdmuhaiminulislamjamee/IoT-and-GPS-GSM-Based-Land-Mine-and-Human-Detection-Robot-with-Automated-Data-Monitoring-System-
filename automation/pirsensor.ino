//Get the PIR sensor values
void pirsensor() {
  bool value = digitalRead(PIR);
  //Blynk.virtualWrite(V0, value);
  if (pirbutton == 1) {
    if (value == 1) {
      Blynk.notify("Life Found");
      digitalWrite(Buzzer, HIGH);
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Life Found!");
      delay(1000);
      lcd.clear();

    } else if (value == 0) {
      lcd.clear();
      digitalWrite(Buzzer, LOW);
    }
  }
}
