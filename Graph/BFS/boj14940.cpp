#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using Point = pair<int, int>;

int n, m;
Point target;
vector<vector<int>> map;   // (n, m)
vector<vector<int>> dist;  // target으로부터의 거리

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

/** target에서 모든 1 땅까지의 거리를 계산한다 */
void GetDist() {
  queue<Point> q;
  q.push(target);
  dist[target.first][target.second] = 1;

  while (!q.empty()) {
    int curx = q.front().first;
    int cury = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {  // 현재 위치 주변을 탐색한다
      int nextx = curx + dx[i];
      int nexty = cury + dy[i];

      if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m) {
        // 최소거리를 보장하기 위해 들린 적이 없는 땅만 방문한다
        if (dist[nextx][nexty] == 0 && map[nextx][nexty] != 0) {
          // 현재 위치보다 1 떨어진 거리이므로 거리를 1 증가시킨다
          dist[nextx][nexty] = dist[curx][cury] + 1;
          q.push({nextx, nexty});
        }
      }
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;

  map.resize(n, vector<int>(m, 0));
  dist.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];

      if (map[i][j] == 2) {
        target.first = i;
        target.second = j;
      }
    }
  }

  GetDist();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        cout << "0 ";
      } else {
        cout << dist[i][j] - 1 << " ";
      }
    }
    cout << '\n';
  }
}
