#ifndef IDT_H
#define IDT_H

#include<types.h>

typedef struct  {
   uint16 low_offset; // offset bits 0..15
   uint16 selector; // a code segment selector in GDT or LDT
   uint8 zero;      // unused, set to 0
   uint8 type_attr; // type ( task,trap or interrupt ) we'll use interrupt
   uint16 high_offset; // offset bits 16..31
}__attribute__ ((packed)) idt_entry_t;


typedef struct {
  uint16 limit;
  uint32 base;
}__attribute__ ((packed)) idt_register_t;


#define IDT_ENTRIES 256

idt_entry_t idt[IDT_ENTRIES];
idt_register_t idt_register;


void add_idt_entry(int n , uint32 handler);
void install_idt();

#endif