#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(void) {
  int n;
  scanf("%d", &n);

  vector<int> v;
  set<int> s;         // 중복만 제거
  vector<int> vSort;  // 중복 제거 + 정렬까지
  map<int, int> m;    // vSort의 인덱스 저장

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    v.push_back(num);
    s.insert(num);  // 중복 제거
  }

  for (auto i = s.begin(); i != s.end(); i++) {
    vSort.push_back(*i);
  }

  // 정렬
  sort(vSort.begin(), vSort.end());

  // 정렬된 배열의 인덱스까지 저장
  for (int i = 0; i < vSort.size(); i++) {
    m[vSort[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", m[v[i]]);
  }
}

// 2차원 벡터도 sort 가능하다. 이때 벡터의 첫번째 요소를 기준으로 정렬한다.