// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
/**********************************************************/

bool hasNextLine();
void shiftLines();
void resetHolder();
void printLine(char*);
void printLine(int*, char*);

char *array0 = "               ";
char *array1 = "something......";  //the string to print on the LCD
char *array2 = "words are cool.";  //the string to print on the LCD
char *array3 = "I am very nice.";
char *array4 = "you are awesome";
char *array5 = "Hello, World...";

char *paragraph[6] = {array0, array1, array2, array3, array4, array5};

char *holder[2];

int lastLine;

int tim = 25;  //the value of delay time
			   // initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
									 /*********************************************************/
void setup()
{
	Serial.begin(9600);
	resetHolder();


	lcd.init();  //initialize the lcd
	lcd.backlight();  //open the backlight 
					  //lcd.cursor();
}
/*********************************************************/




void loop()
{
	tim = 90;

	while (hasNextLine())
	{
		for (int ii = 0; ii <= 1; ii++) {
			lcd.setCursor(0, ii);
			printLine((ii == 1) ? &tim : NULL, holder[ii]);
		}

		shiftLines();
		lcd.clear();
	}
	resetHolder();
	delay(1000);
}

bool hasNextLine()
{
	return (lastLine+1 > 6) ? false : true;
}


void shiftLines()
{
	holder[0] = holder[1];
	holder[1] = paragraph[++lastLine];
}

void resetHolder()
{
	lastLine = 1;
	holder[0] = paragraph[0];
	holder[1] = paragraph[lastLine];
}

void printLine(char *text)
{
	printLine(nullptr, text);
}

void printLine(int *delayT, char *text)
{
	for (int positionCounter1 = 0; positionCounter1 < 15; positionCounter1++)
	{

		lcd.print(text[positionCounter1]);  // Print a message to the LCD.

		if (*delayT != NULL)
		{
			Serial.print(*delayT);
			Serial.print(" : ");
			Serial.println(tim);
			delay(*delayT);
		}
		
		

	}
}