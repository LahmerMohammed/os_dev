/*
 * =====================================================================================
 *
 *       Filename:  memory.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/07/2020 07:05:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: LAHMER MOHAMMED, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <memory.h>


void memcpy( uint8 *source , uint8 *destination , int nbytes)
{
		for( ; nbytes > 0 ; nbytes-- )
		{
			destination[nbytes] = source[nbytes];
		}
}

void memset( uint8 *source ,  uint8 value , int nbytes )
{
	for( ; nbytes > 0 ; nbytes-- )
	{
		source[nbytes] = value;
	}
}

void itoa( int number , string str )
{
	int num_length = 0;
	bool sign  = number > 0 ? false : true;
	int x = number;
	
	do{
		num_length++;
		x/=10;
	}while(num_length);
    
	if( sign ) str[0] = '-' else str[0] = '+';
	
	str[num_length+1] = '\0';
	
	uint8 offset = 48; // ascii ('0') = 48
	
	for( ; num_length > 0 ; num_length-- )
	{
		str[num_length] = (char)(number%10 + offset);
		number/=10;
	}
	
}


