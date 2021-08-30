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

#define FB_HIGH_BYTE_COMMAND    14 // expect the heighest
#define FB_LOW_BYTE_COMMAND     15 // expect the lowest



#define TAB_LENGTH 4

#define USER "[mohammed-la]#:"

#define DEFAULT_COLOR 0x0F

enum COLOR {
  BLACK=0,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  LIGHTGREY,
  DARKGREY,
  LIGHTBLUE,
  LIGHTGREEN,
  LIGHTCYAN,
  LIGHTRED,
  LIGHTMAGENTA,
  LIGHTBROWN,
  WHITE,
};


#endif
