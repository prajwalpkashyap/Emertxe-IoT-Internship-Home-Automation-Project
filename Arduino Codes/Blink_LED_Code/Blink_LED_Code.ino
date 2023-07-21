/*To BLINK the LED {Code to TOGGLE an LED} */

// My Comment
/*Comment said by Mam*/

#define LED 2

void setup() 
{
  //Code in which we have to do setup for 1 Time
  
  /*To Configure PIN-2 as the Output Pin [Since PIN-2 can be eiter INPUT or OUTPUT] */
  pinMode(LED, OUTPUT);  //pinMode(PinNumber, INPUT/OUTPUT); is the General Form ; LED is assigned with 2 by using 'define' Macro, hence LED is used
  
  
  
}

void loop() 
{
  //Code to repeatedly execute the function 
  
  /*To turn ON the LED*/   
  digitalWrite(LED, HIGH);  //Can also be written as digitalWrite(2, 1); since 2 is assigned to LED and HIGH=1 ; Using LED & HIGH itself is good practice
  //This ON & OFF of LED is so Fast that it is invisible or unreognizable to Human Eye ; Hence DELAY is needed to be given after ON & OFF
  delay(500); //Delay will be in ms ; 1000ms = 1ms
  
  /*To turn OFF the LED*/
  digitalWrite(LED, LOW);   //Can also be writtem as digitalWrite(2, 0);
  delay(500);

  //Now Save the file in desired location ; Compile it ; If successful then Follow Sketch -> Export Compiled Binary (or just ctrl+alt+s) to export HEX File
  
}

/*After Compiling and getting a HEX file ; Now we have to upload this HEX file into the PicSimLab Simulator by following File -> Load HEX -> Select
 file with bootloader.standard.hex file -> Verify LED is Blinking [Spare Parts -> Outputs -> LED -> Click on Screen to make LED Board Visible ->
 Right Click -> Properties -> In any of the PINs, select 4 PD2/2 (Because here PIN-2 is used) -> Now can Observe Blinking :) ]*/
 
