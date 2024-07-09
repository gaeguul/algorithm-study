#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int map[1001][1001] = {0};

  for (int i = 1; i <= n; i++) {
    char line[1001];
    scanf("%s", line);
    for (int j = 0; j < m; j++) {
      map[i][j + 1] = line[j] - '0';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (map[i][j] == 0) continue;
      map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;
    }
  }

  int max = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (max < map[i][j]) max = map[i][j];
    }
  }

  printf("%d\n", max * max);
}

// 풀이 참고: https://yabmoons.tistory.com/158