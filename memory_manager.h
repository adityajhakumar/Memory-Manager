#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>

// Function prototypes
void* my_malloc(size_t size);
void my_free(void* ptr);
void print_memory_stats();

#endif // MEMORY_MANAGER_H
