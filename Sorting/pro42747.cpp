#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
  int hIndex = 0;
  sort(citations.begin(), citations.end());

  for (int i = citations.size() - 1; i >= 0; i--) {
    if (hIndex < citations[i])
      hIndex++;
    else
      break;
  }

  return hIndex;
}

// 1. 처음에 hIndex가 citations의 요소라고 생각했는데, hIndex와 citations은
// 별개이다.
// 2. 참고 https://born2bedeveloper.tistory.com/19