#include<isr.h>



void isr_0()
{
  write(exception_messages[0] , UNDEFINED);
  asm("hlt");
}

void isr_1()
{
  write(exception_messages[1] , UNDEFINED);
  asm("hlt");
}


void init_isr()
{
  set_idt_entry(0 , (uint32)isr_0);
  set_idt_entry(1 , (uint32)isr_1);

  set_idt(); // load idt
  
}


