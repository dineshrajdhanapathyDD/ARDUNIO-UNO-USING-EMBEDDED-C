void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}


void blink()
{
  for(int i=0; i<5; i++)
  {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}
  
void loop()
{
  if(Serial.readString() == "blink")
  {
    blink();
  }
    
}