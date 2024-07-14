#include <cstdio>
using namespace std;

int main(void) {
  int n;  // n: 공의 개수
  int k;  // k: 바구니 개수
  scanf("%d %d", &n, &k);

  int limit = k * (k + 1) / 2;  // 최소한의 공의 개수

  if (n < limit) {
    printf("%d", -1);
  } else if ((n - limit) % k == 0) {
    printf("%d", k - 1);
  } else {
    printf("%d", k);
  }
}