/*Alan Benitez
COP 3014
Dr. Amitabh Mishra
04/26/2020/
*/
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;

class Matrix{

   public:
      int numRows;
      int numCols;
      int** matrix;
      
      Matrix();
      ~Matrix();
      
      Matrix(int numRows, int numCols);
      Matrix(const Matrix& mat2);
      
      Matrix add(const Matrix& mat2);
      Matrix substract(const Matrix& mat2);
      Matrix multiply(const Matrix& mat2);
      Matrix transpose();

      int getNumRows();
      void setNumRows(int numRows);
      int getNumCols();
      void setNumCols(int numCols);
      int** getMatrix();
      void setMatrix(int numRows, int numCols, int** matrix);

};

#endif





