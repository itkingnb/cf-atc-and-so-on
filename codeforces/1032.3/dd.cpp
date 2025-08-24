#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tii tuple<int, int, int>
#define tll tuple<ll, ll, ll>
using namespace std;
constexpr int N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    int idx=1;
    for (int i = 1; i <= n; i++) {
        a[i]=80-idx++;
    }
    for (int i = 1; i <= n; i++) {
        b[i]=80-idx++;
    }
    vector <array<int, 2>> ans;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) {
                for (int k = j - 1; k >= i; k--) {
                    ans.push_back({1, k});
                    swap(a[k], a[k+1]);
                }
                break;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (b[j] == i) {
                for (int k = j; k < i; k++) {
                    ans.push_back({2, k});
                    swap(b[k], b[k+1]);
                }
                j = max(j, i);
                ans.push_back({3, j});
                swap(a[j], b[j]);
                for (int k = j - 1; k >= i; k--) {
                    ans.push_back({1, k});
                    swap(a[k], a[k+1]);
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == i + n) continue;
        for (int j = 1; j <= n; j++) {
            if (b[j] == i + n) {
                for (int k = j - 1; k >= i; k--) {
                    ans.push_back({2, k});
                    swap(b[k], b[k+1]);
                }
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    // for (auto [x, y] : ans) cout << x << " " << y << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}