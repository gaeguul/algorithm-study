#include <cstdio>

int n;         // 체스판의 크기이자, 퀸의 개수
int cnt;       // 퀸을 놓는 총 방법의 수
int cols[15];  // i번째 행에 놓은 퀸의 위치를 저장하는 배열

/** 절댓값을 구하는 함수 */
int get_abs(int a) { return (a > 0) ? a : -a; }

/** 퀸을 배치할 수 있는지 판단하는 함수 */
bool is_possible(int cur) {
  for (int i = 0; i < cur; i++) {  // 이전 행들에 놓은 퀸들과 비교
    // 같은 열에 있거나, 대각선에 있는지 확인
    if (cols[i] == cols[cur] ||
        get_abs(cur - i) == get_abs(cols[cur] - cols[i]))
      return false;
  }
  return true;
}

/** cur번째 행에 퀸을 놓는 경우 */
void backtracking(int cur) {
  /**
   * 재귀함수 종료조건: 모든 행에 퀸을 놓은 경우
   */
  if (cur == n) {
    cnt++;
    return;
  }

  /** 현재 cur행에 퀸을 놓을 위치 결정 */
  for (int r = 0; r < n; r++) {
    cols[cur] = r;  // cur번째 행의 퀸을 r번째 열에 놓는다

    /** cur번째 행에 퀸을 놓을 수 있는지 확인 */
    if (is_possible(cur)) backtracking(cur + 1);
  }
}

int main(void) {
  scanf("%d", &n);
  backtracking(0);
  printf("%d\n", cnt);
}