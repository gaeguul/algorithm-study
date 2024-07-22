#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> v;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
int answer = 1;  // 늑대를 막을 수 있으면 1, 그렇지 않으면 0

// (r,c)에 양이 있는지 체크
bool isSheep(int r, int c) {
  if (0 <= r && r < R && 0 <= c && c < C) {
    if (v[r][c] == 'S') return true;
  }
  return false;
}

// 늑대 주변에 적어도 한마리 이상의 양이 있는지 확인하기
bool isSheepAroundWolf(int r, int c) {
  for (int i = 0; i < 4; i++) {
    int nr = dr[i] + r;
    int nc = dc[i] + c;
    if (isSheep(nr, nc)) {
      return true;
    }
  }
  return false;
}

int main(void) {
  cin >> R >> C;
  v.resize(R, vector<char>(C, '.'));

  for (int i = 0; i < R; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < C; j++) {
      char ch = str[j];
      if (ch == '.') ch = 'D';  // 울타리는 어디에 세워도 상관없음
      v[i][j] = ch;
    };
  }

  // 늑대를 한마리씩 검사하면서 동서남북에 양이 있는지 확인하기
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (v[i][j] == 'W' && isSheepAroundWolf(i, j)) {
        answer = 0;
      }
    }
  }

  cout << answer << '\n';

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) cout << v[i][j];
    cout << '\n';
  }
}