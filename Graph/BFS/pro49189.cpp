#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;  // 각 노드에서 이어진 다른 노드들 배열, 인덱스 1~n
vector<int> dist;  // 각 노드까지의 최단거리, -1이면 방문X, 인덱스 1~n

int FindDist(int n) {
  queue<int> q;
  q.push(1);
  dist[1] = 0;  // 시작노드 1번 방문했다고 표시

  while (!q.empty()) {
    int cur = q.front();  // 현재 위치한 노드 번호
    q.pop();

    // 인접 노드 중에서 다음에 방문할 노드 구하기
    for (int i = 0; i < v[cur].size(); i++) {
      int next = v[cur][i];    // 인접 노드
      if (dist[next] == -1) {  // 방문하지 않은 노드만 추가
        q.push(next);
        dist[next] = dist[cur] + 1;  // 큐에 추가할 때 거리 업데이트
      }
    }
  }

  // dist 순회하며 가장 멀리 떨어진 노드 구하기
  int cnt = 0;
  int max_dist = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > max_dist) {
      max_dist = dist[i];
      cnt = 1;
    } else if (dist[i] == max_dist) {
      cnt++;
    }
  }
  return cnt;
}

int solution(int n, vector<vector<int>> edge) {
  v.resize(n + 1);
  dist.resize(n + 1, -1);

  for (int i = 0; i < edge.size(); i++) {  // 간선
    int a = edge[i][0];
    int b = edge[i][1];
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int answer = FindDist(n);

  return answer;
}