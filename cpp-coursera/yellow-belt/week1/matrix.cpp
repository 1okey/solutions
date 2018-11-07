#include <iostream>
#include <exception>
#include <string>
#include <vector>
using namespace std;

class Matrix {
public:
  Matrix(){
    rows_ = 0;
    cols_ = 0;
  }
  Matrix(int rows, int cols): rows_(rows), cols_(cols){
    if(rows < 0 || cols < 0){
      throw out_of_range("Matrix can't have negative size");
    }
    rows_ = rows;
    cols_ = cols;
    Reset(rows_, cols_);
  }
  void Reset(int rows, int cols){
    if(rows < 0 || cols < 0){
      throw out_of_range("Reset size can't be negative");
    }
    rows_ = rows;
    cols_ = cols;
    matrix_.assign(rows_, vector<int>(cols_));
  }
  int At(int row, int col) const {
    return matrix_.at(row).at(col);
  }
  int& At(int row, int col){
    return matrix_.at(row).at(col);
  }
  int GetNumRows() const {
    return rows_;
  }
  int GetNumColumns() const {
    return cols_;
  }
private:
  int rows_, cols_;
  vector<vector<int>> matrix_;
};

istream& operator>>(istream & stream, Matrix & m){
  int r,c;
  stream >> r >> c;
  m.Reset(r,c);
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      stream >> m.At(int(i),int(j));

  return stream;
}
ostream& operator<<(ostream & stream, const Matrix &m){
  int r,c;
  r = m.GetNumRows();
  c = m.GetNumColumns();

  stream << r << " " << c << endl;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(j > 0) stream << " ";
      stream << m.At(i,j);
    }
    stream << endl;
  }
  return stream;
}

bool operator==(const Matrix & lhs, const Matrix & rhs) {
  int c = lhs.GetNumColumns();
  int r = lhs.GetNumRows();
  if(c != rhs.GetNumColumns()){
    return false;
  }
  if(r != rhs.GetNumRows()){
    return false;
  }

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if(lhs.At(i,j) != rhs.At(i,j))
        return false;
  return true;
}
Matrix operator+(const Matrix & lhs, const Matrix & rhs) {
  int c = lhs.GetNumColumns();
  int r = lhs.GetNumRows();
  if(c != rhs.GetNumColumns()){
    throw invalid_argument("Matrices are not equal");
  }
  if(r != rhs.GetNumRows()){
    throw invalid_argument("Matrices are not equal");
  }

  Matrix mtrx(r,c);
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++){
      mtrx.At(i,j) = lhs.At(i,j) + rhs.At(i,j);
    }
  return mtrx;
}

int main(){
  std::cout << "Hello" << std::endl;
  return 0;
}

