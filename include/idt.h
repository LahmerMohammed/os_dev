/*
 * =====================================================================================
 *
 *       Filename:  idt.h
 *
 *    Description: Implementation of Interrupt descriptor table  
 *
 *        Version:  1.0
 *        Created:  12/07/2020 06:44:11 PM
 *       Compiler:  gcc
 *
 *         Author:  LAHMER MOHAMMED  
 *   Organization:  
 *
 * =====================================================================================
 */



#ifndef __IDT_H
#define __IDT_H



#include<types.h>



#define KERNEL_CS 0x08

#define IDT_ENTRIES 256

typedef struct {

        uint16 low_offset; // of base address
        uint16 selector;
        uint8 always_zero;
        uint8 flags;
        uint16 high_offset; // of base address
} __attribute__((packed)) idt_entry;


typedef struct {
        uint16 limit;
        uint32 base;

} __attribute__((packed)) idt_descriptor; 

static idt_entry idt_t[IDT_ENTRIES];

static idt_descriptor idt_reg;


void set_idt_entry(int n , uint32 handler);

void set_idt();

#endif
