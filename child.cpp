// child.cpp
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <vector>
#include <cstring>

int main(int argc, char* argv[]) {

    int file = open(argv[2], O_CREAT | O_WRONLY, S_IRWXU);
    if (file == -1) {
        write(STDERR_FILENO, "An error occured with opening file", 35);
        return 1;
    }
    int temp = ftruncate(file, 0);
    if (temp == -1) {
        write(STDERR_FILENO, "An error occured with clearing file", 36);
        return 1;
    }

    int tmp = dup2(file, STDOUT_FILENO);
    if (tmp == -1) {
        write(STDERR_FILENO, "An error occured with redirecting stdout to file", 48);
        close(file);
        return 1;
    }

    const char* mmap_name = argv[1];
    size_t mmap_size = 4096;

    // Open shared memory
    int fd = shm_open(mmap_name, O_RDONLY, 0666);
    if (fd == -1) {
        write(STDERR_FILENO, "An error occurred with opening shared memory", 45);
        return 1;
    }

    // Map memory
    char* mmap_ptr = (char*)mmap(nullptr, mmap_size, PROT_READ, MAP_SHARED, fd, 0);
    if (mmap_ptr == MAP_FAILED) {
        write(STDERR_FILENO, "An error occurred with mapping memory", 38);
        close(fd);
        return 1;
    }

    std::vector<char> vec;
    for (size_t i = 0; i < mmap_size && mmap_ptr[i] != '\0'; ++i) {
        vec.push_back(mmap_ptr[i]);
        if (mmap_ptr[i] == '\n') {
            for (int j = vec.size() - 2; j >= 0; --j) {
                write(STDOUT_FILENO, &vec[j], 1);
            }
            write(STDOUT_FILENO, "\n", 1);
            vec.clear();
        }
    }

    munmap(mmap_ptr, mmap_size);
    close(file); 
    close(fd);
    return 0;
}

