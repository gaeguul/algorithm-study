#include <iostream>
#include <vector>
using namespace std;

// 피로도 -- 최소 0, 최대 M
// 일 -> 피 + A, 일 + B
// 휴식 -> 피 - C

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int A, B, C, M;
  cin >> A >> B >> C >> M;

  int tired = 0;  // 현재 피로도
  int work = 0;   // 현재 일한 시간

  for (int i = 0; i < 24; i++) {
    // 현재 상태에서 일을 했을 경우 피로도가 M 초과할 경우 쉬어야 한다
    if (tired + A > M) {
      // 쉬어야 하는  경우
      tired -= C;
      if (tired < 0) tired = 0;  // 피로도가 음수인 경우 0으로 수정한다
    } else {
      // 일 해도 되는 경우
      tired += A;
      work += B;
    }
  }

  cout << work << '\n';
}