#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000001

vector<int> solution(vector<int> sequence, int k) {
  int slen = sequence.size();
  int start = 0;
  int end = 0;
  int sum = 0;        // 구간합 [start, end): end - start
  int min_len = MAX;  // 구간합이 k와 같을 때 구간배열의 최소 길이
  int min_start = MAX;  // 구간합이 k와 같을 때 구간배열 최소 시작인덱스

  while (start < slen) {
    if (sum >= k || end == slen) {
      // 구간합이 k보다 크거나 같거나 end==slen이면 start++
      sum -= sequence[start];
      start++;
    } else {  // 구간합이 k보다 작으면 end++
      sum += sequence[end];
      end++;
    }

    // 구간합이 k인지 확인하고 k라면 min_len, min_start 업데이트한다
    if (sum == k) {
      if ((end - start) < min_len) {  // 구간이 더 짧은 경우
        min_len = end - start;
        min_start = start;
      } else if ((end - start) == min_len) {  // 구간의 길이가 기존과 같다면
        if (start < min_start) {  // 시작 인덱스가 더 작은 경우
          min_start = start;
        }
      }
    }
  }

  vector<int> answer = {min_start, min_len + min_start - 1};
  return answer;
}