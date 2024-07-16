#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char arr[5][5];     // 자리 배치
bool selected[25];  // 칠공주 여부
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt;  // 소문난 칠공주 결성할 수 있는 모든 경우의 수

/**
 * 7명의 학생들이 서로 인접해 있는지 검사 (BFS)
 */
bool is_adjacent() {
  queue<pair<int, int>> q;
  vector<vector<bool>> check_selected(
      5, vector<bool>(5, false));  // 칠공주 학생들 위치 저장
  vector<vector<bool>> queue_selected(
      5, vector<bool>(5, false));  // BFS 수행하면서 방문한 위치 저장
  bool adjacent = false;

  int tmp = 0;  // 첫번째 학생인지 판단하는 flag 변수
  for (int i = 0; i < 25; i++) {
    if (selected[i]) {
      int x = i / 5;
      int y = i % 5;
      check_selected[x][y] = true;  // 선택된 학생들 7명의 위치 저장
      if (tmp == 0) {
        q.push({x, y});               // 첫번째 학생만 queue에 넣음
        queue_selected[x][y] = true;  // 첫번째 학생 위치에 방문했다고 표시
        tmp++;
      }
    }
  }

  int count_adjacent = 1;
  while (!q.empty()) {  // queue가 빌 때까지 BFS를 수행한다.
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (count_adjacent == 7) {  // 7명의 학생이 모두 인접해있는 경우
      adjacent = true;
      break;
    }

    // 현재 학생 위치에서 동서남북 확인해서 다음 학생이 인접있는지 판단
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
      if (check_selected[nx][ny] &&
          !queue_selected[nx][ny]) {  // 다음 학생이 인접해있고 큐에 들어간 적
                                      // 없는 경우
        queue_selected[nx][ny] = true;
        q.push({nx, ny});
        count_adjacent++;
      }
    }
  }

  return adjacent;
}

/**
 * 뽑은 7명 학생 중 이다솜파 학생이 4명 이상인지 확인
 */
bool is_more_than_four() {
  int som = 0;
  for (int i = 0; i < 25; i++) {
    int x = i / 5;
    int y = i % 5;
    if (selected[i] && arr[x][y] == 'S') som++;
  }

  if (som >= 4)
    return true;
  else
    return false;
}

/**
 * 총 25명 학생들 중에서 7명 선택하기 (조합, 순서 상관 X)
 */
void dfs(int idx, int tot) {
  // 조건 3개 만족하는지 확인한다 (총 인원, som 인원, 인접)
  if (tot == 7) {
    if (is_more_than_four() && is_adjacent()) cnt++;
    return;
  }

  // dfs로 7명의 조합 찾기
  for (int i = idx; i < 25; i++) {  // idx 기준으로 이후만 탐색
    if (selected[i]) continue;
    selected[i] = true;
    dfs(i, tot + 1);
    selected[i] = false;  // i로 시작하는 조합의 경우의 수는 다 찾음
  }
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < 5; j++) {
      arr[i][j] = str[j];
    }
  }

  dfs(0, 0);
  cout << cnt << '\n';
}

// 1.
// 처음에는 조건을 만족하는 경우의 수를 구하려고 시도했는데
// 이렇게 구하면 중복되는 경우를 제거하기 어려워진다.
// 따라서 우선 모든 경우의 수를 구한 뒤에
// 조건을 만족하는지 판단하는 방식으로 고쳤다.

// 2.
// DFS와 BFS가 모두 쓰인 문제

// 3.
// 순열과 조합 구분하기 (이 문제에서는 조합이 사용되었다)
// 순열과의 차이점은 조합은 순서가 상관이 없다는 것이다.
// 조합을 재귀함수로 구현하려면 시작점을 결정한 이후에
// 그 전의 요소는 쳐다보지 않는다.