#include <bits/stdc++.h>
using namespace std;

int arithmeticSubarrays(vector<int> &a, int n) {
  vector<int> vec;
  for (int i = 1; i < n; i++) {
    vec.push_back(a[i] - a[i - 1]);
  }
  vector<int> arr;
  int sz = vec.size();
  for (int i = 0; i < sz; i++) {
    int j = i;
    while (j < sz && vec[i] == vec[j]) {
      j++;
    }
    arr.push_back(j - i + 1);
    i = j - 1;
  }
  int ans = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] >= 3) {
      int c = arr[i] - 2;
      ans += c * (c + 1) / 2;
    }
  }
  return ans;
}