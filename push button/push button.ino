void setup()
{
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
}

void loop()
{
  if (digitalRead(8) == HIGH)
  {
    digitalWrite(13, HIGH);
    delay(5000);
    digitalWrite(13, LOW);
}
}