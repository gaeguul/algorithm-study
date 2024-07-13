#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> v;

ll getCount(ll length) {
  ll count = 0;
  for (int i = 0; i < v.size(); i++) {
    count += (v[i] / length);
  }
  return count;
}

int main(void) {
  int k, n;  // k: 이미 가지고 있는 랜선의 개수, n: 필요한 랜선의 개수
  scanf("%d %d", &k, &n);

  ll left = 1;   // 최소한 자를 수는 있어야 하므로 1로 정한다
  ll right = 1;  // 가장 긴 랜선의 길이
  ll mid;

  for (int i = 0; i < k; i++) {
    ll x;
    scanf("%lld", &x);
    v.push_back(x);

    if (right < x) right = x;
  }

  while (left <= right) {
    mid = (left + right) / 2;
    ll count = getCount(mid);
    if (count >= n) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  printf("%lld\n", right);
}