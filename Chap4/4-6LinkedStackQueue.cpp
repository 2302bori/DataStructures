#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class LinkedStack;
template <class T> class LinkedQueue;
template <class T>
class ChainNode{
friend class LinkedStack<T>;
friend class LinkedQueue<T>;
private:
  T data;
  ChainNode<T>* link;
};

template <class T>
class LinkedStack{
public:
  LinkedStack(){top=0;}
  void Push(const T& e);
  void Pop();
private:
  ChainNode<T>* top;
};

template <class T>
class LinkedQueue{
public:
  LinkedQueue(){front =0; rear = 0;};
  void Push(const T& e);
  void Pop();
private:
  ChainNode<T>* front, rear;
};

// 스택 삽입 삭제
template <class T>
void LinkedStack<T>::Push(const T& e){
  top = new ChainNode<T>(e, top);
}
template <class T>
void LinkedStack<T>::Pop(){
  ChainNode<T> *delNode = top;
  top = top->link;
  delete delNode;
}

//큐 삽입 삭제
template <class T>
void LinkedQueue<T>::Push(const T& e){
  rear = new ChainNode(e,0);
  rear = rear->link;
}
template <class T>
void LinkedQueue<T>::Pop(){
  ChainNode<t> *delNode = front;
  front = front ->link;
  delete delNode;
}