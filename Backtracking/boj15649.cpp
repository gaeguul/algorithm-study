#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<bool> visited;

void PrintArr() {
  for (int i = 0; i < M; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void MakeArr(int cnt) {
  if (cnt == M) {
    PrintArr();
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      arr[cnt] = i;
      MakeArr(cnt + 1);
      visited[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M;
  arr.resize(M);
  visited.resize(N + 1, false);
  MakeArr(0);
}