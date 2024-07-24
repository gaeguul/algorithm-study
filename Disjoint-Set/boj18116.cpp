#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAX_SIZE 1000001
int parent[MAX_SIZE];
int cnt[MAX_SIZE];

/** 부품 x의 최상위 부모 부품의 번호를 찾는다. */
int find_parent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = find_parent(parent[x]);
}

/** a와 b의 최상위 부모 부품을 합친다. */
void union_sets(int a, int b) {
  a = find_parent(a);  // a의 최상위 부모 부품 번호
  b = find_parent(b);  // b의 최상위 부모 부품 번호

  if (a < b) {
    parent[b] = a;
    cnt[a] += cnt[b];
  } else {
    parent[a] = b;
    cnt[b] += cnt[a];
  }
}

int main(void) {
  /** 시간 초과 해결을 위해 추가 */
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  /* 각 부품의 부모를 자기자신으로 초기화한다 */
  for (int i = 0; i < MAX_SIZE; i++) {
    parent[i] = i;
    cnt[i] = 1;
  }

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    char ch;
    cin >> ch;
    if (ch == 'I') {
      int a, b;
      cin >> a >> b;
      if (find_parent(a) != find_parent(b))
        union_sets(a, b);  // a와 b 집합을 합친다
    } else {
      // ch=='Q'
      int c;
      cin >> c;
      cout << cnt[find_parent(c)] << '\n';
    }
  }

  return 0;
}

/**
 * cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
 * 이 코드 없으면 시간 초과 난다.. :)
 * 시간 초과 나면 입출력 함수 확인하자.
 */