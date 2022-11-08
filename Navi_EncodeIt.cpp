#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
  unordered_map<char, char> m;
  char chr = 'A';
  for (auto c : s) {
    if (m.find(c) == m.end()) {
      m[c] = chr;
      chr++;
    }
  }
  string res = "";
  for (auto c : s) {
    res += (m[c]);
  }
  return res;
}

int main() {

  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  cout << solve(s) << "\n";
  return 0;
}