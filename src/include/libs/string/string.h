#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>

void *memset(void *pointer, uint32_t value, size_t size);

void *memcpy(void *destination, const void *src, size_t size);

int memcmp(const void *pointer1, const void *pointer2, size_t size);

#endif