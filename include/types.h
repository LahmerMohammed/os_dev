#ifndef TYPES_H
#define TYPES_H

typedef unsigned char uint8;
typedef signed char int8;

typedef unsigned short uint16;
typedef signed short int16;

typedef unsigned int uint32;
typedef signed int int32;

typedef unsigned long long uint64;
typedef signed long long int64;

typedef char* string;

#define FB_COMMAND_PORT 0x3D4 // Describe data
#define FB_DATA_PORT 0x3D5		// data itself

#define FB_HIGH_BYTE_COMMAND    14 // expect the heighest
#define FB_LOW_BYTE_COMMAND     15 // expect the lowest

#define SC_WIDTH 80 
#define SC_HEIGHT  25

#define SC_DEPTH  2
#define FB_ADDRESS 0xb8000

#define TAB_LENGTH 4

#define USER "[mohammed-la]#:"


#endif
