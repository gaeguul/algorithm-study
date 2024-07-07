#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int arr[100001] = {0};

  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    arr[i] += arr[i - 1];
  }

  for (int i = 0; i < m; i++) {
    // a번째수부터 b번째 수까지의 합은 sum(b) - sum(a-1)
    int from, to;
    scanf("%d %d", &from, &to);
    printf("%d\n", arr[to] - arr[from - 1]);
  }
}

// 1. 처음에 구간합 떠올리지 못해서 다른 풀이 참고함.
// 참고: https://ljhyunstory.tistory.com/176
// 2. 시간 초과나서 cin, cout을 scanf, printf로 수정해서 통과함.