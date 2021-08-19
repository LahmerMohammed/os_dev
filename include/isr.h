#ifndef ISR_H
#define ISR_H


#include<idt.h>
#include<screen.h>

void isr_0();
void isr_1();


void init_isr();

string exception_messages[] = {'Division by Zero','Keyboard'};




#endif