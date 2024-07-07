#include <algorithm>
#include <cstdio>
using namespace std;

int main(void) {
  int n;
  scanf("%d", &n);
  int arr[301] = {0};
  int dp[301] = {0};

  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }

  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];

  for (int i = 3; i <= n; i++) {
    dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
  }

  printf("%d\n", dp[n]);
}

// 처음에 점화식 잘못 설정해서 다른 풀이 참고
// 참고: https://kwanghyuk.tistory.com/4