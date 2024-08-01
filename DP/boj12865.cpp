#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<int> v;
vector<vector<int>> dp;  // 크기 (N, K)

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  v.resize(N + 1, 0);
  w.resize(N + 1, 0);
  dp.resize(N + 1, vector<int>(K + 1, 0));

  for (int i = 1; i <= N; i++) {
    cin >> w[i] >> v[i];
  }

  // i번째 물건까지 살펴본 뒤, 배낭의 용량이 j였을 때
  // 들어갈 수 있는 물건들의 가치 최대 합
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (w[i] <= j) {  // i번째 물건을 넣을 수 있는 경우
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[N][K] << '\n';
}