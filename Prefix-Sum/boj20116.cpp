#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void) {
  int n;  // n: 상자의 개수
  ll L;   // L: 상자 크기(2L*2L)
  cin >> n >> L;

  vector<ll> v(n + 1, 0);    // 상자의 중심 x좌표
  vector<ll> sum(n + 1, 0);  // x좌표의 합

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  sum[n] = v[n];
  // 상자 i에서 균형을 이루는지 확인한다
  for (int i = n - 1; i >= 1; i--) {
    sum[i] += (v[i] + sum[i + 1]);

    // 상자 i의 구간 (v[i]-L, v[i]+L)
    // 상자 i...n 개수 = n-i+1
    // 무게중심 좌표: sum[i+1]/(n-i+1)
    // 위 좌표가 상자 i 구간을 벗어나면 unstable
    ll left_range = v[i] - L;
    ll right_range = v[i] + L;
    double mid_x = sum[i + 1] / (double)(n - i);

    // 무게 중심 좌표가 i번 상자의 구간을 벗어나는 경우 불균형
    if (mid_x <= left_range || right_range <= mid_x) {
      cout << "unstable";
      return 0;
    }
  }

  cout << "stable";
  return 0;
}

// 처음에는 좌표를 int 타입으로 해결할 수 있다고 생각했는데
// 오버플로우 때문인지 실패해서 long long 타입으로 변경하니까 해결됐다.