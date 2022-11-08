#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  int dp[105];
  //   dp[0] = 1;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  for (int i = 4; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 3];
  }
  return dp[n];
}

int main() {

  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  int n;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    cout << solve(n) << "\n";
  }

  return 0;
}