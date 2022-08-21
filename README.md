# Dynamic 2D Array
In this repository I show how to allocate and free dynamic memory for 2D Array

## Scenario
![](https://server.179.ru/tasks/cpp/total/images/dynamic_array.png)

## Source code in C++
```cpp
#include <iostream>
#include <cstdlib>

short **malloc_2d_array(const size_t rows, const size_t cols) {
    const size_t total_2d_array_size_in_bytes = rows * sizeof(short *) + rows * cols * sizeof(short); 
    void *allocated_memory = std::malloc(total_2d_array_size_in_bytes);
    if (!allocated_memory) {
        std::cerr << "OS cannot allocate memory!" << std::endl;
        return nullptr;
    }

    short **array_2d = static_cast<short **>(allocated_memory);
    short *begin = (short *)(static_cast<char *>(allocated_memory) + rows * sizeof(short *));

    // initialize pointers with the addresses of the first element from the columns
    for (size_t i = 0; i < rows; i++) {
        array_2d[i] = begin + i * cols;
    }

    return array_2d;
}

void free_2d_array(short **array_2d) {
    if (!array_2d) 
        std::cerr << "OS cannot remove memory for array! Because 2d array is null";
    std::free(array_2d);
}
```
