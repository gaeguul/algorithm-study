#include <string.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define MAX 10001
struct Edge {
  int to, cost;  // 'to' 도시까지 걸리는 비용 cost
};

vector<Edge> graph[MAX];
int visited[MAX];
int edge_cnt;       // 총 도로의 개수
int max_cost;       // 가장 긴 거리
int farthest_node;  // 가장 긴 거리를 가지는 가장 먼 노드

/**
 * 가장 먼 노드와 그 거리를 찾는다.
 * @param cur 현재 노드
 * @param cost 현재 노드까지의 비용
 */
void dfs(int cur, int cost) {
  if (cost > max_cost) {
    max_cost = cost;
    farthest_node = cur;
  }
  visited[cur] = 1;  // 현재 노드 방문했다고 표시

  // 현재 도시에서 인접해있는 모든 도시를 순회한다
  for (auto edge : graph[cur]) {
    if (!visited[edge.to]) {
      dfs(edge.to, cost + edge.cost);
    }
  }
}

int main(void) {
  cin.tie(NULL), cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, cost;
  while (cin >> a >> b >> cost) {  // 입력 횟수가 정해져있지 않으므로
    graph[a].push_back({b, cost});  // a에서 b까지 거리가 dist이다.
    graph[b].push_back({a, cost});  // b에서 a까지 거리가 dist이다.
  }

  dfs(1, 0);  // 임의의 노드(1)에서 시작하여 가장 먼 노드 찾기
  memset(visited, 0, sizeof(visited));
  max_cost = 0;
  dfs(farthest_node, 0);  // 가장 먼 노드에서 시작하여 가장 긴 거리 찾기

  cout << max_cost << '\n';
}