#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//2.1 adt2.1
class NaturalNumber{
public:
  NaturalNumber Zero();
  bool IsZero();
  NaturalNumber Add(NaturalNumber y);
  bool Equal(NaturalNumber y);
  NaturalNumber Successor();
  NaturalNumber Substract(NaturalNumber y);
};
  
//adt2.3 다항식
class Polynomial; //전방선언

class Term{
friend Polynomial;
private:
  float coef; //계수
  int exp; //지수
};

class Polynomial{
//<지수, 계수>
private:
  Term *termArray; //0이 아닌 항의 배열
  int capacity; //termArray의 크기
  int terms; //0이 아닌 항의 수
public:
  Polynomial();
  Polynomial Add(Polynomial poly); //합
  Polynomial Mult(Polynomial poly); //곱
  float Eval(float f);
};
// p2.8, 2.9 ?

