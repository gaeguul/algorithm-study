#include <iostream>
#include <vector>
using namespace std;

#define MAX 9
int N;
vector<int> arr(MAX, 0);        // 인덱스 0~N-1
vector<bool> used(MAX, false);  // 인덱스 1~N

void PrintArr() {
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}

/**
 * cur - 배열에서 현재 채워야 하는 인덱스
 */
void FindArr(int cur) {
  if (cur >= N) {
    PrintArr();
    return;
  }

  for (int i = 1; i <= N; i++) {  // 숫자 i를 배열에 넣을지 판단한다
    if (!used[i]) {  // 사용되지 않았을 때에만 배열에 삽입한다
      used[i] = true;    // 사용한 숫자 i를 사용했다고 표시한다
      arr[cur] = i;      // 현재 인덱스에 숫자를 추가한다
      FindArr(cur + 1);  // 다음 인덱스에 추가할 숫자를 탐색한다
      used[i] = false;  // 숫자 i를 다시 사용할 수 있도록 used 값을 변경한다
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;

  FindArr(0);
}