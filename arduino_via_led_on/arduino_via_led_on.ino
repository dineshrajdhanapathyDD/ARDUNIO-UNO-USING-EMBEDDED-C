 int led = 2;
 void setup() 
 {
 Serial.begin(9600);
 pinMode(led,OUTPUT); 
}

void loop()
{
  while(!Serial.available());
  byte value = Serial.read();
  switch(value)
  {
    case 'O':
      digitalWrite(led,HIGH);
      break;
    case 'F':
      digitalWrite(led,LOW);
      break;
  }
}
