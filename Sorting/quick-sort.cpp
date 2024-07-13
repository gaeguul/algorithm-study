#include <algorithm>
using namespace std;

int n;
int target[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void quickSort(int* target, int start, int end) {
  if (start >= end) return;

  int pivot = start;  // 비교 기준이 되는 수의 index
  int left = start + 1;
  int right = end;

  while (left <= right) {
    // left로 pivot값보다 큰 값을 찾는다
    while (left <= end && target[left] <= target[pivot]) left++;

    // right로 pivot값보다 작은 값을 찾는다
    while (right > start && target[right] >= target[pivot]) right--;

    if (left > right)
      // 엇갈렸다면 pivot과 작은 데이터(right)를 교체
      // pivot을 기준으로 왼쪽은 작은 수, 오른쪽은 큰 수
      swap(target[pivot], target[right]);
    else
      // 엇갈리지 않았다면 작은 데이터(left)와 큰 데이터(right)를 교체
      swap(target[left], target[right]);
  }

  quickSort(target, start, right - 1);
  quickSort(target, right, end);
}