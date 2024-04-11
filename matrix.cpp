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
    for(int i = 0; i < size.at(1)*3; i++){
        std::cout << '*';
    }
    std::cout << std::endl;
    for(const auto& r : data){
        for(const auto& num : r){
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    for(int i = 0; i < size.at(1)*3; i++){
        std::cout << '*';
    }
    std::cout << std::endl;
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

//Overloaded operators

//A*B
Matrix Matrix::operator*(const Matrix& m) const{
    if(size.at(1) != m.size.at(0)){
        std::cout << "Matrices are incompatible for multiplication" << std::endl;
        Matrix result(0,0);
        return result;
    }else{
        Matrix result(size.at(0), m.size.at(1));
        for(int i = 0; i < size.at(0); i++){
            for(int j = 0; j < m.size.at(1); j++){
                for(int k = 0; k < size.at(1); k++){
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }  
}

//A*scalar
Matrix Matrix::operator*(int s) const{
    Matrix result(size.at(0), size.at(1));
    for(int i = 0; i < size.at(0); i++){
        for(int j = 0; j < size.at(1); j++){
            result.data[i][j] = data[i][j] * s;
        }
    }
    return result;
}

//A+B
Matrix Matrix::operator+(Matrix& m)const{
    if(size.at(0) != m.size.at(0) || size.at(1) != m.size.at(1)){
        Matrix result(0,0);
        std::cout << "Matrices incompatible for addition" << std::endl;
        return result;
    }else{
        Matrix result(size.at(0), size.at(1));
        for(int i = 0; i < size.at(0); i++){
            for(int j = 0; j < size.at(1); j++){
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }
}

//A-B
Matrix Matrix::operator-(Matrix& m) const{
    if(size.at(0) != m.size.at(0) || size.at(1) != m.size.at(1)){
        Matrix result(0,0);
        std::cout << "Matrices incompatible for subtraction" << std::endl;
        return result;
    }else{
        Matrix result(size.at(0), size.at(1));
        for(int i = 0; i < size.at(0); i++){
            for(int j = 0; j < size.at(1); j++){
                result.data[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return result;
    }
}

//Transpose
Matrix Matrix::transpose() const{
    Matrix result(size.at(1), size.at(0));
    for(int i = 0; i < size.at(0); i++){
        for(int j = 0; j < size.at(1); j++){
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}