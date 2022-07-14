 
#include <XInput.h>

 
 
const boolean UseLeftJoystick   = true;   
const boolean InvertLeftYAxis   = false;  

const boolean UseRightJoystick  = true;  
const boolean InvertRightYAxis  = false; 

const boolean UseTriggerButtons = true;   

const int ADC_Max = 1023;  // 10 bit
 
const int Pin_LeftJoyX  = A0;
const int Pin_LeftJoyY  = A1;
const int Pin_RightJoyX = A2;
const int Pin_RightJoyY = A3;
 
const int Pin_TriggerL = 1;
const int Pin_TriggerR = 9;
 
const int Pin_ButtonA = 15;
const int Pin_ButtonB = 16;
const int Pin_ButtonX = 14;
const int Pin_ButtonY = 10;

const int Pin_ButtonLB = 0;
const int Pin_ButtonRB = 8;

const int Pin_ButtonL3 = 6;
const int Pin_ButtonR3 = 7;

const int Pin_DpadUp    = 2;
const int Pin_DpadDown  = 3;
const int Pin_DpadLeft  = 4;
const int Pin_DpadRight = 5;
 
void setup() {
  if (UseTriggerButtons == true) {
    pinMode(Pin_TriggerL, INPUT_PULLUP);
    pinMode(Pin_TriggerR, INPUT_PULLUP);
  }
 
  else {
    XInput.setTriggerRange(0, ADC_Max);
  }

 
  pinMode(Pin_ButtonA, INPUT_PULLUP);
  pinMode(Pin_ButtonB, INPUT_PULLUP);
  pinMode(Pin_ButtonX, INPUT_PULLUP);
  pinMode(Pin_ButtonY, INPUT_PULLUP);

  pinMode(Pin_ButtonLB, INPUT_PULLUP);
  pinMode(Pin_ButtonRB, INPUT_PULLUP);

  pinMode(Pin_ButtonL3, INPUT_PULLUP);
  pinMode(Pin_ButtonR3, INPUT_PULLUP);

  pinMode(Pin_DpadUp, INPUT_PULLUP);
  pinMode(Pin_DpadDown, INPUT_PULLUP);
  pinMode(Pin_DpadLeft, INPUT_PULLUP);
  pinMode(Pin_DpadRight, INPUT_PULLUP);

  XInput.setJoystickRange(0, ADC_Max); 
  XInput.setAutoSend(false); 

  XInput.begin();
}

void loop() {

 
 
  boolean buttonA = !digitalRead(Pin_ButtonA);
  boolean buttonB = !digitalRead(Pin_ButtonB);
  boolean buttonX = !digitalRead(Pin_ButtonX);
  boolean buttonY = !digitalRead(Pin_ButtonY);

  boolean buttonLB = !digitalRead(Pin_ButtonLB);
  boolean buttonRB = !digitalRead(Pin_ButtonRB);

  boolean buttonL3 = !digitalRead(Pin_ButtonL3);
  boolean buttonR3 = !digitalRead(Pin_ButtonR3);

  boolean dpadUp    = !digitalRead(Pin_DpadUp);
  boolean dpadDown  = !digitalRead(Pin_DpadDown);
  boolean dpadLeft  = !digitalRead(Pin_DpadLeft);
  boolean dpadRight = !digitalRead(Pin_DpadRight);

 
  boolean button_start = buttonB && dpadRight;
  boolean button_back = buttonB && dpadLeft;

  XInput.setButton(BUTTON_A, buttonA);
  XInput.setButton(BUTTON_B, buttonB);
  XInput.setButton(BUTTON_X, buttonX);
  XInput.setButton(BUTTON_Y, buttonY);

  XInput.setButton(BUTTON_LB, buttonLB);
  XInput.setButton(BUTTON_RB, buttonRB);

  XInput.setButton(BUTTON_L3, buttonL3);
  XInput.setButton(BUTTON_R3, buttonR3);
  XInput.setButton(BUTTON_START, button_start);
  XInput.setButton(BUTTON_BACK, button_back);

  XInput.setDpad(dpadUp, dpadDown, dpadLeft, dpadRight);

 
  if (UseTriggerButtons == true) {
 
    boolean triggerLeft  = !digitalRead(Pin_TriggerL);
    boolean triggerRight = !digitalRead(Pin_TriggerR);
 
    XInput.setButton(TRIGGER_LEFT, triggerLeft);
    XInput.setButton(TRIGGER_RIGHT, triggerRight);
  }
  else {
 
    int triggerLeft  = analogRead(Pin_TriggerL);
    int triggerRight = analogRead(Pin_TriggerR);

 
    XInput.setTrigger(TRIGGER_LEFT, triggerLeft);
    XInput.setTrigger(TRIGGER_RIGHT, triggerRight);
  }
 
  if (UseLeftJoystick == true) {
    int leftJoyX = analogRead(Pin_LeftJoyX);
    int leftJoyY = analogRead(Pin_LeftJoyY);
    boolean invert = !InvertLeftYAxis;

    XInput.setJoystickX(JOY_LEFT, leftJoyX);
    XInput.setJoystickY(JOY_LEFT, leftJoyY, invert);
  }

 
  if (UseRightJoystick == true) {
    int rightJoyX = analogRead(Pin_RightJoyX);
    int rightJoyY = analogRead(Pin_RightJoyY);

    boolean invert = !InvertRightYAxis;

    XInput.setJoystickX(JOY_RIGHT, rightJoyX);
    XInput.setJoystickY(JOY_RIGHT, rightJoyY, invert);
  }

  XInput.send();
}

 
