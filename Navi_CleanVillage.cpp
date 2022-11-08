#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int place[m];
  for (int i = 0; i < m; ++i) {
    cin >> place[i];
  }
  int prefixdiff[m];
  prefixdiff[0] = abs(place[0]);
  for (int i = 1; i < m; ++i) {
    prefixdiff[i] = prefixdiff[i - 1] + abs(place[i] - place[i - 1]);
  }
  int res = INT_MAX;
  for (int i = n - 1; i < m; ++i) {
    if (i == (n - 1)) {
      res = min(res, prefixdiff[i]);
    } else {
      res = min(res,
                prefixdiff[i] - prefixdiff[i - n + 1] + abs(place[i - n + 1]));
    }
    cout << res << "\n";
  }
  return 0;
}