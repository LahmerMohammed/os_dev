#ifndef IDT_H
#define IDT_H

#include<types.h>

typedef struct  {
   uint16 low_offset; // offset bits 0..15
   uint16 selector; // a code segment selector in GDT or LDT
   uint8 zero;      // unused, set to 0
 //uint8 flags;
   uint8 type_attr; // type and attributes, see below
   uint16 high_offset; // offset bits 16..31
}__attribute__ ((packed)) idt_entry_t;


typedef struct {
  uint32 base;
  uint16 limit;
}__attribute__ ((packed)) idt_register_t;


#define IDT_ENTRIES 256

idt_entry_t idt[IDT_ENTRIES];
idt_register_t idt_register;


void set_idt_entry(uint16 n , uint32 handler);
void set_idt();

#endif