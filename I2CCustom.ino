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

	//Serial.begin(9600);

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
			//i == 1 ? 0 : ii++;
			lcd.setCursor(0, i);  // set the cursor to column 15, line 0
			

			for (int positionCounter1 = 0; positionCounter1 < 15; positionCounter1++)
			{
				//sprintf("Printing : %s", paragraph[ii][positionCounter1])
				//lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
				//Serial.println();
				lcd.print(paragraph[ii][positionCounter1]);  // Print a message to the LCD.
				
				delay(tim);  //wait for 250 microseconds
			}
			if (ii + 1 <= 4) { i == 1 ? 0 : ii++; }
			else { break; }

			//ii + 1 > 3 ? 0 : (i == 1 ? 0 : ii++);
			//i == 1 ? 0 : ii++;

		}
		lcd.clear();
	}

	

	/*
	lcd.setCursor(0, 0);  // set the cursor to column 15, line 0
	for (int positionCounter1 = 0; positionCounter1 < 15; positionCounter1++)
	{
		//lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
		lcd.print(array1[positionCounter1]);  // Print a message to the LCD.
		delay(tim);  //wait for 250 microseconds
	}
	// lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.
	lcd.setCursor(0, 1);  // set the cursor to column 15, line 1
	for (int positionCounter = 0; positionCounter < 15; positionCounter++)
	{
		
		//lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
		lcd.print(array2[positionCounter]);  // Print a message to the LCD.
		delay(tim);  //wait for 250 microseconds
	}
	//lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.
	*/
}
/************************************************************/

void shiftLines()
{

}