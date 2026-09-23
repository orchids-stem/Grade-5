void setup()
{
  // Set pins 5 to 10 as output pins to control LEDs
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // Turn on each LED one by one with a 1-second delay between each
  digitalWrite(5, HIGH);  // Turn on LED connected to pin 5
  delay(1000);            // Wait for 1 second
  digitalWrite(6, HIGH);  // Turn on LED connected to pin 6
  delay(1000);            // Wait for 1 second
  digitalWrite(7, HIGH);  // Turn on LED connected to pin 7
  delay(1000);            // Wait for 1 second
  digitalWrite(8, HIGH);  // Turn on LED connected to pin 8
  delay(1000);            // Wait for 1 second
  digitalWrite(9, HIGH);  // Turn on LED connected to pin 9
  delay(1000);            // Wait for 1 second
  digitalWrite(10, HIGH); // Turn on LED connected to pin 10
  delay(1000);            // Wait for 1 second

  // Turn off each LED one by one with a 1-second delay between each
  digitalWrite(5, LOW);   // Turn off LED connected to pin 5
  delay(1000);            // Wait for 1 second
  digitalWrite(6, LOW);   // Turn off LED connected to pin 6
  delay(1000);            // Wait for 1 second
  digitalWrite(7, LOW);   // Turn off LED connected to pin 7
  delay(1000);            // Wait for 1 second
  digitalWrite(8, LOW);   // Turn off LED connected to pin 8
  delay(1000);            // Wait for 1 second
  digitalWrite(9, LOW);   // Turn off LED connected to pin 9
  delay(1000);            // Wait for 1 second
  digitalWrite(10, LOW);  // Turn off LED connected to pin 10
  delay(3000);            // Wait for 3 seconds before restarting the loop
}
