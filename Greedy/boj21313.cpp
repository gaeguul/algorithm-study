#include <iostream>
#include <vector>
using namespace std;

int HANDS = 8;

int main(void) {
  int n;
  cin >> n;
  vector<int> v;
  v.resize(n, 0);

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      v[i] = 1;
    } else {
      v[i] = 2;
    }
  }

  if (v[0] == v[n - 1]) {
    v[n - 1] = 3;
  }

  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
}