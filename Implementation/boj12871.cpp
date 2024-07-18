#include <iostream>
#include <string>
using namespace std;

/** 최대공약수 구하기 */
int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

/** 최소공배수 구하기 */
int lcm(int a, int b) { return (a * b) / gcd(a, b); }

/**
 * s와 t의 최소공배수 길이를 구한 후
 * 그만큼 더해서 무한 문자열을 만든 뒤에 두 문자열을 비교한다
 * @return 1이면 두 문자열 s와 t의 무한 문자열이 동일하다는 것,
 * 0이면 다르다는 것이다
 */
int get_answer(string s, string t) {
  int len = lcm(s.size(), t.size());  // 두 문자열의 최소공배수 길이
  string ss, tt;
  for (int i = 0; i < (len / s.size()); i++) {
    ss += s;
  }
  for (int i = 0; i < (len / t.size()); i++) {
    tt += t;
  }
  return (ss.compare(tt) == 0) ? 1 : 0;
}

int main(void) {
  string s, t;
  cin >> s;
  cin >> t;
  cout << get_answer(s, t) << '\n';
}