#include <screen.h>
#include<gdt.h>
#include<isr.h>

void kmain()
{
	install_gdt();
	initScreen();
	install_isr();
	int x = 5/0;

	//write("Hello \n");
	
}	
