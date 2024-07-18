#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;                  // 선수 인원 수
vector<vector<int>> s;  // 각 선수들의 능력치
vector<bool> included;  // 스타트 팀에 포함됐는지 여부
int answer;  // 스타트 팀과 링크 팀의 능력치의 차이의 최솟값

/** 스타트 팀과 링크 팀의 능력치의 차이 구하기 */
int get_score_diff() {
  int start_score = 0;
  int link_score = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (included[i] && included[j]) {
        start_score += s[i][j];
      } else if (!included[i] && !included[j]) {
        link_score += s[i][j];
      }
    }
  }

  return abs(start_score - link_score);
}

/**
 * @param idx 현재 선택한 선수
 * @param pick_cnt 현재까지 스타트 팀에 속한 인원 수
 */
void get_answer(int idx, int pick_cnt) {
  if (1 <= pick_cnt &&
      pick_cnt <= n / 2) {  // 팀 구성의 모든 경우의 수는 (n/2)가지이므로
    answer = min(answer, get_score_diff());
  }

  /** 스타트 팀에 선택할 다음 선수를 고른다 */
  for (int i = idx; i <= n; i++) {  // 현재 선수 idx 기준으로 이후 선수들만
                                    // 고려하여 중복 선택을 방지한다
    included[i] = true;               // 스타트 팀에 포함시킨다
    get_answer(i + 1, pick_cnt + 1);  // 다음 선수를 선택한다
    included[i] = false;              // 링크 팀에 포함시킨다
  }
}

int main(void) {
  cin >> n;

  s.resize(n + 1, vector<int>(n + 1));
  included.resize(n + 1, false);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
      answer += s[i][j];
    }
  }

  get_answer(1, 0);
  cout << answer << '\n';
}
