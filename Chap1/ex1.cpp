#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> //accumulate()
using namespace std;
//1.2
void swap(int x, int y){
  int temp = x;
  x=y;
  y = temp;
}
void SelectionSort(int* a, const int n){
  for(int i=0;i<n;i++){
    int j = i;
    for(int k=i+1;k<n;k++)
      if(a[k]<a[j]) j=k;
    swap(a[i],a[j]);
  }
}
// <순환 알고리즘>
//1.3 1.4 이원 탐색의 순환적 구현
int BinarySearch(int* a, const int x, const int left, const int right){
  if(left<=right){
    int middle = (left+right)/2;
    if(x<a[middle]) return BinarySearch(a,x,left,middle-1);
    else if(x>a[middle]) return BinarySearch(a,x,middle+1,right);
    return middle;
  }
  return -1;
}
//1.5 순환적 순열 생성기
void Permutations(char* a, const int k, const int m){ //k에서 m까지, k를 핀이라고 생각, m은 움직이지 않음
  if(k==m){
    for (int i=0; i<=m; i++) cout << a[i] << " ";
    cout << endl;
    }
  else {
    for (int i=k; i<=m; i++){ //k는 0부터 m까지 꽂는다
      //순서를 바꾸는 함수
      swap(a[k], a[i]); //0 index-> a로 시작하는 순열.. b로 시작하는 순열.. 
      //그 안의 순열
      Permutations(a, k+1, m); //1 index-> k+1로 시작하는 순열.. k+2로 시작하는 순열.. 2index.. 3index.. m index..
      //다시 처음 순서로 돌아가기
      swap(a[k], a[i]);
    }

  }
}
// <STL>
//1.6
int Product(int* a, int n){
  int initVal = 1;
  return accumulate(a, a+n, initVal, multiplies<int>());
}
//1.7
void Permutations(char* a, const int m){
  do{
    copy(a, a+m+1, ostream_iterator<char>(cout, " "));
    cout << endl;
  } while(next_permutation(a, a + m +1));
}
// <성능분석>, 시간복잡도
//1.11
float Sum(float *a, const int n){ //선언문(명령문) 0
  int count =0; //책에서는 전역변수
  float s=0; //지정문 1
  count++; 
  for(int i=0; i<n; i++){
    count++; //for 1
    s+=a[i];
    count++; //지정문 1
  }//2n
  count++; //for의 마지막 시행 1
  count++; //return 1
  return s;
}// => 따라서 전체 단계수는 2n+3
//1.12
float Rsum(float *a, const int n){
  int count =0;
  count++; //조건문 1
  if(n<=0){
    count++; //return 1
    return 0;
  }
  else{
    count++; //return 1
    return (Rsum(a,n-1)+a[n-1]); //순환관계
  }
} //if->2,  else->2+R(n-1) => 따라서 전체 단계수는 2n+2
//1.13
void Add(int **a, int **b, int **c, int m, int n){
  int count=0;
  for(int i=0;i<m;i++){
    count++;//for i 1
    for(int j=0;j<n;j++){
      count++; //for j 1
      c[i][j] = a[i][j]+b[i][j];
      count++; //지정문 1 => 2n
    } 
    count++; //마지막 for j 1
  } // => (2n+2) * m
  count++; //마지막 for i 1
} // => 따라서 전체 단계수는 2nm + 2m + 1
//1.20 magic square
void Magic(const int n){ //크기가 n이고 n은 홀수인 매직스퀘어 생성
  const int MaxSize = 51;
  int square[MaxSize][MaxSize], k, l;
  //n이 올바른지 검사: 범위 안 & n이 홀수
  if((n>MaxSize)||(n<1)) throw "Error!.. n out of range";
  else if(!(n%2)) throw "Error!.. n is even"; // !0 -> 1

  //n이 가능하면 Coxeter 규칙 사용 가능
  for(int i=0; i<n; i++) fill(square[i], square[i]+n, 0); // i행에 0에서 n-1열까지 0
  square[0][(n-1)/2] = 1; // 첫행의 중간
  // [i][j] -> [k][l]. 변수 key는 +1씩 증가 후 할당
  int i=0; int j=(n-1)/2; //현재 위치
  int key = 2; // 할당할 값
  while(key <= n*n){
    if(i-1<0) k=n-1; else k=i-1; //행 이동. k만들기
    if(j-1<0) l=n-1; else l=j-1; //열 이동. l만들기
    if(square[k][l]) i = (i+1)%n; // square가 채워짐. 아래로 이동. 행만 이동, 열은 가만히
    else{
      i = k; j=l;
    }
    square[i][j] = key;
    key++;
  }// square 다 채워짐
  // 출력
  cout << "magic square of size" << n <<endl;
  for(i = 0; i<n; i++){
    copy(square[i], square[i]+n, ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}

