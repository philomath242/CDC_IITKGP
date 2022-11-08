#include <bits/stdc++.h>
using namespace std;

int dp[1100][110];

int solve(int i, int k, vector<int> &prices) {
  if (k <= 0)
    return 0;
  if (i <= 0)
    return 0;
  // if already present return `dp[i][j]`
  if (dp[i][k] != -1)
    return dp[i][k];

  // if we don't trade even after `i`
  int profit = solve(i - 1, k, prices);
  // if traded then
  for (int j = i - 1; j >= 0; j--) {
    if (prices[j] < prices[i]) {
      profit = max(profit, solve(j - 1, k - 1, prices) + prices[i] - prices[j]);
    }
  }
  dp[i][k] = profit;
  return profit;
}

int maxProfit(int k, vector<int> &prices) {
  memset(dp, -1, sizeof(dp));
  int n = prices.size();
  if (k > prices.size())
    return solve(n - 1, n, prices);
  return solve(n - 1, k, prices);
}

int main() {

  cin.tie(0);
  cout.tie(0);
  int ans;
  vector<int> input = {3, 2, 6, 5, 0, 3};
  int k = 2;
  cout << maxProfit(k, input) << "\n";
  return 0;
  input = {2, 4, 1};
  k = 2;
  ans = maxProfit(k, input);

  cout << (ans == 0 ? -1 : ans) << "\n";

  return 0;
}