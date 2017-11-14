void setup() {
  pinMode(13,OUTPUT);
  pinMode(0,INPUT_PULLUP);

}

boolean stan = 0;

void loop() {
  if(digitalRead(0) == LOW){
   delay(20); //opoznienie w przeskoku miedzy stanem niskim i wysokim
    stan = !stan;
    digitalWrite(13,stan);
    while(digitalRead(0) == LOW);
    delay(20);
  }

}
