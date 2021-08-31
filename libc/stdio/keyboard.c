#include <keyboard.h>


uint8 read_scan_code(void)
{
  return inportb(KBDATAP);
}



