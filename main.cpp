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

void initialize_2d_array(short **array_2d, const size_t rows, const size_t cols) {
    if (!array_2d)
        std::cerr << "We cannot initialize! Because 2d array is null";
    else {
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) 
                array_2d[i][j] = rand() % 20;
    }
}

void print_2d_array(short **array_2d, const size_t rows, const size_t cols) {
    if (!array_2d)
        std::cerr << "We cannot print! Because 2d array is null";
    else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) 
                std::cout << array_2d[i][j] << "\t";
            std::cout << std::endl;
        }
    }
}

int main()
{
    const size_t rows = 4, cols = 5;
    short **array_2d = malloc_2d_array(rows, cols);

    initialize_2d_array(array_2d, rows, cols);
    print_2d_array(array_2d, rows, cols);

    free_2d_array(array_2d);

    return 0;
}
