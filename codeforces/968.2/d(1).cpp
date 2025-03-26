#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define pii pair<int, int>
#define mii map<int, int>
#define msi map<string, int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;        // 2147483647
int minint = INT_MIN;        // -2147483648
long long maxll = LLONG_MAX; // 9223372036854775807
long long minll = LLONG_MIN; // -9223372036854775808
ll jc(ll n) {
    if (n == 1 || n == 0)
        return (ll)1;
    else
        return n * jc(n - 1);
}
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
ll qpow(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<int> len(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i];
        a[i].resize(len[i]);
        for (int j = 0; j < len[i]; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
        int target = 0, cnt = 0, jj = 0;
        for (int j = 0; j < len[i]; j++) {
            if (a[i][j] > target) {
                cnt++;
                if (cnt == 1) {
                    mx = max(mx, target);
                    jj = target++;
                    j--;
                } else {
                    mp[jj] = max(target, mp[jj]);
                    mx = max(target, mx);
                    break;
                }
            } else if (a[i][j] == target)
                target++;
        }
        if (cnt == 1) {
            mp[jj] = max(target, mp[jj]);
            mx = max(target, mx);
        }
        if (cnt == 0) {
            mp[target - 1] = max(mp[target - 1], target);
            mx = max(mx, target);
            if (a[i][len[i] - 1] == (target - 1)) {
                mp[target] = target + 1;
                mx = max(target, mx);
            }
        }
    }
    for (int i = 0; i <= min(m, mx); i++) {
        ans += max({mp[i], mx, i, mp[mx]});
    }
    ans += (ll)(m + min(m, mx) + 1) * (m - min(m, mx)) / 2;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        cout << '\n';
    }
    return 0;
}