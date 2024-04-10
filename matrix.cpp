#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

Matrix::Matrix(int r, int c){
    size[0] = r;
    size[1] = c;
    data.resize(size[0], std::vector<int>(c, 0));
}

Matrix::~Matrix(){
    std::cout << "Matrix destructor" << std::endl;
}

std::array<int, 2> Matrix::get_size() const{
    return size;
}

int Matrix::get_rows() const{
    return size.at(0);
}

int Matrix::get_cols() const{
    return size.at(1);
}

void Matrix::display() const{
    for(const auto& r : data){
        for(const auto& num : r){
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
}

void Matrix::populate(){
    int max_val = 0;
    int min_val = 0;

    std::cout << "Give the minimum value for the matrix (integer): ";
    std::cin >> min_val;
    std::cout << "\nGive the maximum value for the matrix (integer): ";
    std::cin >> max_val;
    
    std::srand(std::time(nullptr));
    for(int i = 0; i < size.at(0); i++){
        for(int j = 0; j < size.at(1); j++){
            data[i][j] = min_val + rand() % max_val;
        }
    }
}