#include<gdt.h>

/**
 * @brief  add entry to gdt table
 * 
 * @param other : expect high 4 bits of actual gran ( without limit )
 * @param base : 32 bits base address
 * @param limit : 32 bits size
 * @param index : index of entry in gdt table
 */

void add_gdt_entry(uint16 index , uint32 base , uint32 limit , uint8 access , uint8 other)
{
  // set base address
  gdt[index].base_low = base & 0xFFFF;
  gdt[index].base_middle = (base >> 16) & 0xFF;
  gdt[index].base_high = (base >> 24) & 0xFF;

  // set limit 
  gdt[index].limit_low = limit & 0xFFFF;
  gdt[index].limit_high = (limit >> 16) & 0xF;


  // set access & other 
  gdt[index].other = other & 0xF;
  gdt[index].access = access;

}

void init_gdt()
{
  add_gdt_entry(0 , 0 , 0 , 0 , 0);
  add_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
  add_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

}


void install_gdt()
{

  init_gdt();

  gdt_register.base =(uint32) &gdt;
  gdt_register.limit = GDT_ENTRIES * sizeof(gdt_entry_t) - 1;

  gdt_flush();
}