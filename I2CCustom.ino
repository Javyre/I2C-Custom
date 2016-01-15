// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
/**********************************************************/
char array1[] = "something......";  //the string to print on the LCD
char array2[] = "words are cool.";  //the string to print on the LCD
char array3[] = "I am very nice.";
char array4[] = "you are awesome";
char array5[] = "Hello, World...";

char *paragraph[5] = {array1, array2, array3, array4, array5};

char *holder[2];

int tim = 25;  //the value of delay time
			   // initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
									 /*********************************************************/
void setup()
{

	holder[0] = paragraph[0];
	holder[1] = paragraph[1];


	lcd.init();  //initialize the lcd
	lcd.backlight();  //open the backlight 
					  //lcd.cursor();
}
/*********************************************************/
void loop()
{
	tim = 90;

	for (int ii = 0; ii <= 4;) {
		for (int i = 0; i <= 1; i++)
		{
			lcd.setCursor(0, i);  // set the cursor to column 15, line 0


			for (int positionCounter1 = 0; positionCounter1 < 15; positionCounter1++)
			{

				lcd.print(paragraph[ii][positionCounter1]);  // Print a message to the LCD.

				delay(tim);  //wait for 250 microseconds
			}
			if (ii + 1 <= 4) { i == 1 ? 0 : ii++; }
			else { break; }
		}
		lcd.clear();
	}

}
void shiftLines()
{

}