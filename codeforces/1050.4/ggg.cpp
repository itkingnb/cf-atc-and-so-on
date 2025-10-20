#include "bits/stdc++.h"

using namespace std;
using i64 = int64_t;

constexpr int N = 2E5;
vector<vector<int>> divi;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n + 1);
    int g = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto d : divi[a[i]]) {
            cnt[d]++;
            if (cnt[d] != i + 1) {
                ans = max(ans, cnt[d]);
            }
        }
        if (gcd(a[i], g) != g) {
            ans = max(ans, cnt[g]);
        }
        g = gcd(a[i], g);
	cout << ans << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    divi.assign(N + 1, {});
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divi[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}