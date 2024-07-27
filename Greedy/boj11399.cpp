#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1000

int main(void) {
  int n;
  int time[MAX];
  int sum = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> time[i];
  }
  sort(time, time + n);

  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += time[i];
    sum += cur;
  }

  cout << sum << '\n';
}