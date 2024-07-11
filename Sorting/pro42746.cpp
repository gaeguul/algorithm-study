#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @param a 왼쪽 수
 * @param b 오른쪽 수
 * @return true이면 a가 더 크고, false이면 b가 더 크다.
 */
bool compare(int a, int b) {
  string sa = to_string(a);
  string sb = to_string(b);

  return sa + sb > sb + sa;
}

string solution(vector<int> numbers) {
  int n = numbers.size();

  sort(numbers.begin(), numbers.end(), compare);

  // 모든 숫자가 0인 경우를 처리
  if (numbers[0] == 0) {
    return "0";
  }

  string answer = "";
  for (int i = 0; i < n; i++) {
    answer += to_string(numbers[i]);
  }

  return answer;
}

/**
 * 1. string 클래스를 사용하면 문자열끼리의 연산 수행이 가능하다. (덧셈, 크기
 * 비교)
 * 2. to_string, stoi 이젠 외우자.
 * 3. 처음엔 모든 숫자가 0인 경우를 전혀 생각하지 못했었다. 문제 조건(범위 양끝)
 * 잘 확인하자.
 * 4. 처음엔 버블 정렬로 사용했다가 시간 초과 돼서 sort 메소드와 custom compare
 * 메소드로 변경했다.
 */
