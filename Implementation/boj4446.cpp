#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<char> v = {'a', 'i', 'y', 'e', 'o', 'u'};  // 모음 (3번째 전으로)
vector<char> c = {
    'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g',
    'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};  // 자음 (10번째 전으로)

string convert_to_en(string rot) {
  string en = "";

  for (int i = 0; i < rot.size(); i++) {
    char ch = rot[i];
    bool is_upper = false;  // 대문자인 경우

    // 알파벳이라면
    if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
      if ('A' <= ch && ch <= 'Z') {
        is_upper = true;
        ch = tolower(ch);
      }

      // 자음인지 모음인지 찾기
      if (find(v.begin(), v.end(), ch) != v.end()) {
        // 모음인 경우
        int idx = find(v.begin(), v.end(), ch) - v.begin();
        ch = v[(idx + 3) % v.size()];

      } else {
        // 자음인 경우
        int idx = find(c.begin(), c.end(), ch) - c.begin();
        ch = c[(idx + 10) % c.size()];
      }

      if (is_upper) {
        ch = toupper(ch);
      }
    }
    en += ch;
  }

  return en;
}

int main(void) {
  string rot;
  while (getline(cin, rot)) {
    cout << convert_to_en(rot) << '\n';
  }
}

// 처음에 반복문의 조건을 while(true)라고 적어서 '출력 초과'가 떴다.
// 별도 종료 조건이 따로 명시되지 않았으므로 EOF(End of File, 파일의 끝)을
// 판단해야 해야 한다. 이때 getline으로 판단하거나 혹은 try-catch 문도 가능하다.