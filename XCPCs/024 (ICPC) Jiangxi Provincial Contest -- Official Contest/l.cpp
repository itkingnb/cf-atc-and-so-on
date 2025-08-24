#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, m ,k ,t;
    cin >> n >> m >> k >> t;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector <int> p(k + 1), l(k + 1), r(k + 1);
    vector <vector <int> > open(t + 1), close(t + 2);
    for (int i = 1; i <= k; i++) {
        cin >> p[i] >> l[i] >> r[i];
        open[l[i]].push_back(i);
        close[r[i] + 1].push_back(i);
    }
    vector <vector <pair<int, int> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v ,w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector <vector <int> > mdis(k + 1,vector <int> (n + 1, 1e9));
    for (int i = 1; i <= k; i++) {
        priority_queue <pair <int, int>, vector <pair<int, int> >, greater <pair <int, int> > > q;
        vector <bool> f(n + 1, 0);
        mdis[i][p[i]] = 0;
        q.push({0, p[i]});
        while (!q.empty()) {
            pair <int, int> h = q.top();
            q.pop();
            int u = h.second;
            if (f[u]) {
                continue;
            }
            f[u] = 1;
            for (auto [v, w] : e[u]) {
                if (mdis[i][u] + w < mdis[i][v]) {
                    mdis[i][v] = mdis[i][u] + w;
                    q.push({mdis[i][v], v});
                }
            }
        }
    }
    ll sum = 0, mod = 998244353;
    vector <priority_queue <pair <int, int>, vector <pair<int, int> >, greater <pair <int, int> > > > q(n + 1);
    vector <bool> f(k + 1, 0);
    int fsum = 0;
    for (int i = 1; i <= t; i++) {
        for (auto x : open[i]) {
            f[x] = 1;
            fsum++;
            for (int j = 1; j <= n; j++) {
                if (!q[j].empty()) {
                    sum -= 1ll * q[j].top().first * a[j];
                }
                q[j].push({mdis[x][j], x});
                while (!q[j].empty() && f[q[j].top().second] == 0) {
                    q[j].pop();
                }
                sum += 1ll * q[j].top().first * a[j];
            }
        }
        for (auto x : close[i]) {
            f[x] = 0;
            fsum--;
            for (int j = 1; j <= n; j++) {
                if (!q[j].empty()) {
                    sum -= 1ll * q[j].top().first * a[j];
                }
                while (!q[j].empty() && f[q[j].top().second] == 0) {
                    q[j].pop();
                }
                if (!q[j].empty()) {
                    sum += 1ll * q[j].top().first * a[j];
                }
            }
        }
        if (fsum == 0) {
            cout << "-1" << '\n';
        }
        else {
            cout << sum << '\n';
        }
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