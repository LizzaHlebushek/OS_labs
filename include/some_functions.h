#pragma once
#include "Row_Or_Line.h"
#include "Arguments.h"
#include <iostream>
#include <fstream>

void* multiply_matrices(void* arg);

void get_table1(Row_Or_Line* table1, const size_t lines, std::ifstream& inputFile);
void get_table2(Row_Or_Line* table2, const size_t rows, std::ifstream& inputFile);

void check(size_t lines1, size_t rows1, size_t lines2, size_t rows2);