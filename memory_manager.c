#include "memory_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a fixed-size memory pool
#define MEMORY_POOL_SIZE 1024

static char memory_pool[MEMORY_POOL_SIZE];
static size_t free_offset = 0;

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

static Block* free_list = NULL;

void* my_malloc(size_t size) {
    // Ensure size is positive and non-zero
    if (size == 0) return NULL;

    // Align size to the nearest multiple of sizeof(Block)
    size = (size + sizeof(Block) - 1) & ~(sizeof(Block) - 1);

    // Check if there is a suitable block in the free list
    Block** curr = &free_list;
    while (*curr) {
        if ((*curr)->size >= size) {
            Block* allocated_block = *curr;
            *curr = allocated_block->next;
            return (char*)allocated_block + sizeof(Block);
        }
        curr = &(*curr)->next;
    }

    // Check if there is enough space in the memory pool
    if (free_offset + size + sizeof(Block) > MEMORY_POOL_SIZE) {
        return NULL;
    }

    // Allocate memory from the pool
    Block* new_block = (Block*)(memory_pool + free_offset);
    free_offset += size + sizeof(Block);
    new_block->size = size;
    new_block->next = NULL;

    return (char*)new_block + sizeof(Block);
}

void my_free(void* ptr) {
    if (!ptr) return;

    Block* block_to_free = (Block*)((char*)ptr - sizeof(Block));
    block_to_free->next = free_list;
    free_list = block_to_free;
}

void print_memory_stats() {
    size_t allocated = free_offset;
    size_t free = MEMORY_POOL_SIZE - allocated;

    printf("Memory Pool Size: %d bytes\n", MEMORY_POOL_SIZE);
    printf("Allocated: %zu bytes\n", allocated);
    printf("Free: %zu bytes\n", free);
}
