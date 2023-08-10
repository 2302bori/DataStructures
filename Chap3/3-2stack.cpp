#include <iostream>
#include <algorithm>
using namespace std;

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
// 3.1 시스템스택
//ADT3.1 Stack 추상화 타입
template <class T>
class Stack
{
public:
  Stack(int stackCapacity = 10);
  bool IsEmpty() const;
  T& Top() const;
  void Push(const T& item);
  void Pop();
private:
  T* stack; //스택 원소를 위한 배열
  int top; //톱 원소의 위치
  int capacity;//스택 배열의 크기
};
//스택 연산들
template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
  if(capacity < 1) throw "Stack capacity must be > 0";
  stack = new T[capacity];
  top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const {return top == -1;}

template <class T>
inline T& Stack<T>::Top() const
{
  if(IsEmpty()) throw "Stack is empty";
  return stack[top];
}

template <class T>
void Stack<T>::Push(const T& x)
{
  if(top == capacity -1) //만원일때
  {
    ChangeSizeID(stack, capacity, capacity*2);
    capacity *= 2;
  }
  stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
  if(IsEmpty()) throw "Stack is empty. Cannot delete";
  stack[top--].~T();
}