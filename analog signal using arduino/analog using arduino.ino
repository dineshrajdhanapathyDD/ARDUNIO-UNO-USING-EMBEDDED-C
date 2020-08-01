void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop()
{
  int v = analogRead(A0);
  Serial.println(v);
  digitalWrite(7, (1023-v >=1));
  digitalWrite(6,(1023-v >=256));
  digitalWrite(5,(1023-v >=512));
  digitalWrite(4,(1023-v >=1023));

}