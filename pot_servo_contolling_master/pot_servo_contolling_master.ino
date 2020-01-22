 
#include <SPI.h>
#include <RF24.h>

// Radio Configuration
RF24 radio(51,7);
byte addresses[][6] = {"1Node","2Node"};
// analog pins used to connect the potentiometer
byte PotPins[] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15}; 
unsigned int data[16];

void setup() {
    Serial.begin(9600);                   // Get ready to send data back for debugging purposes
    radio.begin();                        // Get the transmitter ready
    radio.setPALevel(RF24_PA_LOW);        // Set the power to low
    radio.openWritingPipe(addresses[1]);  // Where we send data out
    radio.openReadingPipe(1,addresses[0]);// Where we receive data back
}

// the code inside loop() 
void loop() {

     int val = analogRead(A5); 
    int result = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
   
          Serial.print("pot data"); 
    Serial.print(5); 
    Serial.print(" : "); 
    Serial.println(val); 
    
    radio.stopListening();                                 // Stop listening and begin transmitting
    delay(500);                                            // quite a long delay -- causes jittering of servo
    for (int x = 0; x < 16; x++){
      data[x]= convertpotToServo(x); // reads the value of the potentiometer and convert to servo value
      radio.write(&data[x], sizeof(data[x]));    //Send data   
    } 
    radio.startListening();
 
}

 

int convertpotToServo(int x) {
  // reads the value of the potentiometer (value between 0 and 1023)
    int val = analogRead(PotPins[x]); 
    int result = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)


    return result;
}
