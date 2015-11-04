// Random Number Generator
// Written by Christiane Kotero
// May 18 2015
//
// My strategy; Use the clock to find a key. XOR this key with with a bit shifted representation of the same key.

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/* define macros */
#define FILESIZE 100000

int main(){

	int i = 0;
	for(i;i<FILESIZE;i++)
	{
		struct timespec init_1;
	
		/* recast time_t as a long int */		
		clock_gettime(CLOCK_MONOTONIC,&init_1);

		long temp1= init_1.tv_nsec; 

		/* store a bit shifted version of init_t in temp */	
		long temp2 = temp1<< 1;

		/* replace new_time with xor'ed bit pattern */		
		temp1 ^= temp2;

		/* convert this number to a character from the 256 character alphabet */
		unsigned char c = (temp1 & 0xFF); // we take the lowest 8 bits
		printf("%c",c);		
	}



return 0;
}
