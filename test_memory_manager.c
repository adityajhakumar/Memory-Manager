#include "memory_manager.h"
#include <stdio.h>

void run_tests() {
    printf("Starting tests...\n");

    void* ptr1 = my_malloc(50);
    void* ptr2 = my_malloc(150);

    if (ptr1) {
        printf("Test 1 Passed: Allocated 50 bytes at address %p\n", ptr1);
    } else {
        printf("Test 1 Failed: Allocation failed\n");
    }

    if (ptr2) {
        printf("Test 2 Passed: Allocated 150 bytes at address %p\n", ptr2);
    } else {
        printf("Test 2 Failed: Allocation failed\n");
    }

    my_free(ptr1);
    my_free(ptr2);

    void* ptr3 = my_malloc(1000);
    if (ptr3 == NULL) {
        printf("Test 3 Passed: Allocation failed as expected\n");
    } else {
        printf("Test 3 Failed: Allocation succeeded unexpectedly\n");
    }

    print_memory_stats();

    printf("Tests complete.\n");
}

int main() {
    run_tests();
    return 0;
}
