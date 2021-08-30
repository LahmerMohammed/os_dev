#include "types.h"
#include "string.h"
#include "system.h"

uint16 cursorX,cursorY;


#define REG_SCREEN_CRTL 0x3D4
#define REG_SCREEN_DATA 0x3D5

#define SCREEN_HEIGHT 80
#define SCREEN_WIDTH 25
#define SCREEN_DEPTH  2


#define VGA_ADDRESS 0xb8000


void clearLine(uint8 start, uint8 end);

void updateCursor();

void clearScreen();

void setCursor(unsigned int row , unsigned int column);

void scrollUp(uint8 no_lines);

void lastLineReach();

void write_char(char ch);

void write(string str , uint8 _color);

uint8 getTextColor(uint8 bg , uint8 fg);

void initScreen();
