#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int arr[500][500] = {0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int num;
      cin >> num;
      arr[i][j] = num;
    }
  }

  // arr 마지막 줄에서 윗 줄로 올라가며 두 수 중 최댓값을 윗 수와의 합 저장하기
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
    }
  }

  cout << arr[0][0] << '\n';
}