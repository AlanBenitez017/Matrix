#include "iostream"
#include "matrix.h"

using namespace std;

void print(Matrix& mat){
//Printing the matrixes
   int numRows = mat.getNumRows();
   int numCols = mat.getNumCols();
   int** matrix = mat.getMatrix();
   cout << "[";
   //Iterating the rows
   for(int i = 0; i < numRows; i++){
      cout << "[";
      //Iterating the columns
      for(int j = 0; j < numCols; j++){
         cout << matrix[i][j];
         //Adding a comma
         if(j!=(numCols-1)){
            cout << ", ";
         }
      }
      cout << "]";
      //Adding a comma after the first row
      if(i!=(numRows-1)){
         cout << ", ";
      }
   }
   cout << "]" << endl;
}

int main(){
//Creating objects of type Matrix
   Matrix mat1;
   Matrix mat2(2,3);
   Matrix mat3(2,3);
   Matrix mat9;
   
   mat1.setNumRows(2);
   mat1.setNumCols(3);
   int** matrix1 = new int*[2];
   for(int i = 0; i < 2; i++){
      matrix1[i]= new int[3];
   }
   
   for(int i = 0; i < 2; i++){
      for(int j = 0; j < 3; j++){
         matrix1[i][j] = 3*i+j;
      }
   }
   
   mat1.setMatrix(2, 3, matrix1);
   
   int** matrix2 = new int*[2];
   for(int i = 0; i < 2; i++){
      matrix2[i]= new int[3];
   }
   
   for(int i = 0; i < 2; i++){
      for(int j = 0; j < 3; j++){
         //int **matrix = mat1.getMatrix();
         matrix2[i][j] = 3+i+j;
      }
   }
   mat2.setMatrix(2, 3, matrix2);
   
   //Printing Matrix 1
   cout << "Matrix 1: " << endl;
   print(mat1);
   cout << endl;
   
   //Printing matrix 2
   cout << "Matrix 2: " << endl;
   print(mat2);
   cout << endl;
   
   //Printing the copy constructor
   cout << "Matrix 3: " << endl;
   mat3 = mat1;
   print(mat3);
   cout << endl;
   
   //Printing the default constructor
   cout << "Matrix 9: " << endl;
   print(mat9);
   cout << endl;
   
   //Adding the first two matrixes
   cout << "Matrix 4: " << endl;
   Matrix mat4 = mat1.add(mat2);
   cout << "mat4 = mat1 + mat2" << endl;
   print(mat4);
   cout << endl;
   
   //Substraction matrix 2 minus matrix 1
   cout << "Matrix 4: " << endl;
   mat4 = mat2.substract(mat1);
   cout << "mat4 = mat2 - mat1" << endl;
   print(mat4);
   cout << endl;
   
   //Adding the first matrix and the copy constructor
   cout << "Matrix 5: " << endl;
   Matrix mat5 = mat1.add(mat3);
   cout << "mat5 = mat1 + mat3" << endl;
   print(mat5);
   cout << endl;
   
   //Substraction matrix 1 minus matrix 3
   cout << "Matrix 5: " << endl;
   mat5 = mat1.substract(mat3);
   cout << "mat5 = mat1 - mat3" << endl;
   print(mat5);
   cout << endl;
   
   //Implementing the transpose and copying a constructor
   cout << "Matrix 6: " << endl;
   Matrix mat6 = mat1;
   mat6.transpose();
   cout << "mat6 = transpose()" << endl;
   print(mat6);
   cout << endl;
   
   //Multiplying matrix 2 times matrix 3
   cout << "Matrix 7: " << endl;
   Matrix mat7 = mat2.multiply(mat3);
   cout << "mat7 = mat1 * mat3" << endl;
   print(mat7);
   cout << endl;
   
   //Multyplying matrix 1 times matrix 2
   cout << "Matrix 8: " << endl;
   Matrix mat8 = mat1.multiply(mat2);
   cout << "mat8 = mat1 * mat2" << endl;
   print(mat8);
   cout << endl;
   
   return 0;
}