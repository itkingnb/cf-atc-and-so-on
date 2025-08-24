#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int z[100001], fz[1000001] = {0}, cnt = 0;
void solve()
{
    ll n, h;
    cin >> n;
    h = n;
    priority_queue <int> q;
    for (int i = 1; i <= cnt; i++) {
        ll x = z[i];
        while (h % x == 0) {
            q.push(x);
            h /= x;
        }
    }
    h = n;
    int sum = 0;
    vector <ll> ans;
    while (!q.empty()) {
        // priority_queue <int> q2 = q;
        // while (!q2.empty()) {
        //     cout << q2.top() << " ";
        //     q2.pop();
        // }
        // cout << endl;
        ll y = q.top();
        if (y == 2) {
            break;
        }
        q.pop();
        ll x = h / y;
        h += x;
        int p = (y + 1);
        while (p % 2 == 0) {
            q.push(2);
            p /= 2;
        }
        if (p != 1) {
            q.push(p);
        }
        // cout << x << " " << h << endl;
        ans.push_back(x);
        sum++;
    }
    // cout << q.size() << endl;
    if (q.size() % 2 == 1) {
        ans.push_back(h);
        sum++;
    }
    cout << sum << '\n';
    for (int i = 0; i < sum; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    // cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fz[1] = 1;
    for (int i = 1; i <= 1e6; i++) {
        if (fz[i] == 0) {
            z[++cnt] = i;
            // cout << cnt << " " << i << endl;
        }
        for (int j = 1; j <= cnt && i * z[j] <= 1e6; j++) {
            fz[i * z[j]] = 1;
        }
    }
    // cout << cnt << endl;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}