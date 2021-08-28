#include<isr.h>



void isr_0()
{
  print(exception_messages[0]);
  asm("hlt");
}

void isr_1()
{
  print(exception_messages[1]);
  asm("hlt");
}


void init_isr()
{
  set_idt_entry(0 , (uint32)isr_0);
  set_idt_entry(1 , (uint32)isr_1);

  set_idt(); // load idt
  
}


