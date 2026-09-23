#include <LedControl.h>
// Define pins: DIN, CLK, CS, number of devices (2 matrices)
LedControl lc = LedControl(11, 13, 10, 2);
// Smiley face pattern
byte smiley[8] = {
B00111100,
B01000010,
B10100101,
B10000001,
B10100101,
B10011001,
B01000010,
B00111100
};
// Angry face pattern 😠  (same  as  smiley  but  mouth  flipped)
byte angry[8] = {
B00111100,
B01000010,
B10100101,
B10000001,
B10011001, //inverted from smiley’s 5th row
B10100101, //inverted from smiley’s 6th row
B01000010,
B00111100
};
void setup() {
for (int i = 0; i < 2; i++) {
lc.shutdown(i, false); // Wake up from power-saving
lc.setIntensity(i, 7); // Set brightness
lc.clearDisplay(i);
// Clear display
}
}
void loop() {
displayPattern(0, smiley); // Matrix 0 shows smiley
displayPattern(1, angry); // Matrix 1 shows inverted mouth (angry)
delay(2000);
lc.clearDisplay(0);
lc.clearDisplay(1);
delay(1000);
}
// Reusable function to show 8x8 pattern on a matrix
void displayPattern(int matrix, byte pattern[8]) {
for (int row = 0; row < 8; row++) {
lc.setRow(matrix, row, pattern[row]);
}
}
