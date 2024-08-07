#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 101

int arr[MAX][MAX];  // 인덱스 1~n, 각 선수가 승리한 상대선수들, 인접행렬

// 정확하게 순위가 정해진 선수의 수 반환한다
int CalcRank(int n) {
  // 인접 행렬을 사용하여 선수들의 모든 승패를 업데이트한다
  for (int k = 1; k <= n; k++) {      // 중간 선수
    for (int i = 1; i <= n; i++) {    // 이긴 선수
      for (int j = 1; j <= n; j++) {  // 진 선수
        // i가 k를 이기고, k가 j를 이긴 경우 i가 j를 이긴 것과 같다
        if (arr[i][k] == 1 && arr[k][j] == 1) {
          arr[i][j] = 1;
          arr[j][i] = -1;
        }
      }
    }
  }

  int answer = 0;  // 정확한 순위를 가진 선수의 수
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      // 자기자신 제외한 모든 선수들과의 승패가 1 또는 -1인 경우
      if (arr[i][j] != 0) {
        cnt++;
      }
    }
    if (cnt == n - 1) {
      answer++;
    }
  }

  return answer;
}

int solution(int n, vector<vector<int>> results) {
  for (int i = 0; i < results.size(); i++) {
    int win = results[i][0];   // 이긴 선수
    int lose = results[i][1];  // 진 선수
    arr[win][lose] = 1;
    arr[lose][win] = -1;
  }

  return CalcRank(n);
}
