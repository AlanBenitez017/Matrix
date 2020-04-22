/*Alan Benitez
COP 3014
Dr. Amitabh Mishra
04/26/2020/
*/
#include "iostream" 
#include "matrix.h"

//Default Constructor
Matrix::Matrix(){
   numRows = 0;
   numCols = 0;
   matrix = NULL;
}

//Destructor
Matrix::~Matrix(){
   for(int i = 0; i < numRows; i++){
      delete []matrix[i];
   }
   delete []matrix;
}

//Overloaded constructor
Matrix::Matrix(int numRows, int numCols){
   this->numRows = numRows;
   this->numCols = numCols;
   this->matrix = new int*[numRows];
   for(int i = 0; i < numRows; i++){
      this->matrix[i] = new int[numCols];
   }
}

//Copy Constructor
Matrix::Matrix(const Matrix& mat2){
   this->numRows = mat2.numRows;
   this->numCols = mat2.numCols;
   this->matrix = new int* [mat2.numRows];
   for(int i = 0; i < mat2.numRows; i++){
      this->matrix[i] = new int[mat2.numCols];
      for(int j = 0; j < mat2.numCols; j++){
         this->matrix[i][j] = mat2.matrix[i][j]; 
      }
   }
} 

Matrix Matrix::add(const Matrix& mat2){
   Matrix result(numRows, numCols);
   if((this->numRows == mat2.numRows) && (this->numCols == mat2.numCols)){
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < numCols; j++){
            result.matrix[i][j] = matrix[i][j] + mat2.matrix[i][j];
         }
      }
   
   }
   else{
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < numCols; j++){
            result.matrix[i][j] = 0;
         }
      }
   }
   return result;
}

Matrix Matrix::substract(const Matrix& mat2){
   Matrix result(numRows, numCols);
   if((this->numRows == mat2.numRows) && (this->numCols == mat2.numCols)){
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < numCols; j++){
            result.matrix[i][j] = matrix[i][j] - mat2.matrix[i][j];
         }
      }
   
   }
   else{
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < numCols; j++){
            result.matrix[i][j] = 0;
         }
      }
   }
   return result;
}

Matrix Matrix::multiply(const Matrix& mat2){
   if(this->numCols == mat2.numCols){
      Matrix result(numRows, mat2.numCols);
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < numCols; j++){
            result.matrix[i][j] += matrix[i][j] * mat2.matrix[i][j];
            /*for(int k = 0; k < this-> numCols; k++){
               result.matrix[i][j] += matrix[i][k] * mat2.matrix[k][j];
            }*/
         }
      }
   return result;
   }
   else{
      Matrix result(numRows, mat2.numCols);
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < numCols; j++){
            result.matrix[i][j] = 0;
         }
      }
   return result;
   }
}

Matrix Matrix::transpose(){
   Matrix result(numRows, numCols);
   for(int i = 0; i < numRows; i++){
      for(int j = 0; j < numCols; j++){
         result.matrix[j][i];
      }
   }
   return result;
}

int Matrix::getNumRows(){
   return this->numRows;
}

void Matrix::setNumRows(int numRows){
   int** newMatrix = new int*[numRows];
   for(int i = 0; i < numRows; i++){
      newMatrix[i] = new int[numCols];
   }
   /*for(int i = 0; i < numRows; i++){
      delete []matrix[i];
   }*/
   delete []matrix;
   
   this->numRows = numRows;
   this->matrix = newMatrix;
}

//Getting the columns
int Matrix::getNumCols(){
   return this->numCols;
}

//Setting the columns
void Matrix::setNumCols(int numCols){
   for(int i = 0; i < numRows; i++){
      delete matrix[i];
      matrix[i] = new int[numCols];
   }
   this->numCols = numCols;
}

//Getting the matrix
int** Matrix::getMatrix(){
   return this->matrix;
}

//Setting the matrix
void Matrix::setMatrix(int numRows, int numCols, int** matrix){
   for(int i = 0; i < numRows; i++){
      for(int j = 0; j < numCols; j++){
         this->matrix[i][j] = matrix[i][j];
      }
   }
}





