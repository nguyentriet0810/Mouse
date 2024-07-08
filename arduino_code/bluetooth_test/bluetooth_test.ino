#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(9, 10);
char c;

void setup()
{
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(9600);
}

void loop()
{
  if (Bluetooth.available())
  {
    c = Bluetooth.read();
    Serial.write(c);
  }

  if (Serial.available())
  {
    c = Serial.read();
    Bluetooth.write(c);
  }
  Bluetooth.write("1\n");
  delay(1000);
}