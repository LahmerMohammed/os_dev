#include <system.h>

uint8 inportb(uint16 _port)
{
	uint8 result;
	__asm__ __volatile__("in %%dx,%%al"
						 : "=a"(result)
						 : "d"(_port));
	return result;
}

void outportb(uint16 port, uint8 data)
{
	__asm__ __volatile__("outb %%al, %%dx"
						 :
						 : "a"(data), "d"(port));
}