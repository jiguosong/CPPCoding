/*
 * alignedAllocate.h
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#ifndef ALIGNEDALLOCATE_H_
#define ALIGNEDALLOCATE_H_

#include <cstddef>

class alignedAllocate_test {
public:
	void *alignedAllocate(size_t sizeInBytes, size_t alignment);
	void alignned_free(void* p);
};



#endif /* ALIGNEDALLOCATE_H_ */
