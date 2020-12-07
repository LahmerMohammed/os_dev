#include "types.h"
#include "string.h"
#include "system.h"

unsigned int cursorX,cursorY;

void clearLine(uint8 start, uint8 end);

void updateCursor();

void clearScreen();

void setCursor(unsigned int row , unsigned int column);

void scrollUp(uint8 no_lines);

void lastLineReach();

void print_char(char ch);

void print(string str);

void initScreen();
