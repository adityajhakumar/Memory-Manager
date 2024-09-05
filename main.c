#include "memory_manager.h"
#include <stdio.h>

int main() {
    print_memory_stats();

    printf("Allocating 100 bytes...\n");
    void* ptr1 = my_malloc(100);
    if (ptr1) {
        printf("Allocated 100 bytes at address %p\n", ptr1);
    } else {
        printf("Allocation failed\n");
    }
    
    print_memory_stats();

    printf("Allocating 200 bytes...\n");
    void* ptr2 = my_malloc(200);
    if (ptr2) {
        printf("Allocated 200 bytes at address %p\n", ptr2);
    } else {
        printf("Allocation failed\n");
    }

    print_memory_stats();

    printf("Deallocating 100 bytes...\n");
    my_free(ptr1);
    printf("Freed 100 bytes at address %p\n", ptr1);

    print_memory_stats();

    // Clean up
    my_free(ptr2);

    return 0;
}
