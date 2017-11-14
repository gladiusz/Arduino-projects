void setup() {
  // put your setup code here, to run once:
  for(int i=1; i<=3; i++)
  pinMode(i, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*digitalWrite(1, HIGH);
digitalWrite(3, LOW);
delay(500);
digitalWrite(2, HIGH);
digitalWrite(1, LOW);
delay(500);
digitalWrite(3, HIGH);
digitalWrite(2, LOW);
delay(500);
*/
for(int i=1; i<=3; i++)
{
digitalWrite(i, HIGH);
if (i==1)
digitalWrite(3, LOW);
else
digitalWrite(i-1, LOW);
delay(500);
}
}
