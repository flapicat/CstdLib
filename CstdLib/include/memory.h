#pragma once
#include "types.h"

void* mem_copy(void* dest, const void* src, size_t size);
void* mem_move(void* dest, const void* src, size_t size);
void* mem_set(void* ptr, int value, size_t size);
int   mem_compare(const void* ptr1, const void* ptr2, size_t size);
const void* mem_find(const void* ptr, int value, size_t size);
