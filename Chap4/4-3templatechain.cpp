#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class Chain;

template <class T>
class ChainNode{
friend class Chain<T>;
private:
  T data;
  ChainNode<T>* link;
};

template <class T>
class Chain{
public:
  Chain(){first=0;};
  void InsertBack(const T& e);
  void Concatenate(Chain<T> &b);
  void Reverse();
private:
  ChainNode<T>* first;
  ChainNode<T>* last;
};

// 체인 연산
// 리스트 끝에 삽입
template <class T>
void Chain<T>::InsertBack(const T& e){ // e는 데이터 원소
  if(first){
    last->link = new ChainNode<T>(e);
    last = last->link;
  }
}
// 두 체인의 접합
template <class T>
void Chain<T>::Concatenate(Chain<T>&b){
  if(first) {last->link = b.first; last = b.last;}
  else{first = b.first; last = b.last;}
  b.first = b.last =0; //없애기
}
// 역순서화
template <class T>
void Chain<T>::Reverse(){
  ChainNode<T>* current = first, *previous = 0; //pre는 curr를 따라감
  while(current){
    ChainNode<T>* r = previous;
    previous = current;
    current = current->link;
    previous->link = r;
  }
  first = previous;
}