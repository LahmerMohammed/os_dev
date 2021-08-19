#include<idt.h>

void set_idt_entry(uint16 n , uint32 handler ) {
    idt[n].low_offset = (uint16)(handler & 0xFFFF);
    idt[n].zero = 0x00;
    idt[n].high_offset = (uint16)( (handler >> 16) & 0xFFFF );

    idt[n].selector = 0x08; // no idea
    idt[n].type_attr = 0xE;
}


void set_idt(){
  idt_register.base = (uint32) &idt;
  idt_register.limit = IDT_ENTRIES * sizeof(idt_entry_t) - 1;
  
  asm volatile("lidt (%0) " :: "r"(&idt_register));
}

