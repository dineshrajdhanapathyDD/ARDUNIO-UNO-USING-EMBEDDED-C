volatile char state = LOW;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), button_changed, CHANGE);
}

void button_changed()
{
  state = !state;
}
void loop()
{
  digitalWrite(13, state);
}