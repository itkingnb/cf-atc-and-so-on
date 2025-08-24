#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector <ll> a(2* n + 1), b(2 * n + 1, 0);
    ll sum = 0, x = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        sum += a[i];
        x += a[i] * (i % 2);
        if (i % 2 == 1) {
            b[i] = -a[i];
        }
        else {
            b[i] = a[i];
        }
    }
    // for (int i = 1; i <= 2 * n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= 2 * n; i++) {
    //     b[i] += b[i - 1];
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    ll y = sum - 2 * x;
    // cout << sum << " " << x << " " << y << endl;
    set <ll> s;
    s.insert(0);
    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        ll r = 2 * a[i];
        ll l = r - y;
        auto it = s.lower_bound(l);
        if (it != s.end()) {
            ll h2 = *it;
            ll g = r - h2;
            ll f = x + g / 2;
            ans = max(ans, min(f, sum - f));
        }
        if (--it != s.begin()) {
            // it--;
            ll h1 = *it;
            ll g = r - h1;
            ll f = x + g / 2;
            ans = max(ans, min(f, sum - f));
        }
        s.insert(2 * a[i]);
    }
    cout << ans << '\n';
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}