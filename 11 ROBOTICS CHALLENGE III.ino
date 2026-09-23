#include <Adafruit_GFX.h>      // Graphics library (required for Max72xxPanel)
#include <Max72xxPanel.h>      // Library to control 8x8 LED matrices using MAX7219

// ----------------------------
// Matrix configuration
// ----------------------------
const int pinCS = 10;           // Chip Select pin for MAX7219
const int numHorizontal = 2;    // Number of matrices chained horizontally (2 × 8 = 16 columns)
const int numVertical = 1;      // Only 1 row of matrices (8 rows total)
Max72xxPanel matrix = Max72xxPanel(pinCS, numHorizontal, numVertical);

// ----------------------------
// Joystick configuration
// ----------------------------
const int xPin = A0;            // Joystick X-axis (horizontal movement)
const int yPin = A1;            // Joystick Y-axis (vertical movement)
const int buttonPin = 2;        // Joystick button (center press)
const int resetPin = 3;         // External button to clear display

// ----------------------------
// Cursor and display state
// ----------------------------
int x = 0;                      // Cursor column (0 to 15)
int y = 0;                      // Cursor row (0 to 7)
bool ledState[8][16] = {0};     // Stores ON/OFF state for each pixel

void setup() {
  matrix.setIntensity(8);        // Set brightness level (0 = dim, 15 = bright)
  matrix.setRotation(0, 2);      // Rotate matrix 0 (left one) 180°
  matrix.setRotation(1, 2);      // Rotate matrix 1 (right one) 180°

  matrix.fillScreen(LOW);        // Clear all LEDs initially
  matrix.write();                // Apply the cleared screen to display

  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up for joystick button
  pinMode(resetPin, INPUT_PULLUP);   // Enable internal pull-up for reset button
  Serial.begin(9600);                // Start Serial Monitor (optional for debugging)
}

void loop() {
  int xValue = analogRead(xPin);    // Read horizontal axis
  int yValue = analogRead(yPin);    // Read vertical axis

  // ----------------------------
  // Joystick movement logic
  // ----------------------------

  // Move cursor left
  if (xValue < 400 && x > 0) {
    x--;
    delay(150); // Delay to avoid skipping too fast
  }
  // Move cursor right
  else if (xValue > 600 && x < 15) {
    x++;
    delay(150);
  }

  // Move cursor up
  if (yValue < 400 && y > 0) {
    y--;
    delay(150);
  }
  // Move cursor down
  else if (yValue > 600 && y < 15) {
    y++;
    delay(150);
  }

  // ----------------------------
  // Drawing pixels on button press
  // ----------------------------
  if (digitalRead(buttonPin) == LOW) {
    // Toggle pixel state at current cursor position
    ledState[y][x] = !ledState[y][x];
    matrix.drawPixel(x, y, ledState[y][x]);  // Draw ON/OFF based on toggle
    matrix.write();
    delay(100); // Debounce delay
  }

  // ----------------------------
  // Blinking cursor (visual indicator)
  // ----------------------------
  if (ledState[y][x]) {
    // If already ON, blink OFF briefly
    matrix.drawPixel(x, y, LOW);
    matrix.write();
    delay(50);
    matrix.drawPixel(x, y, HIGH);
    matrix.write();
    delay(50);
  } else {
    // If currently OFF, blink ON briefly
    matrix.drawPixel(x, y, HIGH);
    matrix.write();
    delay(50);
    matrix.drawPixel(x, y, LOW);
    matrix.write();
    delay(50);
  }

  // ----------------------------
  // Clear screen when reset button is pressed
  // ----------------------------
  if (digitalRead(resetPin) == LOW) {
    matrix.fillScreen(LOW);   // Turn off all LEDs
    matrix.write();
    
    // Clear pixel states in memory
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 16; j++) {
        ledState[i][j] = false;
      }
    }

    delay(500); // Debounce delay
  }
}

