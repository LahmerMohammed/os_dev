#ifndef GDT_H
#define GDT_H

#include<types.h>


typedef struct {
  
  uint16 limit_low;
  uint16 base_low;
  uint8 base_middle;
  uint8 access;
  uint8 limit_high : 4; // 4 bits
  uint8 other: 4; // 4 bits
  uint8 base_high;

}__attribute__((packed)) gdt_entry_t;


typedef struct {
  uint16 limit;
  uint32 base;

}__attribute__((packed)) gdt_register_t;


#define GDT_ENTRIES 3

gdt_entry_t gdt[GDT_ENTRIES];
gdt_register_t gdt_register;


void add_gdt_entry(uint16 index , uint32 base , uint32 limit , uint8 access , uint8 other);
void init_gdt();

// tells the CPU where the new GDT is
extern void gdt_flush();


void install_gdt();


#endif