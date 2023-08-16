#include <iostream>
#include <algorithm>
using namespace std;


class Chain;
class ChainNode{
friend class Chain;
public:
  ChainNode(int element=0, ChainNode* next=0)
  {data = element; link = next;}
private:
  int data;
  ChainNode* link;
};
class Chain{
public:
  void Create2();
  void Insert50(ChainNode* x); //x의 다음 원소에
  void Delete(ChainNode *x, ChainNode* y); //x가 가르키는 노드 없애기
private:
  ChainNode* first;
};
//4.2 2개의 노드로 구성된 체인을 생성
void Chain::Create2(){
  ChainNode* second = new ChainNode(20, 0); //마지막원소
  first = new ChainNode(10,second);
}
//4.3 50을 삽입 (노드삽입)
void Chain::Insert50(ChainNode* x){
  if(first)
    x->link = new ChainNode(50,x->link); //x와 x다음 원소 사이에 50노드 삽입
  else
    first = new ChainNode(50); //fist와 0 사이에 50노드 삽입
}
//4.4 노드 삭제
void Chain::Delete(ChainNode* x, ChainNode* y){
  if(x==first) first = first->link; //first(x) 다음 원소를 가르키기
  else y->link = x->link; // x 다음 원소 가르키기
  delete x;
}