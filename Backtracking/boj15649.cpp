#include <iostream>
using namespace std;

int n, m;      // n: 수 범위, m: 수열의 길이
int arr[9];    // print할 수열 기록
bool used[9];  // 인덱스 i: 숫자 i가 사용되었는지 기록

/**
 * 1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열 출력
 * @param k 현재까지 선택한 수의 개수 (최댓값 m)
 */
void print_backtracking(int k) {
  /** 재귀함수 종료조건 */
  if (k == m) {
    for (int i = 0; i < m; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      arr[k] = i;  // k번째 수를 i로 정한다.
      used[i] = true;
      print_backtracking(k + 1);  // 다음 수를 정한다.
      used[i] = false;  // k번째 수를 i로 정한 모든 경우에 대해 확인했으니 i가
                        // 사용되지 않았다고 명시함.
    }
  }
}

int main(void) {
  cin >> n >> m;
  print_backtracking(0);
}