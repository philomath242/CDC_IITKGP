#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void printVector(vector<int> arr) {
  cout << "[ ";
  for (auto x : arr) {
    cout << x << ", ";
  }

  cout << "]\n";
  return;
}

int main() {

  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    arr[i] = temp;
  }

  int x;
  cin >> x;
  int q;
  cin >> q;

  vector<int> queries;

  for (int i = 0; i < q; ++i) {
    int temp;
    // cin >> temp;
    cin >> temp;
    queries.push_back(temp);
  }

  // printVector(queries);

  vector<int> ans;
  ans.push_back(0);
  int count = 0;

  for (int i = 0; i < n; ++i) {
    if (arr[i] == x)
      ans.push_back(i + 1), count++;
  }

  // printVector(ans);

  for (int i = 0; i < q; ++i) {
    if (queries[i] > count) {
      cout << -1 << endl;

    } else {

      cout << ans[queries[i]] << endl;
    }
  }

  return 0;
}