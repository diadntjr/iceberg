# Search Algorithm

## 탐색이란?

- 같은 형태의 자료들이 모여 있는 집합에서 특정 자료를 찾는 모든 작업
- 탐색할 자료가 저장되어 있는 구조를 먼저 __파악__하는 것이 중요

탐색 구조가 직접적으로 드러난 경우는 쉬운문제, 직접 드러나지는 않으나 문제 해결과정에서 자체적으로 구조화하며 탐색하는 경우 중급 이상 문제

## 탐색 기반 설계

- 문제에 주어진 데이터를 __특성에 맞도록 구조화하고__ 이 자료를 적절한 방법으로 탐색해 나가면서 원하는 해를 찾는 알고리즘 설계법
- 전체를 탐색하는 __전체탐색법__과 탐색할 영역을 적절한 방법으로 배제하여 탐색의 효율을 높인 __부분탐색법__이 있다.

## 탐색이 되는 구조
- 선형구조: 배열이나 연결리스트로 표현될 수 있는 구조
- 비선형구조: 트리나 그래프의 형태로 표현되는 구조

## 선형구조 탐색

- 자료의 순서를 유일하게 결정할 수 있는 형태의 구조
- 비선형구조: 트리나 그래프의 형태로 표현되는 구조

## 1. 선형구조 탐색

- 자료의 순서를 유일하게 결정할 수 있는 형태의 구조
- i번째 자료를 탐색한 다음, i+1번째로 탐색, 탐색해야할 자료가 유일한 형태
- 2차원/3차원 구조라도 순서가 일정하면 선형
- 선형구조의 탐색에는 __순차탐색__과 __이분탐색__이 존재하며, 이들을 적절히 사용한 탐색법도 만들어 사용 가능

<img src="https://t1.daumcdn.net/cfile/tistory/2729EE4C569B69832D">   
이렇게 순차적으로 데이터가 있다고 가정할 때,

<img src="https://t1.daumcdn.net/cfile/tistory/262AF14C569B6BDC36">   
로 찾을 수 있다.

__코드__

순차탐색 코드 - 무지성 탐색

리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 차례대로 확인하는 방법

- 정렬되지 않는 리스트에서 주로 사용
- 시간만 많으면 원하는 원소 찾기 ㄱㄴ

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, want = 0, status = 0, k = 0;
    scanf("%d %d", &n, &want);
    int *arr = calloc(n, sizeof(int));

    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    while(k != n) {
        if(arr[k] == want) {
            status = 1;
            break;
        }
        k++;
    }

    if(status)
        printf("%d", k);
    else
        printf("Not Found");
    return 0;
}
```


이분탐색 코드 - 매우 간단함

- 속도가 $log_2N$ 에 비례한다. 단계마다 탐색 범위를 2로 나누는 것과 같기 때문
- 무조건 오름차순 정렬을 해야 한다.

```C
#include<stdio.h>

int S[100], n, k;

int find(int s, int e) {
    while(s <= e) {
        int m = (s+e) /2;
        if(S[m] == k) return m;
        if(S[m]>k) e=m-1;
        else s=m+1;
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &S[i]);
    }
    printf("%d\n", find(0, n-1));
    return 0;
}
```