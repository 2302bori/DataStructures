#include <iostream>
#include <algorithm>
using namespace std;

// 이중 연결 리스트
class DblList;
class DblListNode{
friend class DblList;
private:
  int data;
  DblListNode *left, *right;
};
class DblList{
public:
  void Delete(DblListNode *x);
  void Insert(DblListNode *p, DblListNode *x);
private:
  DblListNode *first; //헤더노드를 가르킨다
};

// x를 삭제
void DblList::Delete(DblListNode *x){
  if(x == first) throw "Deletion of header node not permitted"; // x가 헤더노드라면
  else{
    x->left->right = x->right;
    x->right->left = x->left;
    delete x;
  }
}

// 노드 x의 오른편에 노드 p를 삽입
void DblList::Insert(DblListNode *p, DblListNode *x){
  p->left = x; p->right = x->right; // p노드의 포인터들 설정
  x->right->left = p; x->right = p; // p 양쪽 노드들의 포인터들 설정
}