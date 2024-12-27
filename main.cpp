#include "Row_Or_Line.h"
#include "Arguments.h"
#include "some_functions.h"
#include <iostream>
#include <fstream>
#include <chrono>


 


int main(int argc, char *argv[]){
    int num_threads;
    if (argc > 1) {
        num_threads = atoi(argv[1]);
    } else {
        num_threads = 1;
    }
    auto start = std::chrono::high_resolution_clock::now(); 
    if (num_threads <= 0) throw "the number of threads must be greater than 0";
    pthread_t threads[num_threads];
    Arguments arg_array[num_threads];

    std::ifstream file("input.txt"); 
    if (!file.is_open()) {
        std::cerr << "Error in opening file!" << std::endl;
        return 1;
    }
    int num_of_tests;
    file >> num_of_tests;
    size_t lines1, rows1;
    size_t lines2, rows2;
    for (int i = 0; i < num_of_tests; ++i){

        
        file >> lines1 >> rows1; 
        Row_Or_Line table1[lines1];  
        for (size_t i = 0; i < lines1; ++i) {
            table1[i].resize(rows1);
        }
        get_table1(table1, lines1, file);
        for (size_t i = 0; i < lines1; ++i) {
            for (size_t j = 0; j < rows1; ++j) {
            }
        }

        file >> lines2 >> rows2;
        Row_Or_Line table2[rows2]; 

        for (size_t i = 0; i < rows2; ++i) {
            table2[i].resize(lines2);
        }
        get_table2(table2, rows2, file);

        
        for (size_t i = 0; i < rows2; ++i) {
            for (size_t j = 0; j < lines2; ++j) {
            }
        } 

        Row_Or_Line result_table[lines1]; 
        for (size_t i = 0; i < lines1; ++i) {
            result_table[i].resize(rows2);
        }
        

        for (int i = 0; i < num_threads; i++) {
            arg_array[i].result_table = result_table;
            arg_array[i].table1 = table1;
            arg_array[i].table2 = table2;
            arg_array[i]._thread_id = i;
            arg_array[i]._num_of_threads = num_threads;
            pthread_create(&threads[i], NULL, multiply_matrices, (void*)&arg_array[i]);
        }
        for (int i = 0; i < num_threads; i++) {
            pthread_join(threads[i], NULL);
        }

        for (size_t i = 0; i < lines1; ++i) {
            for (size_t j = 0; j < rows1; ++j) {
            }
        }

        for (size_t i = 0; i < rows2; ++i) {
            for (size_t j = 0; j < lines2; ++j) {
            }
        }

        std::cout<< "--------test "<< i<< " ------ starting with " << lines1 << ' ' << lines2 << "---------"<< std::endl;
        for (size_t i = 0; i < lines1; ++i) {
            for (size_t j = 0; j < rows2; ++j) {
                std::cout << result_table[i]._array[j][0] << ' ' << result_table[i]._array[j][1] << 'i' << ' ';
            }
            std::cout << std::endl; 
        }
        std::cout<< "------------------"<< std::endl;
   
    } 
    file.close(); 
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << " seconds" << std::endl;


}