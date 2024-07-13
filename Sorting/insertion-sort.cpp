#include <cstdio>
#include <vector>
using namespace std;

/**
 * @param list a list that we are gonna do insertion sort
 * @param n the length of the list
 */
void insertionSort(vector<int>& list) {
  /**
   * 0번째 숫자는 이미 정렬되었다고 볼 수 있으므로
   * 1번째 숫자부터 삽입할 위치를 찾는다.
   */
  for (int i = 1; i < list.size(); i++) {
    int j;
    int key = list[i];  // 현재 삽입될 숫자인 i번째 정수

    /**
     * 현재 i-1까지 정렬되어 있는 상황에서 i번째 수(key)를 삽입할 적절한
     * 위치(j+1)를 오른쪽에서 왼쪽 방향으로 찾는다. key가 들어갈 자리를 만들기
     * 위해 숫자들을 오른쪽으로 이동시킨다.
     */
    for (j = i - 1; j >= 0 && list[j] > key; j--) {
      list[j + 1] = list[j];  // 숫자들을 오른쪽으로 밀기
    }

    list[j + 1] = key;
  }
}

int main(void) {
  vector<int> list = {31, 25, 12, 22, 11};

  insertionSort(list);

  for (int i = 0; i < list.size(); i++) {
    printf("%d ", list[i]);
  }
}