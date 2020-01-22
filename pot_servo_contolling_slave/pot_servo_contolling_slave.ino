 

// These constants won't change.  They're used to give names
// to the pins used:
#define analogInPin0 A0  // Analog input pin that the potentiometer is attached to

void setup() {
  // initialize serial communications at 9600 bps 
  // (Make sure your Serial Monitor window is set to same)
  Serial.begin(9600);
}

void loop() {

  // display values on the serial monitor:  
  Serial.print("Pot-22K = ");
  Serial.println(analogRead(analogInPin0));

  // wait 10 milliseconds before the next loop  
  delay(100);
}
