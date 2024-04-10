//Body of the matrix class
#pragma once
#include <vector>
#include <array>

class Matrix{
 public:
  Matrix(int r, int c);
  std::array<int, 2> get_size() const;
  int get_rows() const;
  int get_cols() const;
  void display() const;
  void populate();

  //Overloaded operators *, +, -

  //These are not defined yet

  Matrix operator*(const Matrix& m) const; //Multiply with other matrix
  Matrix operator*(int s) const; //Multiply with scalar
  Matrix operator+(Matrix& m) const;
  Matrix operator-(Matrix& m) const;

  //Matrix transpose(Matrix& m);
  

  
 private:
  std::array<int, 2> size;
  std::vector<std::vector<int>> data;  

};
