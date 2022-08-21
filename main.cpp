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
