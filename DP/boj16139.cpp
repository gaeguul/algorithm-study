#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ALPHA_SIZE 26

string S;
int Q;
vector<vector<int>> v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> S;
  cin >> Q;
  v.resize(S.size(), vector<int>(ALPHA_SIZE, 0));

  // 문자열의 i번째 문자까지 등장한 알파벳의 개수
  for (int i = 0; i < S.size(); i++) {
    int idx = (int)(S[i] - 'a');  // i번째 문자가 몇번째 문자인지
    if (i > 0) {
      for (int j = 0; j < ALPHA_SIZE; j++) {
        // 직전 문자까지 등장한 횟수 그대로 복사
        v[i][j] = v[i - 1][j];
      }
    }
    v[i][idx]++;
  }

  for (int i = 0; i < Q; i++) {
    char A;
    int L, R;
    cin >> A >> L >> R;

    int idx = (int)(A - 'a');
    int min = 0, max = v[R][idx];
    if (L != 0) {
      min = v[L - 1][idx];
    }
    int answer = max - min;
    cout << answer << '\n';
  }
}

// 첫번째 시도: 2중 for문 사용해서 50점 맞았다.
// 두번째 시도: 다이나믹 프로그래밍의 bottom-up 방법을 사용했다.