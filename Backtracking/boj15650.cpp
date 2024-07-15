#include <iostream>
using namespace std;

int n;       // 수의 범위
int m;       // 수열의 길이
int arr[9];  // 만들어진 수열

/**
 * @param len 현재 수열의 길이
 * @param max 해당 수열에서 최댓값
 */
void func(int len, int max) {
  /** 종료조건: 현재 수열의 길이가 최대 길이일 때 */
  if (len == m) {
    for (int i = 0; i < m; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  /**
   * 수열의 다음 수를 고를 때
   * 현재 수열의 최댓값인 max보다 큰 수들만 고려한다
   */
  for (int i = max + 1; i <= n; i++) {
    arr[len] = i;      // len번째 수를 i로 정한다.
    func(len + 1, i);  // 수열의 다음 수 정하기
  }
}

int main(void) {
  cin >> n >> m;
  func(0, 0);
}