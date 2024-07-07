#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int arr[1025][1025] = {0};  // 구간합 (1,1에서 x,y까지의 합)
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &arr[i][j]);
      arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--, y1--;
    int result = arr[x2][y2] - arr[x1][y2] - arr[x2][y1] + arr[x1][y1];
    printf("%d\n", result);
  }
}