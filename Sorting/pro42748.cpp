#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int getAnswer(vector<int>& array, vector<int>& command) {
  int start = command[0] - 1;
  int end = command[1] - 1;
  int target = command[2] - 1;

  vector<int> slice;
  for (int i = start; i <= end; i++) {
    slice.push_back(array[i]);
  }

  sort(slice.begin(), slice.end());

  return slice[target];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for (int i = 0; i < commands.size(); i++) {
    answer.push_back(getAnswer(array, commands[i]));
  }

  return answer;
}