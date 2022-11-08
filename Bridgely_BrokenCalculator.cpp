#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;

  for (int p = 1; p <= t; p++) {

    int a[10];

    for (int i = 0; i < 10; i++) {
      cin >> a[i];
    }

    int target;
    cin >> target;

    queue<pair<int, int>> q;
    set<int> s;

    for (int i = 0; i < 10; i++) {
      if (a[i] == 1) {
        s.insert(i);
        q.push({i, 1});
      }
    }

    int ans = INT_MAX;

    while (!q.empty()) {
      int x = q.front().first;
      int moves = q.front().second;
      q.pop();

      if (x == target) {
        ans = min(ans, moves);
        break;
      }

      for (int j = 0; j < 10; j++) {
        if (a[j] == 1) {
          if (s.find(x * 10 + j) == s.end() and x * 10 + j <= target) {
            // cout<<x*10+j<<endl;
            q.push({x * 10 + j, moves + 1});
            s.insert(x * 10 + j);
          }

          if (s.find(x * j) == s.end() and x * j <= target) {
            // cout<<x*j<<endl;
            q.push({x * j, moves + 2});
            s.insert(x * j);
          }
        }
      }
    }

    if (ans == INT_MAX) {
      cout << "Case #" << p << ": Impossible" << endl;
    } else {
      cout << "Case #" << p << ": " << ans + 1 << endl;
    }
  }

  return 0;
  ;
}