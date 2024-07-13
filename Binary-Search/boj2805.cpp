#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;  //

vector<ll> v;

/**
 * 설정한 절단기 높이에 따른 자른 나무 길이의 합 구하기
 * @param height 절단기 높이
 * @return 자른 나무 길이의 합
 */
ll getCutTree(ll height) {
  ll result = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= height) continue;
    result += (v[i] - height);
  }
  return result;
}

int main(void) {
  ll n, m;  // n: 나무의 수, m: 필요한 나무의 길이
  scanf("%lld %lld", &n, &m);

  ll left = 0;
  ll right = 0;  // 가장 긴 나무의 길이
  for (int i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    v.push_back(x);
    if (right < x) right = x;
  }

  // 개수가 매우 크므로 이분탐색 진행하며 절단해서 생성되는 나무 길이 구하기
  while (left <= right) {
    ll mid = (left + right) / 2;
    ll cut_tree = getCutTree(mid);

    if (cut_tree >= m) {
      // 최소 나무 길이 m 이상을 확보해야 하므로 등호가 들어간다
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  printf("%lld\n", right);
}