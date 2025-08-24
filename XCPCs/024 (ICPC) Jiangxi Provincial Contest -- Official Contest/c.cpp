#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, s;
    cin >> n >> s;
    int sum = 0;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == s) {
        cout << n << '\n';
    }
    else {
        cout << n - 1 << '\n';
    }
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