#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pb push_back
#define double long double
#define all(x) (x).begin(), (x).end()
using namespace std;
signed main() {
  // take inputs
  int n, m;
  cin >> n >> m;
  // take array
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  while (m--) {
    int k, y, x;
    cin >> k >> y >> x;
    vector<int> nums;
    int i = 0, curr = 0;
    while (i < k) {
      curr += a[i];
      i++;
    }
    nums.push_back(curr);
    while (i < n) {
      curr += (a[i] - a[i - k]);
      nums.push_back(curr);
      i++;
    }
    vector<int> select;
    for (int b = 30; b >= 0; b--) {
      if ((x >> b) & 1)
        continue;
      for (auto e : nums) {
        if ((e >> b) & 1) {
          select.push_back(e);
        }
      }
      if (select.size() == y) {
        break;
      }
      if (select.size() < y) {
      } else {
        nums = select;
      }
      select.clear();
    }
    for (auto e : select) {
      x = x | e;
    }
    cout << x << endl;
  }
  return 0;
}