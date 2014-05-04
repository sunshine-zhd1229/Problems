#include  <stdlib.h>
#include  <time.h>

int Random(int start, int end)
{
	srand((unsigned int) time(NULL));	
	return (rand() % (end - start + 1)) + start;
}


