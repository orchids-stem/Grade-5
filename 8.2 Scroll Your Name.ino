#include <Adafruit_GFX.h>// Graphics library for drawing text and shapes
#include <Max72xxPanel.h>// Library to control MAX7219 LED matrix modules
// Matrix configuration
int pinCS = 10;
// Chip Select pin connected to Arduino digital pin 10
Max72xxPanel matrix = Max72xxPanel(pinCS, 2, 1); // 2 matrices horizontally, 1 row vertically
// Message and timing setup
String tape = " Robotics ";
int scrollDelay = 70;
// Text to scroll across the LED matrices
// Delay (in milliseconds) between scroll steps
int charWidth = 6;
// Width of each character including 1 pixel spacing
unsigned long prevScrollMillis = 0; // Tracks the last scroll time
int scrollIndex = 0;
// Tracks the scroll position
void setup() {
// Initialize LED matrix settings
matrix.setIntensity(8);// Set brightness level (0 to 15)
matrix.setRotation(0, 2);// Rotate first matrix (0 = leftmost) by 180 degrees
matrix.setRotation(1, 2);// Rotate second matrix by 180 degrees
}
void loop() {
unsigned long currentMillis = millis(); // Get current time in milliseconds
// Check if it’s time to scroll
if (currentMillis - prevScrollMillis >= scrollDelay) {
prevScrollMillis = currentMillis; // Update last scroll time
matrix.fillScreen(LOW);
// Clear the LED matrix
int x = matrix.width() - scrollIndex; // Calculate starting X position for scrolling
matrix.setCursor(x, 0);
matrix.print(tape);
// Set cursor position
// Print the message
matrix.write();// Update the display
scrollIndex++;// Move scroll position
// Reset scroll index once full message has moved off screen
int totalLength = tape.length() * charWidth;
if (scrollIndex > totalLength + matrix.width()) {
scrollIndex = 0;
// Restart scrolling from beginning
}
}
}
