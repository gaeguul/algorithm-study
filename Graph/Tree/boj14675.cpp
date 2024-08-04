#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, a, b, Q, t, k;
  vector<vector<int>> ed;

  cin >> N;
  ed.resize(N + 1, vector<int>(0));
  for (int i = 1; i < N; i++) {  // N-1개의 간선 정보
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> t >> k;  // t가 1이면 단절점인지, 2이면 단절선인지 질의
    bool answer = true;
    if (t == 1) {
      // 트리의 리프 노드를 제외한 모든 노드는 단절점이다
      // 해당 노드와 연결된 노드가 없으면 리프 노드이다
      if (ed[k].size() <= 1) {
        // 리프 노드인 경우
        answer = false;
      } else {
        answer = true;
      }
    } else {
      // 트리의 모든 선은 단절선이다
      answer = true;
    }

    if (answer) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}