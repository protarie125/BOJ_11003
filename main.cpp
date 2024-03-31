#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n, l;
vl A;
deque<pll> Q;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> l;

  A = vl(n);
  for (auto&& x : A) {
    cin >> x;
  }

  for (auto i = 1; i <= n; ++i) {
    if (!Q.empty()) {
      if (Q.front().second < i - l + 1) {
        Q.pop_front();
      }
    }

    while (!Q.empty() && A[i - 1] < Q.back().first) {
      Q.pop_back();
    }

    Q.push_back({A[i - 1], i});
    cout << Q.front().first << ' ';
  }

  return 0;
}