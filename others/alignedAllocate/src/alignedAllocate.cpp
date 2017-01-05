/*
 * alignedAllocate.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "alignedAllocate.h"
#include <cstring>
#include <memory>

/*
For a more generic memory allocation function, the caller doesn't want to have to keep track of two pointers (one to use and one to free).
So you store a pointer to the 'real' buffer below the aligned buffer.

Steps:
1. We will use malloc routine provided by C to implement the functionality.
   Allocate memory of size (bytes required + alignment - 1 + sizeof(void*)) using malloc.
   alignment: malloc can give us any address and we need to find a multiple of alignment.
   (Therefore, at maximum multiple of alignment, we will be alignment-1 bytes away from any location.)
   sizeof(size_t): We are returning a modified memory pointer to user, which is different
   from the one that would be returned by malloc. We also need to extra space to store the
   address given by malloc, so that we can free memory in aligned_free by calling free
   routine provided by C.

2. If it returns NULL, then aligned_malloc will fail and we return NULL.

3. Else, find the aligned memory address which is a multiple of alignment (call this p2).

4. Store the address returned by malloc (e.g., p1 is just size_t bytes ahead of p2),
   which will be required by aligned_free.

5. Return p2.
*/

void *alignedAllocate_test::alignedAllocate(size_t sizeInBytes, size_t alignment)
{
	void* p1;  // original block
	void** p2; // aligned block
	int offset = alignment - 1 + sizeof(void*);
	if ((p1 = (void*)malloc(sizeInBytes + offset)) == NULL) return NULL;
	p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
	p2[-1] = p1;
	return p2;
}

void alignedAllocate_test::alignned_free(void* p) {
	free(((void**)p)[-1]);
}
