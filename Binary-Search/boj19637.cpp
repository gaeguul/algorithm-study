#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Power {
  string name;
  ll limit;
};

int N, M;
vector<Power> powers;

// 두 구조체를 비교할 때 Power의 limit를 기준으로 한다.
bool Comp(const Power& p, ll val) { return p.limit < val; }

void JudgePower(ll input) {
  // input 이상의 limit가 처음으로 등장하는 위치 구하기
  auto it = lower_bound(powers.begin(), powers.end(), input, Comp);
  cout << it->name << '\n';
  return;
}

int main(void) {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M;
  powers.resize(N);

  // N가지의 칭호 입력 받기
  for (int i = 0; i < N; i++) {
    cin >> powers[i].name >> powers[i].limit;
  }

  // M개의 캐릭터의 전투력 입력 받기
  for (int i = 0; i < M; i++) {
    ll input;
    cin >> input;
    JudgePower(input);
  }
  return 0;
}

// lower_bound 함수를 이용했는데
// 구조체를 비교해야 해서 compare 함수를 custom하여 사용했다.