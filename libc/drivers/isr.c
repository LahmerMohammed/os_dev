#include<isr.h>

void install_isr() {
    add_idt_entry(0, (uint32)isr0);
    add_idt_entry(1, (uint32)isr1);
    add_idt_entry(2, (uint32)isr2);
    add_idt_entry(3, (uint32)isr3);
    add_idt_entry(4, (uint32)isr4);
    add_idt_entry(5, (uint32)isr5);
    add_idt_entry(6, (uint32)isr6);
    add_idt_entry(7, (uint32)isr7);
    add_idt_entry(8, (uint32)isr8);
    add_idt_entry(9, (uint32)isr9);
    add_idt_entry(10, (uint32)isr10);
    add_idt_entry(11, (uint32)isr11);
    add_idt_entry(12, (uint32)isr12);
    add_idt_entry(13, (uint32)isr13);
    add_idt_entry(14, (uint32)isr14);
    add_idt_entry(15, (uint32)isr15);
    add_idt_entry(16, (uint32)isr16);
    add_idt_entry(17, (uint32)isr17);
    add_idt_entry(18, (uint32)isr18);
    add_idt_entry(19, (uint32)isr19);
    add_idt_entry(20, (uint32)isr20);
    add_idt_entry(21, (uint32)isr21);
    add_idt_entry(22, (uint32)isr22);
    add_idt_entry(23, (uint32)isr23);
    add_idt_entry(24, (uint32)isr24);
    add_idt_entry(25, (uint32)isr25);
    add_idt_entry(26, (uint32)isr26);
    add_idt_entry(27, (uint32)isr27);
    add_idt_entry(28, (uint32)isr28);
    add_idt_entry(29, (uint32)isr29);
    add_idt_entry(30, (uint32)isr30);
    add_idt_entry(31, (uint32)isr31);

    install_idt(); // Load with ASM
}

/*Handlers*/
void isr0()
{
    write(exception_messages[0]);
    asm("hlt");    
}
void isr1()
{
    write(exception_messages[1]);    
    asm("hlt");
}
void isr2()
{
    write(exception_messages[2]);    
    asm("hlt");
}
void isr3()
{
    write(exception_messages[3]);    
    asm("hlt");
}
void isr4()
{
    write(exception_messages[4]);    
    asm("hlt");
}
void isr5()
{
    write(exception_messages[5]);    
    asm("hlt");
}
void isr6()
{
    write(exception_messages[6]);    
    asm("hlt");
}
void isr7()
{
    write(exception_messages[7]);    
    asm("hlt");
}
void isr8()
{
    write(exception_messages[8]);    
    asm("hlt");
}
void isr9()
{
    write(exception_messages[9]);    
    asm("hlt");
}
void isr10()
{
    write(exception_messages[10]);    
    asm("hlt");
}
void isr11()
{
    write(exception_messages[11]);    
    asm("hlt");
}
void isr12()
{
    write(exception_messages[12]);    
    asm("hlt");
}
void isr13()
{
    write(exception_messages[13]);    
    asm("hlt");
}
void isr14()
{
    write(exception_messages[14]);    
    asm("hlt");
}
void isr15()
{
    write(exception_messages[15]);    
    asm("hlt");
}
void isr16()
{
    write(exception_messages[16]);    
    asm("hlt");
}
void isr17()
{
    write(exception_messages[17]);    
    asm("hlt");
}
void isr18()
{
    write(exception_messages[18]);    
    asm("hlt");
}
void isr19()
{
    write(exception_messages[19]);    
    asm("hlt");
}
void isr20()
{
    write(exception_messages[20]);    
    asm("hlt");
}
void isr21()
{
    write(exception_messages[21]);    
    asm("hlt");
}
void isr22()
{
    write(exception_messages[22]);    
    asm("hlt");
}
void isr23()
{
    write(exception_messages[23]);    
    asm("hlt");
}
void isr24()
{
    write(exception_messages[24]);    
    asm("hlt");
}
void isr25()
{
    write(exception_messages[25]);    
    asm("hlt");
}
void isr26()
{
    write(exception_messages[26]);    
    asm("hlt");
}
void isr27()
{
    write(exception_messages[27]);    
    asm("hlt");
}
void isr28()
{
    write(exception_messages[28]);    
    asm("hlt");
}
void isr29()
{
    write(exception_messages[29]);    
    asm("hlt");
}
void isr30()
{
    write(exception_messages[30]);    
    asm("hlt");
}
void isr31()
{
    write(exception_messages[31]);    
    asm("hlt");
}


/*End Handlers*/



/* To write the message which defines every exception */
string exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};
