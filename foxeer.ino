/* project to use foxeer fpv camera control board as a multifunction button for projects.  The foxeer board simply is a multi-resistor board.  different buttons
 *  output different voltages based on input voltage. my values are based on a voltage divider that needs to be built in order to read input.  Not because of increased voltage,  
 *  but it needs a reference to ground.  My values are based on a 220 ohm resistor as resistor 1 (R1) in the voltage divider.  A0 (analog input 1 is wired directly after the first
 *  resistor in front of the foxeer board.  So I currently have arduino uno 5V wired to a 220 ohm resistor.  The other end gets connected to one wire of the foxeer board.  This also
 *  gets connected to a0.  Then the other wire of the foxeer board connects to ground.
 */
 
#include <SoftwareSerial.h>  //debuging serial

//define constant values for button pressed as well as integer to hold it

#define btnUP 0; 
#define btnRIGHT 1;
#define btnDOWN 2;
#define btnLEFT 3;
#define btnNONE 5;
#define btnENTER 4;
int key_in = 0;

#define BTN_PIN A0 //defines the analog input pin to read voltage

void setup() {


  Serial.begin(9600);
  Serial.println("Push a button");  //print text to serial monitor
  delay(500);  //500ms delay

}

void loop() {

 key_in = read_buttons(); //calls read_buttons function and returns integer value of button pressed and updates the key_in variable from its ADC value.
 Serial.println(key_in); //prints integer of button pressed to serial monitor
 
 

}

int read_buttons()
{
  key_in = analogRead(BTN_PIN); //analog read the pin used for measurement

 // the following were my values based on a resistor 1 value of 220 ohms.  Your numbers may vary.
 
  if (key_in >1022) return btnNONE;
  if ((key_in >= 1008) && (key_in <= 1010)) return btnUP;
  if ((key_in >= 990) && (key_in <= 995)) return btnRIGHT;
  if ((key_in >= 0) && (key_in <= 2)) return btnDOWN;
  if ((key_in >= 1014) && (key_in <= 1017)) return btnLEFT;
  if ((key_in >= 1018) && (key_in <= 1021)) return btnENTER;
 
}
