/*
 * =====================================================================================
 *
 *       Filename:  memory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/07/2020 07:02:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LAHMER MOHAMMED, 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __MEMORY_H
#define  __MEMORY_H


#include<types.h>

void memcpy( uint8 *source , uint8 *destination , uint8 value);

void memset( uint8 *source ,  uint8 value , int nbytes );

void itoa( int number , string str );


#endif
