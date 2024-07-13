#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

/** time분 동안 심사 가능한 인원 수 구하기 */
ll getCount(vector<int>& times, ll time) {
  ll count = 0;
  for (int i = 0; i < times.size(); i++) {
    count += (time / times[i]);
  }
  return count;
}

long long solution(int n, vector<int> times) {
  sort(times.begin(), times.end());

  ll left = 1;
  ll right = times[times.size() - 1] * (ll)n;  // 명시적 형변환 안하면 틀림
  ll answer = 0;

  /** mid분 동안 n명이 모두 심사를 받을 수 있는지 검사 */
  while (left <= right) {
    ll mid = (left + right) / 2;
    if (getCount(times, mid) >= n) {
      // 더 적은 시간으로도 가능한지 확인해봐야 함
      right = mid - 1;
      answer = mid;
    } else {
      // mid분으로는 불충분하므로 시간 늘려야 함
      left = mid + 1;
    }
  }

  return answer;
}

int main(void) {
  int n = 6;
  vector<int> times = {7, 10};
  printf("%lld\n", solution(n, times));
}