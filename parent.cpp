// parent.cpp
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <cstring>

int main() {
    std::string file_name1;
    std::string file_name2;
    char c = 1;
    write(STDOUT_FILENO, "Enter file name 1: ", 20);
    while (c != '\n') {
        read(STDIN_FILENO, &c, sizeof(char));
        if (c != '\n') {
            file_name1 += c;
        }  
    }
    c = 1;

    write(STDOUT_FILENO, "Enter file name 2: ", 20);
    while (c != '\n') {
        read(STDIN_FILENO, &c, sizeof(char));
        if (c != '\n') {
            file_name2 += c;
        }      
    }

    const size_t mmap_size = 4096;
    const char* mmap_name1 = "/shared_mem1";
    const char* mmap_name2 = "/shared_mem2";

    // Create shared memory regions
    int fd1 = shm_open(mmap_name1, O_CREAT | O_RDWR, 0666);
    int fd2 = shm_open(mmap_name2, O_CREAT | O_RDWR, 0666);
    if (fd1 == -1 || fd2 == -1) {
        write(STDERR_FILENO, "An error occurred with creating shared memory", 46);
        return 1;
    }

    ftruncate(fd1, mmap_size);
    ftruncate(fd2, mmap_size);

    char* mmap_ptr1 = (char*)mmap(nullptr, mmap_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
    char* mmap_ptr2 = (char*)mmap(nullptr, mmap_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    if (mmap_ptr1 == MAP_FAILED || mmap_ptr2 == MAP_FAILED) {
        write(STDERR_FILENO, "An error occurred with mapping memory", 38);
        return 1;
    }

    pid_t process_id1 = fork();
    pid_t process_id2 = fork();
    if (process_id1 == 0 && process_id2 > 0) {
        execl("child1", "child1", mmap_name1, file_name2.c_str(), NULL);
        return 1;
    }
    if (process_id1 > 0 && process_id2 == 0) {
        execl("child2", "child2", mmap_name2, file_name2.c_str(), NULL);
        return 1;
    }

    std::string input;
    size_t offset1 = 0, offset2 = 0;
    while (std::getline(std::cin, input)) {
        input += '\n';
        if (input.size() > 11) {
            if (offset2 + input.size() >= mmap_size) break;
            memcpy(mmap_ptr2 + offset2, input.c_str(), input.size());
            offset2 += input.size();
        } else {
            if (offset1 + input.size() >= mmap_size) break;
            memcpy(mmap_ptr1 + offset1, input.c_str(), input.size());
            offset1 += input.size();
        }
    }

    kill(process_id1, SIGTERM);
    kill(process_id2, SIGTERM);

    munmap(mmap_ptr1, mmap_size);
    munmap(mmap_ptr2, mmap_size);
    shm_unlink(mmap_name1);
    shm_unlink(mmap_name2);

    wait(nullptr);
    wait(nullptr);
    return 0;
}
