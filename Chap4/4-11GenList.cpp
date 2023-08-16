#include <iostream>
#include <algorithm>
using namespace std;

// 다변수 다항식 표현
enum Triple{var,ptr,no};
class PolyNode{
  PolyNode *next;
  int exp;
  Triple trio;
  union {
    char vble;
    PolyNode *down;
    int coef;
  };
};

// 범용리스트
template <class T> class GenList;

template <class T>
class GenListNode{
friend class GenList<T>;
private:
  GenListNode<T> *next;
  bool tag;
  union{
    T data;
    GenListNode<T> *down;
  };
};

template <class T>
class GenList{
public:
private:
  GenListNode<T> *first;
};