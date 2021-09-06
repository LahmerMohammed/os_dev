#include <screen.h>

uint16 cursorX = 0,cursorY = 0;
uint8 text_color = DEFAULT_COLOR;

void clearLine(uint8 start_line, uint8 no_lines)
{


	uint16 i = start_line * SCREEN_WIDTH; // 0
	string fb = (string)VGA_ADDRESS;
	
	uint16 no_cells = no_lines * SCREEN_WIDTH; //

	for (; i < no_cells; i++)
	{
		fb[i+1] = getTextColor(BLACK,BLACK);
	}
}

void updateCursor()
{
	uint16 pos = cursorY * SCREEN_WIDTH + cursorX;

	// low  8 bits
	outportb(0x3D4, 0xF); 
	outportb(0x3D5,pos & 0x00FF);

	// high  8 bits
	outportb(0x3D4, 0xE);
	outportb(0x3D5,(pos >> 8) & 0x00FF);
}

void initScreen()
{
	clearScreen();	
	updateCursor();
}

void clearScreen()
{
	clearLine(0, SCREEN_HEIGHT - 1);
}

void scrollUp(uint8 no_lines)
{
	string fb = (string)VGA_ADDRESS;
	uint16 i = 0;

	for (; i < (SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * SCREEN_DEPTH); i++)
	{
		fb[i] = fb[i + SCREEN_WIDTH * SCREEN_HEIGHT * no_lines];
	}

	clearLine(SCREEN_HEIGHT - 1 - no_lines, SCREEN_HEIGHT - 1);

	if ((cursorY - no_lines) < 0)
	{
		cursorX = 0;
		cursorY = 0;
	}
	else
	{
		cursorY -= no_lines;
	}

	updateCursor();
}

void lastLineReach()
{
	if (cursorY == (SCREEN_HEIGHT - 1))
		scrollUp(1);
}

void write_char(char ch)
{
	string fb = (string)VGA_ADDRESS;
	switch (ch)
	{
	case ('\n'): { cursorX = 0; cursorY++; break;}
	default: 
	{
			uint16 pos = ((cursorY * SCREEN_WIDTH) + cursorX) * SCREEN_DEPTH;
			fb[pos] = ch;
			fb[pos + 1] = text_color;
			cursorX++;
			break;
		}
	}
	if (cursorX >= SCREEN_WIDTH)
	{
		cursorX = 0;
		cursorY++;
	}
	lastLineReach();
	updateCursor();
}

uint8 getTextColor(uint8 bg, uint8 fg)
{
  return  ((bg << 4) | 0xF) & (0xF0 | fg);
}

void write(string str , ...)
{
	/*
	va_list args;
	va_start(args , 1); // expect when optional args
	uint8 color = va_arg(args , int);
	va_end(args);
	text_color = color == NULL ? DEFAULT_COLOR : color;
	*/
	uint16 str_size = strSize(str);
	


	for (uint16 i = 0; i < str_size; i++)
	{
		write_char(str[i]);
	}
	
	// set back default color
	text_color = DEFAULT_COLOR;
}

void setCursor(unsigned int row, unsigned int column)
{
	if (row >= 0 && row <= 24 && column >= 16 && column <= 80)
	{
		cursorX = row;
		cursorY = column;
		updateCursor();
	}
}
