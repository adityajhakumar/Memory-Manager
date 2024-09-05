
# 🧠 Memory Manager


## Overview

The Memory Manager project is a simple simulation of a dynamic memory allocator and deallocator, implemented in C. It mimics basic memory management operations typically provided by functions like `malloc` and `free`. This project serves as an educational tool to understand how dynamic memory management works at a fundamental level.

## Problem Statement

In many systems, dynamic memory allocation is a critical feature that allows programs to request and release memory at runtime. The goal of this project is to create a basic memory manager that simulates these operations:

1. **Memory Allocation (`my_malloc`)**: Allocate a block of memory of a specified size from a fixed-size memory pool.
2. **Memory Deallocation (`my_free`)**: Release a previously allocated block of memory, making it available for future allocations.
3. **Memory Statistics (`print_memory_stats`)**: Display the current status of the memory pool, including the amount of allocated and free memory.

### Requirements

1. Implement a simple memory allocator and deallocator.
2. Use a fixed-size memory pool for simulation.
3. Track memory usage and handle allocations and deallocations.
4. Provide statistics about the memory pool status.

## Implementation

### Directory Structure

- `src/`
  - `main.c`: Contains the main function and test cases for the memory manager.
  - `memory_manager.c`: Implements the memory manager functions.
  - `memory_manager.h`: Declares the memory manager functions and data structures.
- `include/`
  - `memory_manager.h`: Header file for public interface (same as `src/memory_manager.h`).
- `tests/`
  - `test_memory_manager.c`: Contains unit tests for the memory manager functions.
- `README.md`: Project overview and instructions.

### Memory Manager Functions

1. **`void* my_malloc(size_t size)`** 🧩
   - Allocates a block of memory of the specified size from the memory pool.
   - Returns a pointer to the allocated memory, or `NULL` if there is not enough space.

2. **`void my_free(void* ptr)`** 🔄
   - Frees a previously allocated block of memory, making it available for future allocations.

3. **`void print_memory_stats()`** 📊
   - Prints the current status of the memory pool, including allocated and free memory.

### Example Usage

After compiling the project, you can run the `memory_manager` executable to see the memory manager in action:

```powershell
.\memory_manager.exe
```

**Expected Output:**

```
Memory Pool Size: 1024 bytes
Allocated: 0 bytes
Free: 1024 bytes
Allocating 100 bytes...
Allocated 100 bytes at address 0x12345678
Memory Pool Size: 1024 bytes
Allocated: 100 bytes
Free: 924 bytes
Allocating 200 bytes...
Allocated 200 bytes at address 0x12345679
Memory Pool Size: 1024 bytes
Allocated: 300 bytes
Free: 724 bytes
Deallocating 100 bytes...
Freed 100 bytes at address 0x12345678
Memory Pool Size: 1024 bytes
Allocated: 200 bytes
Free: 824 bytes
```

### Compilation

To compile the project, use the following command:

```powershell
gcc -o memory_manager src\main.c src\memory_manager.c -Iinclude
```

To compile and run the unit tests:

```powershell
gcc -o test_memory_manager src\test_memory_manager.c src\memory_manager.c -Iinclude
.\test_memory_manager.exe
```

### Testing

The project includes basic unit tests to validate the functionality of the memory manager. The tests cover:

- Allocating and freeing memory.
- Handling allocation failures.
- Checking memory pool status.

## Future Enhancements 🚀

- Implement more sophisticated memory management techniques, such as memory compaction and fragmentation handling.
- Add support for multithreading and concurrent memory access.
- Expand testing to cover additional edge cases and performance benchmarks.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to replace the logo URLs with your actual images or adjust any other elements as needed!
