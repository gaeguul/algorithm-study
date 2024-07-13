#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> cards;

int doOwnCard(int card) {
  int left = 0;
  int right = cards.size() - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;
    if (cards[mid] < card)
      left = mid + 1;
    else if (cards[mid] > card)
      right = mid - 1;
    else
      return 1;
  }
  return 0;
}

int main(void) {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cards.push_back(x);
  }

  sort(cards.begin(), cards.end());

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int card;
    scanf("%d", &card);
    printf("%d ", doOwnCard(card));
  }
}