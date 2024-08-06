#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

int N, M;
int arr[MAX][MAX];  // 인덱스 1 ~ N, 1 ~ M, 인덱스 0인 부분은 모두 0으로 초기화
int dx[3] = {-1, -1, 0};
int dy[3] = {0, -1, -1};

/*
1. 0이면 건너뜀
2. 1이라면 주변의 값 확인한다
3. 주변 값의 최솟값 + 1
*/
int FindRectangle() {
  int max_len = 0;  // 정사각형 변 길이의 최댓값

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (arr[i][j] == 0) continue;  // 0은 건너뛴다

      int tmp_min = INT_MAX;
      for (int k = 0; k < 3; k++) {  // 3개 위치에서의 최솟값 구하기
        int nx = i + dx[k];
        int ny = j + dy[k];
        tmp_min = min(tmp_min, arr[nx][ny]);
      }
      arr[i][j] = tmp_min + 1;
      if (max_len < arr[i][j]) {
        max_len = arr[i][j];
      }
    }
  }
  return max_len;
}

int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;

    bool is_all_zero = true;  // 모두 0이라면 true
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cin >> arr[i][j];
        if (arr[i][j] != 0) is_all_zero = false;  // 0이 아닌 수가 있는 경우
      }
    }

    // 가장 큰 정사각형 길이 출력하기, 없으면 0
    if (is_all_zero) {
      cout << 0 << "\n";
    } else {
      cout << FindRectangle() << '\n';
    }
  }
}