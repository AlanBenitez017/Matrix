#include "iostream"
#include "matrix.h"

using namespace std;

void print(Matrix& mat){
   int numRows = mat.getNumRows();
   int numCols = mat.getNumCols();
   int** matrix = mat.getMatrix();
   cout << "[";
   for(int i = 0; i < numRows; i++){
      cout << "[";
      for(int j = 0; j < numCols; j++){
         cout << matrix[i][j];
         if(j!=(numCols-1)){
            cout << ", ";
         }
      }
      cout << "]";
      if(i!=(numRows-1)){
         cout << ", ";
      }
   }
   cout << "]" << endl;
}

int main(){
   Matrix mat1;
   Matrix mat2(2,3);
   Matrix mat3(2,3);

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
   
   cout << "Matrix 1: " << endl;
   print(mat1);
   cout << endl;
   
   cout << "Matrix 2: " << endl;
   print(mat2);
   cout << endl;
   
   cout << "Matrix 3: " << endl;
   mat3 = mat1;
   print(mat3);
   cout << endl;
   
   cout << "Matrix 4: " << endl;
   Matrix mat4 = mat1.add(mat2);
   cout << "mat4 = mat1 + mat2" << endl;
   print(mat4);
   cout << endl;
   
   cout << "Matrix 4: " << endl;
   mat4 = mat2.substract(mat1);
   cout << "mat4 = mat2 - mat1" << endl;
   print(mat4);
   cout << endl;
   
   cout << "Matrix 5: " << endl;
   Matrix mat5 = mat1.add(mat3);
   cout << "mat5 = mat1 + mat3" << endl;
   print(mat5);
   cout << endl;
   
   cout << "Matrix 5: " << endl;
   mat5 = mat1.substract(mat3);
   cout << "mat5 = mat1 - mat3" << endl;
   print(mat5);
   cout << endl;
   
   cout << "Matrix 6: " << endl;
   Matrix mat6 = mat1;
   mat6.transpose();
   cout << "mat6 = transpose()" << endl;
   print(mat6);
   cout << endl;
   
   cout << "Matrix 7: " << endl;
   Matrix mat7 = mat1.multiply(mat6);
   cout << "mat7 = mat1 * mat6" << endl;
   print(mat7);
   cout << endl;
   
   cout << "Matrix 8: " << endl;
   Matrix mat8 = mat1.multiply(mat2);
   cout << "mat8 = mat1 * mat2" << endl;
   print(mat8);
   cout << endl;
   
   return 0;
}