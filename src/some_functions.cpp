#include "some_functions.h"



void* multiply_matrices(void* arg) {
    try {
        Arguments* data = (Arguments*) arg;
        size_t pair[2] = {0, 0};
        pair[0] = data->_thread_id / data->result_table->size();
        pair[1] = data->_thread_id % data->result_table->size();
        std::array<double, 2> result = {0, 0}; 
        while (pair[0] < data->result_table->size())
        {
            result = data->table1[pair[0]].multiply(data->table2[pair[1]]);
            data->result_table[pair[0]].setElement(pair[1], result[0], result[1]);
            pair[1] +=  data->_num_of_threads;
            pair[0] += pair[1] / data->result_table[0].size();
            pair[1]%= data->result_table[0].size();
        }
        pthread_exit(0);
    } catch (const char* msg) {
        std::cerr << "Caught exception: " << msg << std::endl;
    }
    pthread_exit(0);
} 


void get_table1(Row_Or_Line* table1, const size_t lines, std::ifstream& inputFile){
    size_t rows = table1[0].size();
    std::string content;
    char ch;
    double real = 0;
    double im = 0;
    inputFile.get(ch);
    bool flag = false;
    int flag_minus = 1;
    for (size_t i = 0; i < lines; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            while (inputFile.get(ch)) { //get im number
                if ((ch < '0' || ch > '9') && ch!='.' && ch!='+' && ch!='i' && ch!='-' && ch!=' ' && ch!='\n' && ch!=EOF) std::cerr << "Invalid simbol "<< ch << " in inp file" << std::endl;
                if (ch == ' ' or ch == '\n') {
                    if(flag) break;
                    real = std::stod(content) * flag_minus;
                    content = "";
                    break;
                }
                if ((ch >= '0' && ch <= '9') || ch == '.') {
                    content += ch;
                } 
                
                if (ch == '-'){ 
                    if (content.size() == 0 ) {
                        real = 0;
                    } else {
                        real = std::stod(content) * flag_minus;
                        content = "";
                        flag = true;
                    }
                    flag_minus = -1;
                    
                }
                if (ch == '+'){
                    if (content.size() == 0 ) std::cerr << "No number before '+' in inp file" << std::endl; 
                    real = std::stod(content) * flag_minus;
                    content = "";
                    flag_minus = 1;
                    flag = true;
                }
                if (ch == 'i'){
                    if (content.size() != 0 ){
                        im = std::stod(content) * flag_minus;
                        content = "";
                    } else {
                        im = flag_minus;
                    }
                    flag = true;
                    if (im == 0) im = 1;
                }
            }
            table1[i].setElement(j, real, im);
            im = 0;
            real = 0;
            flag = false;
            flag_minus = 1;         
        }
    }
}



void get_table2(Row_Or_Line* table2, const size_t rows, std::ifstream& inputFile){
    size_t lines = table2[0].size();
    std::string content;
    char ch;
    double real = 0;
    double im = 0;
    inputFile.get(ch);
    bool flag = false;
    int flag_minus = 1;
    for (size_t i = 0; i < lines; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            while (inputFile.get(ch)) { //get im number
                if ((ch < '0' || ch > '9') && ch!='.' && ch!='+' && ch!='i' && ch!='-' && ch!=' ' && ch!='\n') std::cerr << "Invalid simbol "<< ch << " in inp file" << std::endl;
                if (ch == ' ' or ch == '\n') {
                    if(flag) break;
                    real = std::stod(content) * flag_minus;
                    content = "";
                    flag = true;
                    break;
                }
                if ((ch >= '0' && ch <= '9') || ch == '.') {
                    content += ch;
                } 
                
                if (ch == '-'){ 
                    if (content.size() == 0 ) {
                        real = 0;
                    } else {
                        real = std::stod(content) * flag_minus;
                        content = "";
                        flag = true;
                    }
                    flag_minus = -1;
                    
                }
                if (ch == '+'){
                    if (content.size() == 0 ) std::cerr << "No number before '+' in inp file" << std::endl; 
                    real = std::stod(content) * flag_minus;
                    content = "";
                    flag_minus = 1;
                    flag = true;
                }
                if (ch == 'i'){
                    if (content.size() != 0 ){
                        im = std::stod(content) * flag_minus;
                        content = "";
                    } else {
                        im = flag_minus;
                    }
                    flag = true;
                    if (im == 0) im = 1;
                }
            }
            if (!flag) {
                real = std::stod(content) * flag_minus;
            } 
            table2[j].setElement(i, real, im); 
            im = 0;
            real = 0;
            flag = false;
            flag_minus = 1;         
        } 
    }
}

void check(size_t lines1, size_t rows1, size_t lines2, size_t rows2){
    if (lines2 != rows1) {
        throw "wrong sizes of tables";
    }
}