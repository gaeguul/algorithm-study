#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int n, m, x;
vector<vector<int>> tasks;
vector<bool> visited;  // 작업 x를 위해 먼저 해야 하는 일인지 판단
int answer;

int main(void) {
  cin >> n >> m;
  tasks.resize(n + 1);
  visited.resize(n + 1, false);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    tasks[b].push_back(a);
  }
  cin >> x;

  queue<int> q;
  q.push(x);  // 작업 x부터 시작해서 거꾸로 추적한다.
  while (!q.empty()) {
    int current = q.front();
    q.pop();

    if (visited[current]) continue;  // 이미 추가한 작업이면 skip한다
    visited[current] = true;  // current 작업을 해야 하는 작업에 추가한다

    if (current != x) answer++;  // 작업 x는 해야 하는 일에서 제외한다

    vector<int> v = tasks[current];  // current 작업 직전에 해야 하는 작업들
    for (int i = 0; i < v.size(); i++) {
      q.push(v[i]);
    }
  }

  cout << answer << '\n';
}
