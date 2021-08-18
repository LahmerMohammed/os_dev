#include <system.h>



inline uint8 inportb(uint16 port)
{
	uint8 result;
	asm volatile("in %%dx,%%al" : "=a"(result) : "d"(port));
	return result;
}

inline void outportb(uint16 port, uint8 data)
{
	asm volatile("outb %%al, %%dx" :: "a"(data), "d"(port));
}


inline uint16 inportw(uint16 port) {
	
	uint16 result;

	asm volatile("inw %%dx,%%al" : "=a"(result) : "d"(port));

	return result;
}


inline void outportw(uint16 port , uint16 data){
	asm volatile("outw %%al,%%dl" :: "a"(data) , "d"(port));
}