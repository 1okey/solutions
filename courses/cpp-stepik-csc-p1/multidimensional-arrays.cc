#include <iostream>
#include "test_runner.h"

// Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто
// двумерный целочисленный массив) размера rows×cols, и возвращает транспонированную матрицу MT
// (тоже двумерный целочисленный массив) размера cols×rows. Если в M на пересечении i-ой строки и
// j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице MT тоже
// будет стоять число x, или другими словами MT[j][i]=M[i][j].
//
// Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M.
// Выделять память под массив MT можете любым удобным вам способом. Изменять исходную матрицу нельзя.

int ** createIntMatrix(unsigned rows, unsigned cols){
  int ** m  = new int * [rows];
  m[0] = new int [rows * cols];
  for(unsigned r = 1; r < rows; r++)
    m[r] = m[r - 1] + cols;

  return m;
}

void fillIntMatrix(int ** m, unsigned rows, unsigned cols){
  for(unsigned r = 0; r < rows; r++)
    for(unsigned c = 0; c < cols; c++)
      m[r][c] = c + r;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
  int ** new_m = createIntMatrix(cols, rows);
  for(unsigned r = 0; r < rows; r++)
    for(unsigned c = 0; c < cols; c++)
      new_m[c][r] = m[r][c];

  return new_m;
}

void printIntMatrix(int ** m, unsigned rows, unsigned cols){
  for(unsigned r = 0; r < rows; r++){
    for(unsigned c = 0; c < cols; c++){
      std::cout << m[r][c] << " ";
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}

bool compareMatrices(int ** m, int test_m[][3], unsigned rows, unsigned cols){
  for(unsigned r = 0; r < rows; r++)
    for(unsigned c = 0; c < cols; c++)
      if(m[r][c] != test_m[r][c])
        return false;

  return true;
}

void CheckTranspose(){
  unsigned cols = 2;
  unsigned rows = 3;
  int ** m = createIntMatrix(rows,cols);
  fillIntMatrix(m,rows,cols);
  int ** new_m = transpose(m,rows,cols);
  int test_matrix[2][3] = {
    {0,1,2},
    {1,2,3},
  };
  ASSERT(compareMatrices(new_m, test_matrix, 2, 3));
}

int main(){
  TestRunner runner;
  RUN_TEST(runner, CheckTranspose);
}

