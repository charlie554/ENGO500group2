int luxpin = 0;
int ledpin = 2;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(luxpin);
  Serial.println(val);

  if( val < 700)
    digitalWrite(ledpin,HIGH);
  else
    digitalWrite(ledpin,LOW);
}
