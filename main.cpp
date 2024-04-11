#include <iostream>
#include <array>
#include "matrix.h"

int main(){
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    std::array<int, 2> m1_size = m1.get_size();
    std::cout << "Matrix dimensions are: " << m1_size[0] << ',' << m1_size[1] << std::endl;
    m1.populate();
    m2.populate();
    std::cout << "Matrix 1" << std::endl;
    m1.display();

    std::cout << "Matrix 2" << std::endl;
    m2.display();

    Matrix m3 = m1 * m2;
    std::cout << "Matrix 1 * matrix 2" << std::endl;
    m3.display();
    Matrix m4 = m1 * 4;
    std::cout << "Matrix 1 * 4" << std::endl;
    m4.display();

    Matrix m5 = m1 + m2;
    std::cout << "Matrix 1 + matrix 2" << std::endl;
    m5.display();

    Matrix m6 = m1 - m2;
    std::cout << "Matrix 1 - matrix 2" << std::endl;
    m6.display();

    Matrix m7 = m1.transpose();
    std::cout << "Matrix 1 transposed" << std::endl;
    m7.display();

    Matrix m8(5, 4);
    m8.populate();
    Matrix m9 = m8.transpose();
    std::cout << "Matrix 8" << std::endl;
    m8.display();
    std::cout << "Matrix 8 transposed" << std::endl;
    m9.display();

    return 0; 
}