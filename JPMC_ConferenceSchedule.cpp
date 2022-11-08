#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {

  int n;
  cin >> n;

  vector<int> start;
  vector<int> finish;

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    start.push_back(temp);
  }

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    finish.push_back(temp);
  }

  vector<vector<int>> meets;

  for (int i = 0; i < n; ++i) {
    meets.push_back({start[i], finish[i]});
  }

  sort(begin(meets), end(meets),
       [](vector<int> &a, vector<int> &b) { return (a[1] < b[1]); });

  int total = 0, cur = 0;

  for (int i = 0; i < n; ++i) {
    if (cur < meets[i][0]) {
      total++;
      cur = meets[i][1];
    }
  }

  cout << total << endl;

  return 0;
}