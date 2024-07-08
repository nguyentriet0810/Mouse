void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(4)){
    delay(1);
    if (!digitalRead(4)){
      Serial.println(1);
    }
    while (!digitalRead(4));
  }
} 
