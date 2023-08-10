#include <iostream>
#include <algorithm>
using namespace std;

//ADT3.2 Queue 추상 데이터 타입
//무조건 포인터 f,r을 먼저 이동시키고 값 수정
template <class T>
class Queue
{
public:
  Queue(int queueCapacity = 10);
  bool IsEmpty() const;
  T& Front() const;
  T& Rear() const;
  void Push(const T& item);
  void Pop();
private:
  T* queue; //큐 원소를 위한 배열
  int front;
  int rear;
  int capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
  if(capacity < 1) throw "Queue capacity must be > 0";
  queue = new T[capacity]; //배열 동적 할당
  front = rear = 0; //공백
}

template <class T>
inline bool Queue<T>::IsEmpty() const {return front == rear;} // f와 r이 같으면 공백이라고 생각

template <class T>
inline T& Queue<T>::Front() const
{
  if(IsEmpty()) throw "Queue is empty. No front element";
  return queue[(front + 1) % capacity]; //첫번째 원소(삭제될원소)
}

template <class T>
inline T& Queue<T>::Rear() const
{
  if(IsEmpty()) throw "Queue is empty. No rear element";
  return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& x)
{
  //크기를 먼저 수정한 뒤, 원소 삽입
  if((rear+1)%capacity == front){
    //큐가 만원일때, 크기capacity를 두배로
    T* newQueue = new T[2*capacity]; // 크기 두배인 새 배열 생성
    
    //queue를 newQueue로 복사
    int start = (front +1) % capacity; // 첫번째 원소
    if(start < 2)// 원소들 중간에 끊기는 부분이 없을때 
      copy(queue + start, queue + start + capacity -1, newQueue);
    else{
      copy(queue + start, queue + capacity, newQueue);// 배열의 오른쪽 부분 이동.
      //이동한 원소의 수: (capacity-1) - start +1 = capacity - start
      copy(queue, queue + rear + 1, newQueue + capacity + start);// 배열의 왼쪽 부분 이동.
      // capacity - start -1 번째 원소 뒤에 복사됨
    }
    //원소이동 완료

    // f, r 조정 -> 크기 수정 -> 만든 새로운 배열을 queue에 할당
    front = 2*capacity -1; // 배열 마지막 가르키기
    rear = capacity - 2; // 마지막 원소 가르키기
    capacity *= 2; // 크기 수정
    delete [] queue; // 구버전 배열 삭제
    queue = newQueue; // 새로 할당
  }
  rear = (rear +1)%capacity; // rear++
  queue[rear] = x; // rear에 새 원소 삽입
}

template <class T>
void Queue<T>::Pop(){
  if(IsEmpty()) throw "Queue is empty. Cannot delete";
  front = (front +1) % capacity; // f 시계방향으로 위치이동
  queue[front].~T(); //삭제
}