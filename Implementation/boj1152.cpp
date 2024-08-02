#include <iostream>
#include <string>
using namespace std;

int main(void) {
  cin.tie(NULL), cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  string str;
  getline(cin, str);

  int cnt = 0;
  bool isword = false;  // 현재 단어 안에 있는지 여부

  for (int i = 0; i < str.size(); i++) {
    if (str[i] != ' ') {
      if (isword == false) {
        // 이전이 공백이었으면 단어 수 증가
        cnt++;
        isword = true;
      }
    } else {
      // 공백이면 isword 변경
      isword = false;
    }
  }

  cout << cnt << '\n';
}