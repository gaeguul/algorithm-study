#include <limits.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using Info = pair<string, string>;

int N, M;
vector<Info> v;        // 각 기타의 이름과 곡 연주 가능한지 여부
vector<bool> visited;  // 기타 사용했는지 여부
int answer = INT_MAX;  // 기타 최소 개수
int max_songs = 0;     // 연주 가능한 곡의 최대 개수

/**
 * @param cur 현재 기타의 인덱스
 * @param cnt_guitar 필요한 기타 개수
 */
void FindAnswer(int cur, int cnt_guitar) {
  // 종료 조건: 모든 기타를 확인한 경우
  if (cur == N) {
    vector<bool> song(M, false);          // 이미 포함된 곡인지 판단
    int cnt_songs = 0;                    // 연주 가능한 곡 개수
    for (int i = 0; i < N; i++) {         // 모든 기타 i
      if (visited[i] == false) continue;  // 포함되지 않은 기타는 제외
      string arr = v[i].second;           // 기타 i가 연주 가능한 곡들
      for (int j = 0; j < arr.length(); j++) {
        if (arr[j] == 'Y' && song[j] == false) {
          song[j] = true;
          cnt_songs++;  // 곡 개수 하나 증가
        }
      }
    }
    if (max_songs < cnt_songs) {
      // 연주 가능한 곡의 개수가 더 많은 경우
      max_songs = cnt_songs;
      answer = cnt_guitar;
    } else if (max_songs == cnt_songs) {
      // 같은 곡을 더 적은 개수의 기타로 연주할 수 있는 경우
      if (cnt_guitar < answer) answer = cnt_guitar;
    }
    return;
  }

  visited[cur] = true;
  FindAnswer(cur + 1, cnt_guitar + 1);  // cur번째 기타를 포함시킨 경우
  visited[cur] = false;
  FindAnswer(cur + 1, cnt_guitar);  // cur번째 기타를 포함하지 않은 경우
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  v.resize(N);
  visited.resize(N, false);

  for (int i = 0; i < N; i++) {
    cin >> v[i].first >> v[i].second;
  }

  FindAnswer(0, 0);

  if (answer == 0) answer--;
  cout << answer << '\n';
}

// 처음에 문제를 잘못 이해했다.
// 모든 곡을 연주해야 하는 게 아니라 최대한 많은 곡을 연주하면 된다.