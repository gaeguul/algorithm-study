#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define CITY_MAX_SIZE 301
struct Info {
  int to, rate;
};

int N, M, K;
vector<Info> infos[CITY_MAX_SIZE];
int dp[CITY_MAX_SIZE][CITY_MAX_SIZE];
// dp[i][j] - i번째 도시까지 도시 j개를 들렸을 때 기내식 총합의 최댓값
// i번째 도시까지 이동했을 때 최댓값을 구하는 게 아니라
// 도시 j개를 방문했을 때의 최댓값 구하는 방법
// 즉, 도시 개수에 따라 최댓값을 구한다

int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int a, b, rate;
    cin >> a >> b >> rate;
    if (a < b) infos[a].push_back(Info{b, rate});
  }

  /** 1번 도시와 연결된 도시들의 dp 값 변경 */
  for (int i = 0; i < infos[1].size(); i++) {
    int next = infos[1][i].to;
    int cur_rate = infos[1][i].rate;
    dp[next][2] = max(dp[next][2], cur_rate);
  }

  /** 현재까지 방문한 도시의 수 i */
  for (int i = 2; i <= M; i++) {
    /**
     * 현재까지 i개의 도시를 들린 상태에서
     * 다음 도시로 이동할 때의 최대 기내식 점수를 계산한다
     */
    for (int now = 1; now <= N; now++) {
      /** 도시 now에서 출발하는 모든 가능한 항로들 탐색 */
      if (dp[now][i] != 0) {
        /**
         * 도시 now까지 i개의 도시를 들렸을 때
         * 기내식 점수가 기록되어 있는 경우에만 계산을 진행한다
         * 즉, 0인 경우에는 i개의 도시를 들렸을 때
         * 도시 now까지 이동 가능한 경로가 없다는 뜻이다
         */
        for (Info info : infos[now]) {
          int next = info.to; /** 도시 now에서 이동 가능한 도시 next */
          int rate = info.rate;
          dp[next][i + 1] = max(dp[next][i + 1], dp[now][i] + rate);
        }
      }
    }
  }

  int answer = 0;
  for (int i = 2; i <= M; i++) {
    answer = max(answer, dp[N][i]);
  }
  cout << answer << '\n';
}

/**
 * 처음 시도: 완전 탐색으로 진행했는데 시간 초과 발생
 * 두 번째 시도: DP 알고리즘을 사용했지만 dp 배열을 1차원으로 설정해서 틀림
 */