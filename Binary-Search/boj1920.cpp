#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  vector<int> arr, nums;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    arr.push_back(num);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int num;
    scanf("%d", &num);
    nums.push_back(num);
  }

  sort(arr.begin(), arr.end());

  /* nums[i]가 arr에 존재하는지 알아내기 */
  for (int i = 0; i < m; i++) {
    int low = 0;
    int high = n - 1;
    int mid;

    /**
     * 이분탐색 진행
     * nums[i]를 arr[mid]와 비교해서 다음 검사 범위를 정한다
     * 1. 일치하면 성공
     * 2. nums[i]가 작다면, 검사범위를 작은 쪽으로 변경
     * 3. nums[i]가 크다면, 검사범위를 큰 쪽으로 변경
     * 종료 조건: 더 이상 검사할 것이 없는 경우 (low > high 인 경우)
     */
    while (low <= high) {
      mid = (low + high) / 2;

      if (nums[i] == arr[mid]) {
        break;
      } else if (nums[i] < arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (nums[i] == arr[mid])
      printf("1\n");
    else
      printf("0\n");
  }
}