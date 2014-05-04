#include  "Random.h"
#include  <string.h>
#include  <stdlib.h>

void RandomInPlace(void *Array, int length, size_t memsize)
{
	int i, index;
	void *temp = malloc(memsize);

	for (i = 0; i < length; i++) {
		index = Random(i, length - 1);
		memcpy(temp, Array + i * memsize, memsize);
		memcpy(Array + i * memsize, Array + index * memsize, memsize);
		memcpy(Array + index * memsize, temp, memsize);
	}
}


