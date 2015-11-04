// Entropy Calculator
// Written by Christiane Kotero
// May 18 2015


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* defining macros */
# define ALPHASIZE 256 // Defining a macro for alphabet size

/* initialize a buffer to hold the information from stdin */
unsigned char buf [10000000];

/* intitialize a array to hold the frequency of each character */
unsigned int freqArray[256];

/* fill frequency array with zeroes */

int main()
{
	/* initialize Entropy */
	double Entropy = 0;

	/* fill freqency Array with 0 values */
	int count;
	for(count =0; count < 256;count++)
	{
		freqArray[count]=0;
	}
	
	int numBYTES= 0; // total number of bytes read in from stdin
	int totalVAR = 0; // total number of different outcomes

	/* read in from stdin */
	numBYTES = read(0,buf,sizeof(buf)); // store the number of bytes in numBYTES

	
	/* fill the freqArray with the frequency of each character corresponding to array position */
	int i;
	for(i = 0; i<numBYTES; i++)
	{
		freqArray[buf[i]]++; // from the Oracle article
		totalVAR++;
	}

	/* calculating the entropy using guidelines from Oracle article */

	double probOUTCOME =0;

	int j;
	for(j=0; j<ALPHASIZE; j++)
	{

		if(freqArray[j]) // if the frequency of the character is not zero
		{
			probOUTCOME = (double)freqArray[j]/(double)totalVAR;
			Entropy += (probOUTCOME*log2(1/probOUTCOME));
		}
	
	}	
	

	/* print the entropy to stdout */
	printf("This is the Entropy: %f \n",Entropy);

	return 0;
}
