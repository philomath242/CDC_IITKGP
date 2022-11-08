#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
  // take inputs
  string s;
  cin >> s;
  int n = s.size();
  // sort the string for better computation
  sort(s.begin(), s.end());
  set<int> str;
  // this will store the frequency of letters
  // added extra element for ease of traversal
  int fq[27] = {0};
  // update the frequency
  for (auto i : s) {
    fq[i - 'A']++;
    str.insert(i);
  }
  // store max frequency element
  auto it = max_element(fq, fq + 27);
  //
  if (2 * *it - n > 1)
    return cout << -1, 0;

  string ans;
  char prev = 26 + 'A';
  while (2 * *it - n < 1) {
    char x = *str.begin();
    str.erase(x);
    ans += x;
    fq[x - 'A']--;
    if (fq[prev - 'A'])
      str.insert(prev);
    prev = x;
    it = max_element(fq, fq + 27);
    n--;
  }
  if (*it) {
    string aux;
    char x = it - fq + 'A';
    for (int i = 0; i < 26; i++)
      if (x - 'A' != i)
        for (int j = 0; j < fq[i]; j++)
          aux += i + 'A';
    ans += x;
    for (auto i : aux)
      ans += i, ans += x;
  }
  cout << ans;
}