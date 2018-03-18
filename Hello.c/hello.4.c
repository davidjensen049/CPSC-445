
/* An OpneMP multithreaded program that prints hello world. 
   Compile with:
	cc -fopenmp file-name.c

*/

#include <omp.h>
#include <stdio.h>

int main()
{
	printf("Hello from main.\n");
	// Parallel region with default number of threads
	#pragma omp parallel
	{
		int myID = 0;
		printf("hello(%d)", myID);
		printf("world(%d)\n", myID);
	}
}