#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ADT 2.4 희소행렬
class SparseMatrix{
private:
  int rows, cols, terms, capacity; //capacity: smArray의 크기
  MartixTerm *smArray;
public:
  SparseMatrix(int r, int c, int t); // r행, c열, t개의 0이 아닌 항
  SparseMatrix Transpose(); //전치
  SparseMatrix FastTranspose();
  SparseMatrix Add(SparseMatrix b); // 합
  SparseMatrix Multiply(SparseMatrix b); //곱
  void StoreSum(const int sum, const int r, const int c);
};
//원소
class MartixTerm{ //0이 아닌 항들의 배열. index < terms
  friend class SparseMatrix;
private:
  int row, col, value; 
};

//행렬의 전치
SparseMatrix SparseMatrix::Transpose(){
  SparseMatrix b(cols, rows, terms);//전치될 행렬
  if(terms > 0){ // 0이 아닌 항이 적어도 1개 있을 때
    int currentB =0; //index
    for(int c=0;c<cols;c++){ // *this의 '열'j에 있는 모든 원소에 대해
      for(int i=0; i<terms; i++) //0이 아닌 항들의 배열. 원소 terms개 동안 반복
        if(smArray[i].col == c)// martixterm배열 중 c열인지 확인
        {
          b.smArray[currentB].row = c; //열->행
          b.smArray[currentB].col = smArray[i].row; //행->열
          b.smArray[currentB++].value = smArray[i].value; //index++
        }
    }
  }
  return b;
};
// 행렬 빠른 전치
SparseMatrix SparseMatrix::FastTranspose(){
  SparseMatrix b(cols, rows, terms);
  if(terms>0){
    int *rowSize = new int[cols]; // rowSize, rowStart는 항 배열(smArray)의 포인터 역할
    int *rowStart = new int[cols]; 
    fill(rowSize, rowSize + cols, 0); //초기화
    for(int i=0; i<terms; i++) rowSize[smArray[i].col]++; // 배열[i]의 열에 대한 항의 수를 센다. 여기서 i는 *this 항 배열의 index (smArray index)
    
    rowStart[0]=0; //초기화
    for(int i=1; i<cols; i++) rowStart[i] = rowStart[i-1]+rowSize[i-1]; // b의 i행을 위한 배열에 대한 index 만듦. 여기서 i는 b의 행(*this의 열)
    
    // 항을 '하나씩' 전치한다
    for(int i=0; i<terms; i++) //여기서 i는 *this 항 배열의 index (smArray index)
    {
      int j = rowStart[smArray[i].col]; // (*this)배열 i번째 원소의 '열'에 대한, (b) 배열공간 '행'에 대한 index(j)를 찾음 <smArray>
      b.smArray[j].row = smArray[i].col; // *this 열 -> b 행. row != rows
      b.smArray[j].col = smArray[i].row; // *this 행 -> b 열. col != cols
      b.smArray[j].value = smArray[i].value; // 값 이동
      rowStart[smArray[i].col]++; // b smArray 의 행에 원소 크기가 올라감
    }
    delete [] rowSize;
    delete [] rowStart;
  }
  return b;
};
// 행렬 곱셈 ??