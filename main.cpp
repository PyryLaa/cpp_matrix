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

    Matrix m3 = m1*m2;
    std::cout << "Matrix 3" << std::endl;
    m3.display();
    Matrix m4 = m1*4;
    std::cout << "Matrix 4" << std::endl;
    m4.display();

    return 0; 
}