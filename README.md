# Arduino-Button-State-Tracking
# tl;dr
Creates an array holding button states. Includes the function checkButtonStateAndUpdate() that updates the button states. Whilst updating, the function knows that the arduino's code will run many times a second during the time that a button is pressed. So this function prevents multiple changes to a button state during a single press of a button.

This code's void loop() runs this function and toggles the state of two LEDs each time its corresponding button is pressed. This part of the code is not important and is only used to demonstrate that the function is working correctly.

# Long Version
# Problem it Solves
In arduino code, void loop() runs continuously at many thousands of times a second. There will most likely be if statements in this loop that checks if a button has been pressed or not. 

A problem occurs when the user presses down on a button. The user will most likely spend a good 0.5s pressing down on the button (since it takes time for them to remove their finger from the button). However in this time, void loop() will run many, many times (because of the speed of processors). This can cause problems when an if statement is checking to see if a button is being pressed. Because it is checking many, many times and seeing that the button's input is HIGH, the code within the if statement runs many, many times. This is undersirable.

For example, consider a sketch set-up so that with each press of a button, an LED will toggle on or off. If the if statemenet only checks if the button is being pressed at the moment the if statement is run, the LED will toggle many, many times a second with a single press of a button.

This code creates an array holding button states. Then the function checkButtonStateAndUpdate() updates these states whilst considering the problem described. In void loop(), that function is ran and the states of two LEDs are toggled whenever a button is pressed.

# Previous Solutions
Previous attempts to overcome this problem involved setting up another variable that held the previous state of the button. If statements would then check if the current state was HIGH and if the previous state was LOW. If this was the case, it would indicate that a press has just been done; the code would then set the previous state to HIGH. The next time that void loop() is ran, even though the current state would be HIGH, the if statement would see that the previous state was HIGH and so its code would not be run.

This solved the problem however it was believed that this made the code clunky and more difficult to read since these two conditions would have to be checked in every single if statement dealing with button actuation.

This function is reliant on arrays to store a TRUE or FALSE on button actuation. The aim of the function is to change the elements of this array whilst taking into account the problem detailed before. Therefore, any if statements run in void loop() will only have to check the elements of this array and will not have to check for the button's previous state; void checkButtonStates() will have already checked the button's previous state and adjusted the elements accordingly.

This code was created to both learn more about GitHub and to use coding skills gained from uni to create another way of solving this problem
