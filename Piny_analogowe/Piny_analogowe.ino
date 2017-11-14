void setup() {
  Serial.begin(9600);
  while(!Serial);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  float odczyt = analogRead(A0)/1024.00*5;
  if (odczyt > 4.00)
    digitalWrite(13, HIGH);
    else digitalWrite(13, LOW);
  Serial.println(odczyt);
  //delay(1000);
}
