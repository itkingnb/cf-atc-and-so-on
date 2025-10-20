#include <bits/stdc++.h>
#define ll long long
const double PI = acos(-1);
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll sum = 0;
    int f = 0;
    vector <ll> b;
    b.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (i != n && a[i] == a[i + 1]) {
            sum += 2 * a[i];
            // cout << a[i] << endl;
            i++;
            f++;
            continue;
        }
        b.push_back(a[i]);
    }
    ll ans = 0;
    if (f >= 2) {
        ans = sum;
    }
    if (sum == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 0, j = 0; i < b.size() - 1; i++) {
        while (j + 1 < b.size() && b[i] + sum > b[j + 1]) {
            j++;
        }
        // cout << b[i] << " " << b[j] << " " << sum << endl;
        if (i < j) {
            ans = max(ans, sum + b[i] + b[j]);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        // cout << endl;
    }
}