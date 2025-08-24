#include<bits/stdc++.h>
long long mod = 998244353;
using namespace std;
void solve()
{
    int m;
    cin >> m;
    long long ans = 1;
    for (int i = 1; i <= m - 1; i++) {
        ans = (ans * 2) % mod;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}