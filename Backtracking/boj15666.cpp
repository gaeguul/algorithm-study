#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 숫자 중복 가능, 오름차순(=비내림차순)
int n, m;
set<int> s;  // 수열의 중복 제거 + 오름차순 정렬하기 위한 집합
vector<int> v;    // 집합 s를 vector로 변환한 수열
vector<int> arr;  // 출력할 수열 (크기: m)

/** 만들어진 수열 arr 출력하기 */
void print_arr() {
  for (int i = 0; i < m; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return;
}

/**
 * @param idx 수열 v에서 idx 포함한 오른쪽의 수만 포함한다
 * @param cur 수열 arr에서 현재 채워야 하는 원소 인덱스
 */
void func(int idx, int cur) {
  // 종료조건: 수열 arr이 모두 완성된 경우
  if (cur == m) {
    print_arr();
    return;
  }

  // v의 i번째 수를 arr[cur]에 추가한다
  for (int i = idx; i < v.size(); i++) {
    arr[cur] = v[i];
    func(i, cur + 1);
  }
}

int main(void) {
  cin >> n >> m;
  arr.resize(m);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }

  for (auto i = s.begin(); i != s.end(); i++) {
    v.push_back(*i);
  }

  func(0, 0);

  return 0;
}

// 입력된 수열에서 중복된 수를 제거하기 위해 집합을 사용했는데
// 숫자를 하나씩 추가할 때 이전 값과 직접 비교해서 중복을 방지할 수 있다