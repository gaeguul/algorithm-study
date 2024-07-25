#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 뻔과 데기를 cur만큼 반복한 문장을 생성한다
 */
vector<int> MakeSentence(int cur) {
  vector<int> sentence = {0, 1, 0, 1};
  for (int i = 0; i < cur; i++) {
    sentence.push_back(0);
  }
  for (int i = 0; i < cur; i++) {
    sentence.push_back(1);
  }
  return sentence;
}

int main(void) {
  int A, T, Flag;  // Flag: 0(뻔), 1(데기)
  cin >> A >> T >> Flag;
  vector<int> v;  // i번째 사람이 어떤 flag를 외치는지

  int cnt = 0;  // 현재까지 외친 사람의 수 (-> A로 나눠서 나머지로 사람 구하기)
  int flag_cnt = 0;  // 현재까지 flag를 외친 사람의 수
  int cur = 2;       // 현재 반복해야 하는 뻔과 데기의 수

  while (flag_cnt != T) {
    vector<int> sentence = MakeSentence(cur);

    // 문장 차례대로 탐색하며 Flag와 같은 경우에는 cnt를 증가한다
    for (int j = 0; j < sentence.size(); j++) {
      if (sentence[j] == Flag) {
        flag_cnt++;
        if (flag_cnt == T) {
          cout << cnt % A << '\n';
          return 0;
        }
      }
      cnt++;
    }
    cur++;
  }
}