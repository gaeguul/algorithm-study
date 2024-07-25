// n개의 홈을 이용해 이동하면서 y=T까지 올라가기
// 최소 이동 횟수 출력하기
// 정상에 오를 수 없으면 -1
// 현재 나의 위치 (0, 0)
// n개의 홈의 위치 (x,y)

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, T;  // 홈의 총 개수는 n+1이다 (원점 포함하므로)
vector<pair<int, int>> point;  // 홈의 좌표
queue<int> q;                  // 방문해야 하는 좌표의 인덱스
vector<int> visited(
    n + 1);  // 0이면 방문X, 1이상이면 해당 노드까지 필요한 모든 노드의 수

// 두 번째 요소를 기준으로 오름차순 정렬하는 비교 함수
// 두 번째 요소 같으면 첫 번째 요소를 기준으로 한다
bool compareByY(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first < b.first;
}

int bfs() {
  q.push(0);
  visited[0] = 1;

  while (!q.empty()) {
    int idx = q.front();
    q.pop();

    // 현재 좌표의 y좌표가 T라면 최소이동횟수 구했다는 뜻
    if (point[idx].second == T) return visited[idx] - 1;

    // 현재 좌표의 주변에 있는 좌표들을 검사해서 2차이 나는 좌표들만 확인
    for (int i = idx - 1; i > 0; i--) {
      if (abs(point[i].second - point[idx].second) > 2) break;
      if (abs(point[i].first - point[idx].first) > 2 || visited[i] != 0) {
        continue;
      }
      visited[i] = visited[idx] + 1;
      q.push(i);
    }

    for (int i = idx + 1; i <= n; i++) {
      if (abs(point[i].second - point[idx].second) > 2) break;
      if (abs(point[i].first - point[idx].first) > 2 || visited[i] != 0) {
        continue;
      }
      visited[i] = visited[idx] + 1;
      q.push(i);
    }
  }
  return -1;
}

int main(void) {
  cin >> n >> T;
  point.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    point.push_back({x, y});
  }
  visited.resize(n + 1, 0);
  sort(point.begin(), point.end(), compareByY);  // y좌표를 기준으로 정렬한다

  cout << bfs() << '\n';
}
