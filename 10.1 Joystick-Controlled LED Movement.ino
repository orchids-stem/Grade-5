#include <LedControl.h>
// LED Matrix pins: DIN, CLK, CS
LedControl lc = LedControl(11, 13, 10, 1);
// Joystick pins
int xPin = A0;
int yPin = A1;
// Dot position
int x = 3;
int y = 3;
void setup() {
lc.shutdown(0, false);// Wake up LED matrix
lc.setIntensity(0, 5);// Set brightness level
lc.clearDisplay(0);// Clear screen
Serial.begin(9600);
}
void loop() {
int xValue = analogRead(xPin); // Horizontal (left-right)
int yValue = analogRead(yPin); // Vertical (up-down)
lc.clearDisplay(0); // Clear display
// --- Fixed logic: ---
// Move Right
if (xValue > 700 && x < 7) {
x++;
Serial.print("xValue= ");
Serial.println(xValue);
Serial.print("x= ");
Serial.println(x);
}
// Move left
else if (xValue < 300 && x > 0) {
x--;
Serial.print("xValue= ");
Serial.println(xValue);
Serial.print("x= ");
Serial.println(x);
}
// Move UP
if (yValue < 300 && y > 0) {
y--;
Serial.print("yValue= ");
Serial.println(yValue);
Serial.print("y= ");
Serial.println(y);
}
// Move DOWN
else if (yValue > 700 && y < 7) {
y++;
Serial.print("yValue= ");
Serial.println(yValue);
Serial.print("y= ");
Serial.println(y);
}
lc.setLed(0, y, x, true); // Turn on LED at (x, y)
delay(200); // debounce delay
}
