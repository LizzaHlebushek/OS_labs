#include "Row_Or_Line.h"


Row_Or_Line::Row_Or_Line() {
    _length = 0;
    _array = new double*[0];
}

Row_Or_Line::Row_Or_Line(size_t len){
    _length = len;
    _array = new double*[_length];
    
    for (int i = 0; i < _length; ++i) {
        _array[i] = new double[2];
    }
}

Row_Or_Line::Row_Or_Line(const Row_Or_Line& other){
    _length = other._length;
    _array = new double*[_length];
    for (size_t i = 0; i < _length; ++i) {
        _array[i] = new double[2];
        _array[i][0] = other._array[i][0];
        _array[i][1] = other._array[i][1];

    }
}

int Row_Or_Line::size() const{
    return _length;
}

void Row_Or_Line::resize(size_t len) {
    for (size_t i = 0; i < _length; ++i) {
        delete[] _array[i];  
    }
    delete[] _array; 
    _length = len;
    _array = new double*[_length];
    
    for (int i = 0; i < _length; ++i) {
        _array[i] = new double[2];
    }


}

void Row_Or_Line::setElement(size_t index, double value1, double value2) {
    if (index >= 0 && index < _length) {
        _array[index][0] = value1;
        _array[index][1] = value2;
    } else {
        throw "invalid index in setElement";
    }
}

std::array<double, 2> Row_Or_Line::multiply(const Row_Or_Line& other) const{
    //std::cout << " multiply called" << std::endl;
    std::array<double, 2> result = {0, 0}; 
    for (size_t i =0; i < _length; ++i){
        result[0] += (_array[i][0]*other._array[i][0] - _array[i][1]*other._array[i][1]);
        result[1] += (_array[i][0]*other._array[i][1] + _array[i][1]*other._array[i][0]);
        //std::cout << " in for, i =" << i<< "result:" << result[0] << " " << result[1]<<'i' <<std::endl;
    }
    return result;
}

Row_Or_Line::~Row_Or_Line() {
    for (size_t i = 0; i < _length; ++i) {
        delete[] _array[i];  
    }
    delete[] _array; 
    _length = 0; 
}
