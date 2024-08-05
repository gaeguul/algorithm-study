#include <string>
#include <vector>

using namespace std;

vector<string> words = {"zero", "one", "two",   "three", "four",
                        "five", "six", "seven", "eight", "nine"};

/**
s에 매칭되는 영단어가 있는지 확인한다
있으면 - 해당 숫자 반환
없으면 - 숫자 -1 반환
*/
int IsMatched(string s) {
  for (int i = 0; i < 10; i++) {
    if (words[i] == s) {
      return i;
    }
  }
  return -1;
}

string GetOriginal(string s) {
  string ans = "";
  string tmp = "";

  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      ans += s[i];  // 숫자라면 ans에 추가한다
    } else {        // 알파벳인 경우
      tmp += s[i];
      // tmp에 대응되는 영단어가 있는지 확인한다
      if (IsMatched(tmp) != -1) {
        ans += to_string(IsMatched(tmp));
        tmp = "";
      }
    }
  }
  return ans;
}

int solution(string s) {
  string original = GetOriginal(s);
  int answer = stoi(original);
  return answer;
}