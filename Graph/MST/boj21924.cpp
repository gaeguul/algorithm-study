#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001
#define ll long long

struct INFO {
  int start, end, cost;
};

int N, M;           // N: 건물개수, M: 도로개수
vector<INFO> Edge;  // 두 건물을 잇는 도로의 비용
int Parent[MAX];    // 각 건물의 루트 노드에 해당하는 건물
ll Total_Cost = 0;  // 모든 도로 설치할 때의 비용
ll Answer = 0;      // 최소한의 도로 설치할 때의 비용

/** cost를 기준으로 오름차순으로 정렬한다 */
bool Compare(INFO a, INFO b) { return a.cost < b.cost; }

int Find_Root(int x) {
  if (Parent[x] == x)
    return x;
  else
    return Parent[x] = Find_Root(Parent[x]);
}

void Union(int x, int y) {
  x = Find_Root(x);
  y = Find_Root(y);

  if (x < y)
    Parent[y] = x;
  else
    Parent[x] = y;
}

/** 모든 건물의 루트 노드가 동일해야 한다 */
bool IsConnected() {
  for (int i = 2; i <= N; i++) {
    if (Find_Root(1) != Find_Root(i)) return false;
  }
  return true;
}

int main(void) {
  cin >> N >> M;

  /** 자기자신을 루트노드로 초기화 */
  for (int i = 1; i <= N; i++) {
    Parent[i] = i;
  }
  /** 건물에 따른 도로 비용 입력받기 */
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    Edge.push_back({a, b, c});
    Total_Cost += c;
  }

  sort(Edge.begin(), Edge.end(), Compare);

  for (int i = 0; i < Edge.size(); i++) {
    int s = Edge[i].start;
    int e = Edge[i].end;
    int c = Edge[i].cost;

    /** 두 건물 연결했을 때 사이클 없다면 연결한다 */
    if (Find_Root(s) != Find_Root(e)) {
      Union(s, e);
      Answer += c;
    }
  }

  /** 모든 건물이 연결되어 있는지 확인 */
  if (!IsConnected()) {
    cout << "-1\n";
  } else {
    cout << Total_Cost - Answer << '\n';
  }
}