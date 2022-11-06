int led = 5;
char a;
char b;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    Serial.println(Serial.available());
    a = Serial.read();
    b = Serial.read();
  }
  
  if (a == 'a') {
    digitalWrite(led, 1);
    delay(500);
    digitalWrite(led, 0);
    delay(500);
  } else if (a == 'b') {
    digitalWrite(led, 0);
    delay(500);
  }
}
