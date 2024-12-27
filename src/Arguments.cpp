#include "Row_Or_Line.h"
#include "Arguments.h"


Arguments::Arguments(Row_Or_Line* arr1, Row_Or_Line* arr2, Row_Or_Line* arr3, int n1, int n2)
        : table1(arr1), table2(arr2), result_table (arr3), _thread_id(n1), _num_of_threads(n2) {}

Arguments::Arguments(){
    table1 = nullptr; 
    table2 = nullptr; 
    result_table = nullptr; 
    _thread_id = 0;            
    _num_of_threads = 0; 
}