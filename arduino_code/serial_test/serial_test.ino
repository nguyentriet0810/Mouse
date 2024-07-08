#include <string.h>

int x, y, click = 0;
String send;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
  x++;
  if (x > 1920) {
    y = y + 100;
    x = 0;
  }
  if (y > 1080)
    y = 0;

  send = String(x) + "/" + String(y) + "/" + String(click);
  Serial.println(send);
}