#pragma once
#include "Row_Or_Line.h"

class Arguments 
{
public:
    const Row_Or_Line* table1; 
    const Row_Or_Line* table2; 
    Row_Or_Line* result_table;
    int _thread_id;            
    int _num_of_threads;            

public:
    Arguments(Row_Or_Line* arr1, Row_Or_Line* arr2,  Row_Or_Line* arr3, int n1, int n2);
    Arguments();

};