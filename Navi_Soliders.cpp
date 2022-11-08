#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int solve(vector<int> &positions) {
  int n = positions.size();

  vector<int> diff(n, 0);

  for (int i = 1; i < n; ++i) {
    diff[i] = positions[i] - positions[i - 1];
  }

  sort(begin(diff), end(diff));
  // cout << diff[n - 1] << "\n";
  return ceil(diff[n - 1] / 2.0);
}

int main() {

  cin.tie(0);
  cout.tie(0);

  int n, l;

  cin >> n >> l;

  vector<int> input(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  cout << solve(input) << "\n";
  return 0;
}