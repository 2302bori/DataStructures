#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//p 3.3
template <class T>
void ChangeSizeID(T* &a, const int oldSize, const int newSize)
{
  if(newSize < 0) throw "New lenth must be >= 0";
  T* temp = new T[newSize];
  int number = min(oldSize, newSize); //최소값 반환
  copy(a, a+number, temp); //0부터 number-1까지
  a = temp;
  delete []temp;
}
//p3.6 탬플릿 클래스 bag 정의
template <class T>
class Bag{
public:
  Bag(int bagCapacity = 10);
  ~Bag();
  int Size() const;
  bool IsEmpty() const;
  T& Element() const;
  void Push(const T&);
  void Pop();
private:
  int *array;
  int capacity;
  int top;
};
//p3.5 bag 연산들
template <class T>
Bag<T>::Bag(int bagCapacity): capacity(bagCapacity){
  if (capacity <1 ) throw "Capacity must be >0";
  array = new T[capacity];
  top = -1; //index
}
template <class T>
Bag<T>::~Bag() {delete [] array;}
template <class T>
void Bag<T>::Push(const T& x){
  if(capacity ==top+1) //한도에 도달했을시
  {
    ChangeSizeID(array, capacity, capacity*2); //크기를 두배로 
    capacity *= 2; //크기는 2배라고 저장
  }
  array[++top] = x;
}
template <class T>
void Bag<T>::Pop(){
  if(IsEmpty()) throw "Bag is empty, cannot delete";
  int deletePos = top/2;
  copy(array + deletePos +1, array + top + 1, array +deletePos); //배열정리
  array[top--].~T();
}