#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> va, vb;

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    va.push_back(num);
  }

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    vb.push_back(num);
  }

  /**
   * va 오름차순 정렬
   * vb 내림차순 정렬
   */
  sort(va.begin(), va.end());
  sort(vb.rbegin(), vb.rend());

  /**
   * k번의 바꿔치기 연산 수행하기
   * Only when va 원소가 더 작을 때만 바꿔치기
   */
  for (int i = 0; i < k; i++) {
    if (va[i] >= vb[i]) break;
    va[i] = vb[i];
  }

  int result = 0;
  for (int i = 0; i < n; i++) result += va[i];

  printf("result %d\n", result);
}