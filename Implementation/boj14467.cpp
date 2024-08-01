#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 11

struct Cow {
  int cnt;        // 이동 횟수
  int loc;        // 현재 위치
  bool appeared;  // 이전에 등장한 적이 있는지 여부
};

int main(void) {
  int N;
  cin >> N;

  vector<Cow> cows(MAX_SIZE, Cow{0, false});
  for (int i = 0; i < N; i++) {
    int idx, loc;
    cin >> idx >> loc;

    if (!cows[idx].appeared) {
      // idx번째 소가 등장한 적이 없다면
      // cnt 변화시키지 않고 appeared 만 true로 바꾼다
      cows[idx].appeared = true;
    } else if (loc != cows[idx].loc) {
      // 등장한 적이 있고 현재 위치와 이전 위치가 다르다면 cnt++
      cows[idx].cnt++;
    }

    cows[idx].loc = loc;
  }

  int answer = 0;
  for (int i = 1; i < MAX_SIZE; i++) {
    answer += cows[i].cnt;
  }

  cout << answer << '\n';
}