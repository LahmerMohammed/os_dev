#include <screen.h>

uint16 cursorX = 0,cursorY = 0;
uint8 text_color = DEFAULT_COLOR;

void clearLine(uint8 start, uint8 end)
{

	uint8 no_cell = SCREEN_DEPTH * SCREEN_WIDTH;

	uint16 i = start * no_cell;
	string fb = (string)VGA_ADDRESS;
	uint8 no_line = end - start + 1;

	for (; i < (no_cell * no_line); i++)
	{
		fb[i] = 0x0;
	}
}

void updateCursor()
{
	uint16 pos = cursorY * SCREEN_WIDTH + cursorX;

	// low  8 bits
	outportb(0x3D4, 0x0F); 
	outportb(0x3D5,(uint8)( pos & 0xFF));

	// high  8 bits
	outportb(0x3D4, 0x0E);
	outportb(0x3D5,(uint8)(pos >> 8) & 0xFF);
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

void write(string str , uint8 _color)
{
	uint16 str_size = strSize(str);

	if( _color )
		text_color = _color;


	for (uint16 i = 0; i < str_size; i++)
	{
		write_char(str[i]);
	}
	//cursorX += str_size - 1; // -1 : don't add extra space after printing last char
	//updateCursor();
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
