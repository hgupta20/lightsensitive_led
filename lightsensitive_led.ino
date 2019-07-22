// You will be using 4 LEDS and a photoresistor. Put all 4 LEDs next to each (preferably the same
// color). As the amount of light seen by the photoresistor decreases, increase the number of LEDs
// that are lit. 
// In parallel with part 1, you will be using the passive buzzer and the potentiometer. Use the
// potentiometer as an analog input and have the output come from another analog pin. Control the
// volume or tone of the buzzer by adjusting the potentiometer. Make sure to have code to control
// the output of the buzzer based on the potentiometer.
// Be able to have your aurdino do two unconnected things at the same time, using multiple inputs
// and outputs.
// Be able to read and write to analog inputs and outputs.


int pCellReading; // record the reading and compare the amount of light recieved by the circuit
const int pCelldata = 0; // the data pin through which the audrino would read the data
const int ledPin1 = 10; // led1 pin at 10 
const int ledPin2 = 9; // led2 pin at 9
const int ledPin3 = 8; // led3 pin at 8
const int ledPin4 = 7; // led4 pin at 7
const int buzzer = 5; // buzzer placed at pin 6
const int potentio = A1; // analog input

void setup() {
  // setup for the led output and buzzer
  pinMode(5,OUTPUT);
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
  pinMode (buzzer, OUTPUT);
  Serial.begin(9600); // to communicate with the computer and display data to the serial monitor
  pinMode (potentio, OUTPUT);
  
  
  
}

void loop() {


  pCellReading = analogRead (pCelldata); // read the data and set the reading
  Serial.println(pCellReading); // print the reading on the serial monitor
  
  // compare the reading and brightness according to the range provided
  // too dark, turn on all four leds
  if (pCellReading < 100) {
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, HIGH); 
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, HIGH); 
  }
  // other wise partially dark, turn on 3 leds
  else if (pCellReading < 250) {
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, HIGH); 
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
  }
  // other wise Medium, turn on 2 leds
  else if (pCellReading < 500) {
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
  }
  // other wise partially light, lurn on one led
  else if (pCellReading < 750) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
  }
  // other wise fully lit, turn off all the leds
  else{
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW);
  }

  // code to control the buzzer through potentiometer
  int speaker = 0;
  speaker = analogRead(potentio); // read the potentiometer
  speaker = map(speaker, 0 , 3000 , 0, 200); // manage the volume and 
  analogWrite(5,speaker); // write it back 
  
}
