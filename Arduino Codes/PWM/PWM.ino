/*To Control the Brightness of the LED using LDR Sensor */
// This code is ALTERED CODE of 1st written PWM with for loop (Now removed)

// My Comment
/*Comment said by Mam*/

#define LED         3
#define LDR_SENSOR  A0 
// Only * PINS i.e., Only in PINS=3,5,6,9,10,11 we can generate PWM


void setup() 
{
  /*To Configure LED Pin as Output*/
  pinMode(LED, OUTPUT);
  
}

unsigned int ldr_val; //Unsigned int is considered because, We are Not going to get any negative values  

void loop() 
{
  /*To Read the Values from LDR Sensor connected to A0 PIN*/
  ldr_val = analogRead(A0);

  /*Mapping 0-1023(Votage) to 255-0(DutyCycle)*/
  /*Scaling down 0-1023 -> 255-0 */
  ldr_val = (1023 - ldr_val)/4;

  /*To assign Duty Cycle to LED based on LDR Value*/
  analogWrite(LED, ldr_val);
  delay(100);
  
  
  
} 
