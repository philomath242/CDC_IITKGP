#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {2, 4, 8, 6};
  int x = 2;
  int n = v.size();
  vector<int> ans(n);
  set<pair<int, int>> s1, s2;

  for (int i = 0; i < n; i++) {
    while (s2.size() && (*s2.begin()).first + x <= v[i]) {
      ans[(*s2.begin()).second] = v[i];
      s2.erase(s2.begin());
    }
    while (s1.size() && (*s1.begin()).first + x <= v[i]) {
      s2.insert(*s1.begin());
      s1.erase(s1.begin());
    }
    s1.insert({v[i], i});
  }
  while (s2.size()) {
    ans[(*s2.begin()).second] = -1;
    s2.erase(s2.begin());
  }
  while (s1.size()) {
    ans[(*s1.begin()).second] = -1;
    s1.erase(s1.begin());
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}