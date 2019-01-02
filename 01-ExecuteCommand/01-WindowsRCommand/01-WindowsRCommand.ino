#include "Keyboard.h"
#include "Mouse.h"

#define startDelay 1000
#define defaultDelay 100
#define defaultCharDelay 5

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}
void typeLine(String line){
  Keyboard.print(line);
  delay(defaultDelay);
  typeKey(KEY_RETURN);
  delay(defaultDelay);
}
void save(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(115);
  Keyboard.releaseAll();
  delay(defaultDelay);
}
void closeWindows(){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  delay(defaultDelay);
}
void windowsR(String command){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();
  delay(defaultDelay);
  Keyboard.print(command);
  delay(defaultDelay);
  typeKey(KEY_RETURN);
  delay(defaultDelay);
}
void escape(){
  typeKey(KEY_ESC);
  delay(defaultDelay);
}
void setup(){
  
  pinMode(6,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
  
  if(digitalRead(6) == LOW){
    Keyboard.begin();
    Mouse.begin();

    delay(startDelay);
    escape();
    /* ----- Begin-Script -----*/
    windowsR("ipconfig");
    /* ----- End-Script -----*/
    
    Keyboard.end();
  }
}

void loop(){
  digitalWrite(3,LOW);
  delay(defaultDelay);
  digitalWrite(3,HIGH);
  delay(defaultDelay);
}
