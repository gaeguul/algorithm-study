#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using Point = pair<ll, ll>;
vector<Point> points;  // 인덱스: 0 ~ N-1

int N, total;

int main(void) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        // 3개의 점 뽑음 (i,j,k)
        Point p1 = points[i];
        Point p2 = points[j];
        Point p3 = points[k];

        // 피타고라스 정리
        ll len1 = (p1.first - p2.first) * (p1.first - p2.first) +
                  (p1.second - p2.second) * (p1.second - p2.second);
        ll len2 = (p2.first - p3.first) * (p2.first - p3.first) +
                  (p2.second - p3.second) * (p2.second - p3.second);
        ll len3 = (p1.first - p3.first) * (p1.first - p3.first) +
                  (p1.second - p3.second) * (p1.second - p3.second);

        ll max_len = max(len1, max(len2, len3));

        if (max_len * 2 == len1 + len2 + len3) total++;
      }
    }
  }

  cout << total << '\n';
}