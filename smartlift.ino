// Define the pins for the LED and button
const int ledPin = 7;
const int buttonPin = 2;

// Initialize variables for the current floor and destination floor
int currentFloor = 1;
int destinationFloor = 9;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Set the button pin as an input
  pinMode(buttonPin, INPUT);

  // Start the serial communication
  Serial.begin(9600);

  // Print the initial floor
  Serial.print("Elevator is on floor ");
  Serial.println(currentFloor);
}

void loop() {
  // Check if a button press has been received
  int floor;
  if (Serial.available() > 0) 
  {
    // Read the button press
    char buttonPress = Serial.read();

    if(buttonPress == 'b')
    {
      if(destinationFloor>currentFloor)
      {
        destinationFloor = 5;
        Serial.print("Going to floor ");
        Serial.println(destinationFloor);
       }
      }
    else if(buttonPress=='c')
    {
      if(destinationFloor<currentFloor)
      {
        destinationFloor = 5;
        Serial.print("Going to floor ");
        Serial.println(destinationFloor);
       }
      }
    else if(buttonPress=='a')
    {
        destinationFloor = 5;
        Serial.print("Going to floor ");
        Serial.println(destinationFloor);
      }
    // Check if the button press is a number between 1 and 3
    else
    {
      if (buttonPress >= '1' && buttonPress <= '9') 
      {
         // Convert the button press to an integer
         floor = buttonPress - '0';

          // Check if the destination floor is different from the current floor
         if (floor != currentFloor) 
         {
            // Set the destination floor
            destinationFloor = floor;

            // Print the destination floor
            Serial.print("Going to floor ");
            Serial.println(destinationFloor);
          }
        } 
      }
   }

  // Check if the elevator is at the destination floor
  if (currentFloor == destinationFloor) {
    // Blink the LED to signal that the elevator has arrived
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);

    // Reset the destination floor to the current floor
    destinationFloor = currentFloor;

    // Print the current floor
    Serial.print("Elevator is on floor ");
    Serial.println(currentFloor);
  } else {
    // Move the elevator towards the destination floor
    if (destinationFloor > currentFloor) {
      currentFloor++;
    } else if (destinationFloor < currentFloor) {
      currentFloor--;
    }

    // Print the current floor
    Serial.print("Elevator is on floor ");
    Serial.println(currentFloor);

    // Wait for 1 second before checking the next floor
    delay(5000);
  }
}
