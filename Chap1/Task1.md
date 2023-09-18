# PS #1 assigned

## Problem 1

두번째 인덱스부터 시작하게 되고 현재 인덱스 값과, 바로 이전의 인덱스 깂을 비교한다. 만약 이전 인덱스가 더 크면, 현재 인덱스랑 바꿔준다. 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 베열 값을 비교한다. 이런 방식으로 i 값이 커짐에 따라 이웃된 두 값을 비교하여 큰 값이 뒤로 가도록 교환한다. 그렇게 for 안의 코드가 n-1번 순회하면 for문에서 나오게 되고 lastswap 값은 for문에서 배열을 통과하는 동안 교환이 얼만큼 이루어졌는지를 알 수 있다.

만약 a가 잘 정렬된 배열이라 교환을 한번도 하지 않았다면 `lastswap = 0` 이므로 do-while 절에 빠져나오게 된다.

그렇지 않으면, lastswap > 0 이 되고 다시 do-while 안의 블록을 순회한다.
lastswap에 0의 값을 할당하게 되고 for문에서 다시 배열을 검사하여 교환한다. 그리고 lastswap가 0이 될 때까지 검사한다. 왜냐하면 lastswap이 0이라면, 배열이 내림차순으로 정렬이 되어 if문이 실행되지 않아 `lastswap = 0` 이 되기 때문이다.

따라서 이 알고리즘은 실행한 후, 배열이 감소하지 않게 정렬될 것이다.

## Problem 2

for문이 실행되면서 이웃된 두 값을 비교하여 교환하다 보면, 큰 값은 계속해서 작은 값 뒤로 보내게 된다. 그러다보면 제일 큰 값이 먼저 뒤로 보내지게 되고, do-while 루프가 실행될 때마다 정렬이 아직 되지 않은 배열 부분의 제일 큰 값은 뒤로 보내지게 된다.

## Problem 3

```cpp
void ImprovedSwapSort(int *a, int n)
{
    int final, lastswap;
    lastswap = n;
    do {
        final = 0;
        for (int i = 1; i < lastswap; i++){
            if (a[i] < a[i-1]) {
                swap(a[i], a[i-1]);
                final = i;
            }
        }
        lastswap = final;
    } while (lastswap > 0);
}

```

## Problem 4

O(n)

## Problem 5

The ImprovedSwapSort algorithm achieves its best case performance when the input array is already sorted in non-decreasing order.
In this best case, the for loop will still iterate, but no swaps will be performed. Because the condition if a[i] < a[i-1] will never be true. As a result, the lastswap variable will be maintained 0, after the for loop.
So there are no swaps and the outer do-while loop will exit after just one iteration.
In this best case, the algorithm runs in linear time, taking n-1 comparative operations to determine that no swaps are needed.
Therefore, ImprovedSwapSort() achieves the best case perfomance, under the condition that the input array is already sorted in non-decreasing order.

## Problem 6

O(n^2), 2차

## Problem 7

예시 :

```cpp
void SelectionSort(int *a, const int n)
{// Sort the n integers a[0] to a[n-1] into nondecreasing order.
    for (int i = 0; i < n; i++)
    {
        int j = i;
        // find the smallest integer in a[i] to a[n-1]
        for (int k = i + 1; k < n; k++)
            if (a[k] < a[j]) j = k;
        swap(a[i], a[j]);
    }
}
```

정답 :

```cpp
int *SelectionSort(int *a, const int n)
{
    int *array = new int[n];

    for(int i=0; i<n; i++){
        array[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (a[array[k]] < a[array[j]]) j = k;
        swap(array[i], array[j]);
    }
    return array;
}
```
