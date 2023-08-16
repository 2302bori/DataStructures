#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class CircularList;
template <class T>
class ChainNode{
friend class Chain<T>;
private:
  T data;
  ChainNode<T>* link;
};

template <class T>
class CircularList{
public:
  CircularList(){first=0;};
  void InsertFront(const T& e);
  ChainNode<T>* GetNode();
  void RetNode(ChainNode<T>* &x)
private:
  ChainNode<T>* last;
  ChainNode<T>* av;
};

// 원형 리스트 앞에 삽입
template <class T>
void CircularList<T>::InsertFront(const T& e){
  ChainNode<T> *newNode = new ChainNode<T>(e);
  if(last){
    newNode->link = last ->link;
    last->link = newNode;
  }
  else{
    last = newNode;
    newNode->link = newNode; //원형
  }
}
// 노드 획득
template <class T>
ChainNode<T>* CircularList<T>::GetNode(){
  ChainNode<T>* x;
  if(av){ x = av; av= av->list;}
  else x = new ChainNode<T>;
  return x;
}
// 노드 반환
template <class T>
void CircularList<T>::RetNode(ChainNode<T>* &x){
  //x가 가르키는 노드 반환
  x->link = av;
  av = x;
  x = 0;
}
// 원형리스트의 삭제
// ????