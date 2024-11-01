#include <libs/string/string.h>


void *memset(void *pointer, uint32_t value, size_t size)
{
    uint8_t *buffer_pointer = (uint8_t *)pointer;

    for (size_t i = 0; i < size; i++)
    {   
        buffer_pointer[i] = value;
    }

    return pointer;
}

void *memcpy(void *destination, const void *source, size_t size)
{
    uint8_t *dest8 = (uint8_t *)destination;
    const uint8_t *src8 = (uint8_t *)source;

    for (size_t i = 0; i < size; i++)
    {
        dest8[i] = src8[i];
    }

    return dest8;
}

int memcmp(const void *pointer1, const void *pointer2, size_t size)
{
    const unsigned char *ptr1 = pointer1;
    const unsigned char *ptr2 = pointer2;

    for (size_t i = 0; i <size; i++, ptr1++, ptr2++)
    {
        if (*ptr1 != *ptr2)
        {
            return *ptr1 - *ptr2;
        }
    }
    return 0;
}