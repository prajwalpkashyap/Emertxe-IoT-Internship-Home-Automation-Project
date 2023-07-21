/*To fill the Water Tank & Empty it, Read the Volume of Water in the Tank
and to displat it on the CLCD*/

// My Comment
/*Comment said by Mam*/


/* ACTUATORS TO BE USED (Digital Input) : Inlet Valve, Outlet Valve {Numbering is 0x0N}*/
#define INLET_VALVE   0x00
#define OUTLET_VALVE  0x01

/* DIGITAL SENSORS TO BE USED (Digital Output) : High Float, Low Float {Numbering is 0x1N}*/
#define HIGH_FLOAT    0x10
#define LOW_FLOAT     0x11

/*ANALOG SENSOR TO BE USED (Analog Output) : Volume of the Tank {Numbering is 0x3N} */
#define VOLUME        0x30

#define DISABLE       0x00
#define ENABLE        0x01

// Library Functions & Initializing the CLCD, Displaying the String codes are Copied from CLCD Sketch
/* To use I2C/TWI[Two Wired Interface] Protocol and LCD Library, including 2 Libraries */
/* I2C Library */
#include <Wire.h>
/* LCD Library with I2C */
#include <LiquidCrystal_I2C.h>    //This is not In-Built, we have to Install; Tools -> Manage Libraries -> Search & Install LiquidCrystal_I2C version 1.1.2

/* Creating the Object of LCD with I2C address of 0x27 (default), 2 Lines Display with 16 Characters each */
LiquidCrystal_I2C lcd(0x27, 16, 2);               //SYNTAX : LiquidCrystal_I2C object_name (address,column,rows); {0x27 is fixed for this 'lcd hd44780 i2c'}
unsigned char Value_H, Value_L;
unsigned int volume;
unsigned char volumeL, volumeH;

void setup() 
{
  // put your setup code here, to run once:
  /*To Start/Initialize the Serial Communication*/
  Serial.begin(19200);
  
  /* Initializing the CLCD */      //SYNTAX : object_name.function();
  lcd.init();
  /* Turning on the BackLight */
  lcd.backlight();
  /* Clearing the LCD Screen (To erase all the old contents if present) */
  lcd.clear();
  /* To set Cursor to the First Position */
  lcd.home();
  
  /*Displaying the String*/
  lcd.setCursor(0, 0);
  lcd.print("Connect SrTank");

  /*Sending some Dummy Values {Optional, Code will work without this} */
  Serial.write(0xFF);  
  Serial.write(0xFF);  
  Serial.write(0xFF);  
  
} 

void volume_water(void)
{
  /*To read the Volume of Water */
  Serial.write(VOLUME);
  /*Wait for Data */    //Below is the standard Pre-Defined Procedure 
  while(!Serial.available());
  volumeH = Serial.read();  
  while(!Serial.available());
  volumeL = Serial.read();
  /*Combining Higher Byte & Lower Byte */
  volume = (volumeH << 8) | volumeL;  

  lcd.setCursor(0, 1);
  lcd.print("Vol");
  lcd.print(volume);
  lcd.print("ltr");
}


void filling_start(void)
{
  /*Enable the INLET_VALVE */
  Serial.write(INLET_VALVE);
  Serial.write(ENABLE);
  
  /*Disable the OUTLET_VALVE */
  Serial.write(OUTLET_VALVE);
  Serial.write(DISABLE);

  lcd.setCursor(0, 0);
  lcd.print("Filling");

  /*Once Tank is FULL, Disable the INLET_VALVE */
  do
  {
    /*Reading Status of HIGH_FLOAT */
    Serial.write(HIGH_FLOAT);
    /*Wait for Data */
    while(!Serial.available());     //1 Line while loop
    Value_H = Serial.read();  
    volume_water();
  }while(Value_H==0);
}


void start_emptying()
{
  /*Enable the OUTLET_VALVE */
  Serial.write(OUTLET_VALVE);
  Serial.write(ENABLE);
  
  /*Disable the INLET_VALVE */
  Serial.write(INLET_VALVE);
  Serial.write(DISABLE);

  lcd.setCursor(0, 0);
  lcd.print("Emptying");

  /*To check the Tank is EMPTY*/
  do
  {
    /*Reading Status of LOW_FLOAT */
    Serial.write(LOW_FLOAT);
    /*Wait for Data */
    while(!Serial.available());     //1 Line while loop
    Value_L = Serial.read();  
    volume_water();
  }while(Value_L==1);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  filling_start();
  
  start_emptying();
}
