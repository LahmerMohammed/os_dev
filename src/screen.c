#include <screen.h>

unsigned int cursorX = 0, cursorY = 0;

void clearLine(uint8 start, uint8 end)
{

	uint8 no_cell = SC_DEPTH * SC_WIDTH;

	uint16 i = start * no_cell;
	string fb = (string)FB_ADDRESS;
	uint8 no_line = end - start + 1;

	for (; i < (no_cell * no_line); i++)
	{
		fb[i] = 0x0;
	}
}

void updateCursor()
{
	uint16 pos = cursorY * SC_WIDTH + cursorX;

	outportb(0x3D4, 0x0F); // low  8 bits
	outportb(0x3D5, (uint8)(pos & 0xFF));
	outportb(0x3D4, 0x0E); // high  8 bits
	outportb(0x3D5, (uint8)((pos >> 8) & 0xFF));
}

void initScreen()
{
	clearScreen();

	uint16 str_size = strSize(USER);
	
	print(USER);

	cursorX = strSize(USER) - 1;
	cursorY = 0;
	updateCursor();
}

void clearScreen()
{
	clearLine(0, SC_HEIGHT - 1);
}

void scrollUp(uint8 no_lines)
{
	string fb = (string)FB_ADDRESS;
	uint16 i = 0;

	for (; i < (SC_WIDTH * (SC_HEIGHT - 1) * SC_DEPTH); i++)
	{
		fb[i] = fb[i + SC_WIDTH * SC_DEPTH * no_lines];
	}

	clearLine(SC_HEIGHT - 1 - no_lines, SC_HEIGHT - 1);

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
	if (cursorY == (SC_HEIGHT - 1))
		scrollUp(1);
}

void print_char(char ch)
{
	string fb = (string)FB_ADDRESS;
	switch (ch)
	{
	case (0x08):
	{ // back-space
		if ((cursorX >= 16 && cursorY == 0) || (cursorX > 0 && cursorY > 0))
		{
			cursorX--;
			fb[(SC_WIDTH * cursorY + cursorX) * SC_DEPTH] = 0x00;
		}
		else if (cursorX == 0 && cursorY > 0)
		{
			cursorY--;
			uint8 i = SC_WIDTH;
			while ((cursorY > 0 && i >= 0) || (cursorY == 0 && i >= 16))
			{
				if (fb[(SC_WIDTH * cursorY + i - 1) * SC_DEPTH] != 0x00)
					break;
				i--;
			}
			cursorX = i + 1;
		}
		break;
	}
	case ('\r'):
	{
		cursorX = 0;
		break;
	}
	case ('\t'):
	{
		cursorX += TAB_LENGTH;
		break;
	}
	case ('\n'):
	{
		cursorX = 0;
		cursorY++;
		break;
	}
	default:
	{
		uint16 pos = ((cursorY * SC_WIDTH) + cursorX) * SC_DEPTH;
		fb[pos] = ch;
		fb[pos + 1] = 0x0F;
		cursorX++;
		break;
	}
	}
	if (cursorX >= SC_WIDTH)
	{
		cursorX = 0;
		cursorY++;
	}
	lastLineReach();
	updateCursor();
}

void print(string str)
{
	uint16 str_size = strSize(str);
	for (uint16 i = 0; i < str_size; i++)
	{
		print_char(str[i]);
	}
	cursorX += str_size - 1; // -1 : don't add extra space after printing last char
	updateCursor();
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
