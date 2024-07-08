#include <TimerOne.h>
#include <SoftwareSerial.h>
#include <OneButton.h>

#define phim 4

const int x = A0;
const int y = A1;

int xh, yh;
int xcord, ycord;
int tt;

class Button{
private:
  OneButton button;
  int value;
public:
  explicit Button(uint8_t pin):button(pin) {
    button.attachClick([](void *scope) { ((Button *) scope)->Clicked();}, this);
    button.attachDoubleClick([](void *scope) { ((Button *) scope)->DoubleClicked();}, this);
    button.attachLongPressStart([](void *scope) { ((Button *) scope)->LongPressed();}, this);
  }

  void Clicked(){
    //Serial.println("Click then value++");
    tt = 1;
    //Serial.println(tt);
  }

  void DoubleClicked(){
    //Serial.println("DoubleClick");
    tt = 2;
    //Serial.println(tt);
  }

  void LongPressed(){
    //Serial.println("LongPress and the value is");
    tt = 3;
    //Serial.println(tt);
  }

  void handle(){
    button.tick();
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(phim, INPUT_PULLUP);
  delay(1000);
}

Button button(phim);

void loop() {
  button.handle();
  xh = analogRead(x);
  yh = analogRead(y);
  xcord = (xh)/100;
  ycord = (yh)/100;

  String S = (String)(ycord) + '/' + (String)(xcord) + '/' + (String)(tt);
  Serial.println(S);
  delay(1);
  tt = 0;
}



