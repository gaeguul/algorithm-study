#include <limits.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 10001  // 컴퓨터 최대 개수
using ll = long long;
using node = pair<int, int>;  // 감염시키는 컴퓨터 번호, 감염 시간
struct compare {
  bool operator()(node a, node b) { return a.second > b.second; }
};

int t, n, d, c;
vector<node> vec[MAX];
// 각 컴퓨터마다 감염 전파시키는 컴퓨터 번후와 그 시간 저장한다
vector<ll> dist;  // 최소비용배열

void Dijkstra(int total, int start) {
  // 최소힙을 사용하기 위한 우선순위 큐
  priority_queue<node, vector<node>, compare> pq;
  dist.assign(n + 1, LLONG_MAX);
  dist[start] = 0;  // 시작노드의 거리 0으로 초기화
  pq.push({start, dist[start]});

  // 우선순위 큐에 아무것도 없을 때까지 반복한다
  while (!pq.empty()) {
    int cur = pq.top().first;  // 최단 거리가 가장 짧은 노드
    int cost = pq.top().second;  // 최단 거리가 가장 짧은 노드까지의 거리
    pq.pop();                    // 우선순위 큐에서 제거

    // 현재 노드까지의 최소비용이 cost보다 작을 때만 dist[cur] 값을 갱신한다
    if (dist[cur] < cost) continue;

    // 최단 거리가 가장 짧은 노드를 기준으로 인접한 노드의 거리를 업데이트한다
    for (auto& neighbor : vec[cur]) {
      int next = neighbor.first;
      int next_cost = cost + neighbor.second;

      if (next_cost < dist[next]) {
        dist[next] = next_cost;
        pq.push({next, next_cost});
      }
    }
  }

  int cnt = 0;  // 총 감염되는 컴퓨터 수
  ll time = 0;  // 마지막 컴퓨터까지 감염되기까지 걸리는 시간

  for (int i = 1; i <= n; i++) {
    if (dist[i] != LLONG_MAX) {
      cnt++;  // dist 값이 INF가 아닌 노드들의 개수
      if (dist[i] > time) {
        time = dist[i];
      }
    }
  }

  cout << cnt << " " << time << '\n';
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  // 테스트 t번 반복한다
  for (int i = 0; i < t; i++) {
    cin >> n >> d >> c;

    for (int i = 1; i <= n; i++) vec[i].clear();

    // d번 반복하여 a, b, s 입력받는다
    for (int j = 0; j < d; j++) {
      int a, b, s;
      cin >> a >> b >> s;
      vec[b].push_back({a, s});  // b가 감염되면 s초 후에 a도 감염된다
    }

    Dijkstra(n, c);  // 총 노드 개수, 시작 노드 번호
  }
}

// n - 컴퓨터 개수 <= 10,000
// d - 의존성 개수 <= 100,000
// c - 해킹당한 컴퓨터 번호 <= n
