/*
 * spinlock.cpp


 *
 *  Created on: Nov 2, 2016
 *      Author: songjiguo
 */


using namespace std;

#include <iostream>
#include <stdio.h>

/*

static void spinlock_test() {
	__asm__ (
		"spin_lock:"
			"xorl %ecx, %ecx"
			"incl %ecx"
		"spin_lock_retry:"
			"xorl %eax, %eax"
			"lock; cmpxchgl %ecx, (lock_addr)"
			"jnz spin_lock_retry"
			"ret"

		"spin_unlock:"
			"movl $0 (lock_addr)"
			"ret"
	)
*/

	/*
	__asm__ (
			"locked:"
			"	quad 0;"
			"spin_lock:"
			"	mov eax, 1;"
			"	xchg eax, [locked];"
			"	test eax, eax;"
			"	jnz spin_lock;"
			"	ret;"
	);

	__asm__ (
			"mov eax, 0"
			"xchg eax, [locked]"
			"ret"
	);*/

//}

void my_strcpy(char *dest, const char *src, size_t sz) {
	size_t i = 0;
	for(i = 0; i < sz && src[i] != '\0'; ++i) {
		dest[i] = src[i];
	}

	while((size_t)i < sz) {
		dest[i] = '\0';
		++i;
	}
}

int main()
{
	//spinlock_test();

	char *dest = (char *)malloc(sizeof(char)*10);;
	const char *source = "testsdfsdf";
	my_strcpy(dest, source, 3);
	cout << dest <<endl;
}

