#include <iostream>
#include <vector>
using namespace std;

int n, s;  // n: 수열의 길이, s: 부분 수열의 합
int cnt;
vector<int> v;  // 수열

/**
 * 부분 수열의 길이가 len일 때의 수열의 합 구하기
 * @param cur 부분 수열에 포함할지 말지 결정할 수의 인덱스
 * @param sum 부분 수열의 합
 */
void get_cnt(int cur, int sum) {
  /**
   * 종료조건
   * cur이 수열 크기를 넘어서는 경우
   * 이때 sum이 s이면 총 개수+1
   */
  if (cur == n) {
    if (sum == s) cnt++;
    return;
  }

  get_cnt(cur + 1, sum);  // 현재 원소를 포함하지 않은 경우
  get_cnt(cur + 1, sum + v[cur]);  // 현재 원소를 포함한 경우
}

int main(void) {
  cin >> n >> s;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  get_cnt(0, 0);
  if (s == 0) cnt--;  // s가 0일 때 공집합도 카운트되므로 -1 한다.

  cout << cnt << '\n';
}