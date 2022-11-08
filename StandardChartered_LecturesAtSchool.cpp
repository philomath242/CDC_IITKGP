#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m, k;
int dp[210][210];
int t[210][210];
vector<string> arr;
void init() {
  for (int i = 0; i < n; i++) {
    vector<int> pos;
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '1') {
        pos.push_back(j);
      }
    }
    // pr(pos);
    for (int x = 0; x <= k; x++) {
      int p = pos.size();
      if (x >= p) {
        t[i][x] = 0;
        continue;
      }
      t[i][x] = 1e9;
      for (int j = 0; j < p; j++) {
        int left = x - j;
        if (j > x)
          break;
        int right = p - 1 - left;
        t[i][x] = min(t[i][x], pos[right] - pos[j] + 1);
      }
      // pr(t[i][x]);
    }
  }
}
int rec(int d, int kleft) {
  if (d == n)
    return 0;
  if (dp[d][kleft] != -1)
    return dp[d][kleft];
  int ans = 1e9;
  for (int x = 0; x <= kleft; x++) {
    ans = min(ans, rec(d + 1, kleft - x) + t[d][x]);
  }
  // pr(t[0][0],t[0][1]);
  // pr(ans,d,kleft);
  return dp[d][kleft] = ans;
}

void solve() {
  cin >> n >> m >> k;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  init();
  memset(dp, -1, sizeof(dp));
  cout << rec(0, k) << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}