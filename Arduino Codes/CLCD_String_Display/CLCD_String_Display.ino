/* To Configure the CLCD and to Print the Strings on CLCD */

// My Comment
/*Comment said by Mam*/

/* To use I2C/TWI[Two Wired Interface] Protocol and LCD Library, including 2 Libraries */
/* I2C Library */
#include <Wire.h>
/* LCD Library with I2C */
#include <LiquidCrystal_I2C.h>    //This is not In-Built, we have to Install; Tools -> Manage Libraries -> Search & Install LiquidCrystal_I2C version 1.1.2

/* Creating the Object of LCD with I2C address of 0x27 (default), 2 Lines Display with 16 Characters each */
LiquidCrystal_I2C lcd(0x27, 16, 2);               //SYNTAX : LiquidCrystal_I2C object_name (address,column,rows); {0x27 is fixed for this 'lcd hd44780 i2c'}

void setup() 
{
  // put your setup code here, to run once:
  /* Initializing the LCD */      //SYNTAX : object_name.function();
  lcd.init();
  /* Turning on the BackLight */
  lcd.backlight();
  /* Clearing the LCD Screen (To erase all the old contents if present) */
  lcd.clear();
  /* To set Cursor to the First Position */
  lcd.home();

  /* To Display the String on CLCD */
  lcd.setCursor(0,0);     //SYNTAX : object_name.setCursor(column, row); This sets the Position to 1st Column and 1st Row {Indexing from 0}
  lcd.print("PrajwalPKashyap");     
  
  lcd.setCursor(4,1);     //This sets the Position of the Cursor to 5th Column and 2nd Row {Indexing from 0}
  lcd.print("1KI20CS070");

  
}

void loop()
{
  // put your main code here, to run repeatedly:
  /* Don't want to loop any of the Code in this Program, hence this is EMPTY */
}

// Refer 1st Program (Blinking the LCD) for the Steps of Exporting HEX File and to Run (Use lcd hd44780 i2c in Module -> Spare Parts -> Outputs)
