#include "memory.h"
#include <core.h>

void* mem_copy(void* dest, const void* src, size_t size)
{
	unsigned char* d = dest;
	const unsigned char* s = src;

	for (size_t i = 0; i < size; i++){
		d[i] = s[i];
	}

	return dest;
}

void* mem_move(void* dest, const void* src, size_t size)
{
	unsigned char* d = (unsigned char*)dest;
	const unsigned char* s = (const unsigned char*)src;

	if (d < s){
		// Copy forwards
		for (size_t i = 0; i < size; i++)
			d[i] = s[i];
	}
	else if (d > s){
		// Copy backwards
		for (size_t i = size; i > 0; i--)
			d[i - 1] = s[i - 1];
	}

	return dest;
}

void* mem_set(void* ptr, int value, size_t size)
{
	unsigned char* buff = ptr;

	for (size_t i = 0; i < size; i++){
		buff[i] = (unsigned char)value;
	}

	return ptr;
}

int   mem_compare(const void* ptr1, const void* ptr2, size_t size)
{
	const unsigned char* a = ptr1;
	const unsigned char* b = ptr2;

	for (size_t i = 0; i < size; i++){
		if (a[i] != b[i])
			return a[i] - b[i];
	}

	return 0;
}

const void* mem_find(const void* ptr, int value, size_t size)
{
	const unsigned char* pData = ptr;

	for (size_t i = 0; i < size; i++)	{
		if (pData[i] == (unsigned char)value){
			return &pData[i];
		}
	}

	return NULL;
}
