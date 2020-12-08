#include<idt.h>

uint16 low16(uint32 value)
{
        return (uint16)value;
}


uint16 high16(uint32 value )
{
        return (uint16)(value >> 16);
}

void set_idt_entry(int n , uint32 handler)
{
        idt_t[n].low_offset = low16(handler);
        idt_t[n].high_offset = high16(handler);
        idt_t[n].selector = KERNEL_CS;
        idt_t[n].always_zero = 0;
        idt_t[n].flags = 0x8E; // ???
}

void set_idt()
{
        idt_reg.base = (uint32)(&idt_t);
        idt_reg.limit = IDT_ENTRIES * sizeof(idt_entry) - 1;
        __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));
}
