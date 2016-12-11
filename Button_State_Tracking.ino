const int buttonPins[] = {2 , 3};
boolean buttonStates[] = {LOW , LOW , LOW};
boolean oldButtonStates[] = {LOW , LOW , LOW};

const int LEDPins[] = {8 , 7};
boolean LEDStates[] = {LOW, LOW};
const int noOfButtons = 2;

void checkButtonStateAndUpdate() {
  for(int i = 0; i < noOfButtons; i++) {
    if(digitalRead(buttonPins[i])) {
      if(!oldButtonStates[i]) {
        buttonStates[i] = HIGH;
        oldButtonStates[i] = HIGH;
      }
      else
        buttonStates[i] = LOW;  //ie this line will run when oldButtonStates == HIGH 
    }
    else {                      //ie when digitalRead(buttonPins[0])==LOW
      oldButtonStates[i] = LOW;
      buttonStates[i] = LOW;
    }
  }
}

void setup() {
  for(int i = 0; i < noOfButtons; i++)
    pinMode(LEDPins[i], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButtonStateAndUpdate();
  for(int i = 0; i < noOfButtons; i++) {
    if(buttonStates[i])
      LEDStates[i] = !LEDStates[i];
    digitalWrite(LEDPins[i], LEDStates[i]);
  }
  Serial.println(digitalRead(buttonPins[0]));
}

