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



#define KERNEL_CS 0x00


typedef struct {

        uint16 low_offset; // of base address
        uint16 selector;
        uint8 always_zero;
        unit8 falgs;
        uint16 high_offset; // of base address
} __attribute__((packed)) idt_entry;


typedef struct {
        uint16 limit;
        uint32 base;

} __attribute__((packed)) idt_register_table; 



#endif
