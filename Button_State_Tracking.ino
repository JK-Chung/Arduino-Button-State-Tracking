const int buttonPins[] = {2 , 3};             //The pins that the buttons are connected to
boolean buttonStates[] = {LOW , LOW , LOW};   //Stores the state of the buttons and is updated by the checkButtonStateAndUpdate() function
boolean oldButtonStates[] = {LOW , LOW , LOW};//Stores the old state of the buttons; only used by the checkButtonStateAndUpdate() function

const int LEDPins[] = {8 , 7};                //The pins that the LEDs are connected to
boolean LEDStates[] = {LOW, LOW};             //Stores the states that the LEDs should hold (not necessary to the function)
const int noOfButtons = 2;                    //This should also equal the number of LEDs to be toggled

void checkButtonStateAndUpdate() {
/*   For-loop runs the code for every button state that needs updating
 *   Requires that the index of a buttonPin is the same index for that button's
 *   buttonState and oldButtonState in their respective arrays */
 for(int i = 0; i < noOfButtons; i++) {
  if(digitalRead(buttonPins[i])) {
      if(!oldButtonStates[i]) {               //Nested if statement checks the button's old state to see whether a change is necessary
        buttonStates[i] = HIGH;               //When oldButtonStates is LOW, this indicates that the code is being run for the first time since the button was pressed
        oldButtonStates[i] = HIGH;            //So oldButtonStates[i] is set to HIGH as well
      }
      else
        buttonStates[i] = LOW;                //Runs when oldButtonStates[i] is HIGH so buttonStates should be set to LOW so that the code run when buttonStates is HIGH is not run again
    }
    else {                                    //Runs when the button is no longer pressed, so oldButtonStates[i] and buttonStates[i] are reset
      oldButtonStates[i] = LOW;
      buttonStates[i] = LOW;
    }
  }
}

void setup() {
  for(int i = 0; i < noOfButtons; i++)
    pinMode(LEDPins[i], OUTPUT);
}

void loop() {
  checkButtonStateAndUpdate();
  for(int i = 0; i < noOfButtons; i++) {
    if(buttonStates[i])
      LEDStates[i] = !LEDStates[i];
    digitalWrite(LEDPins[i], LEDStates[i]);
  }
}

