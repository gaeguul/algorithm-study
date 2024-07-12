#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

/** 이진탐색으로 target보다 큰 값이 처음 나타나는 위치를 찾는다 */
int find_upper_bound(vector<int>& v, int target) {
  int left = 0;
  int right = v.size();
  int mid;

  while (left < right) {
    mid = (left + right) / 2;

    if (v[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return right;
}

/** 이진탐색으로 target 이상이 처음 나타나는 위치를 찾는다 */
int find_lower_bound(vector<int>& v, int target) {
  int left = 0;
  int right = v.size();
  int mid;

  while (left < right) {
    mid = (left + right) / 2;

    if (v[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return right;
}

int get_count(vector<int>& v, int target) {
  return find_upper_bound(v, target) - find_lower_bound(v, target);
}

int main(void) {
  int n, m;
  vector<int> cards;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    cards.push_back(num);
  }

  sort(cards.begin(), cards.end());  // 오름차순으로 정렬해야 이진탐색 가능

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int target;
    scanf("%d", &target);
    printf("%d ", get_count(cards, target));
  }
}