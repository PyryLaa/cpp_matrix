#include <iostream>
#include <array>
#include "matrix.h"

int main(){
    Matrix m1(2, 3);
    std::array<int, 2> m1_size = m1.get_size();
    std::cout << "Matrix dimensions are: " << m1_size[0] << ',' << m1_size[1] << std::endl;
    m1.populate();
    m1.display();
    return 0; 
}