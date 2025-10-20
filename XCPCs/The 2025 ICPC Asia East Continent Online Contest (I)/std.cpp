#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

void chmin(ll& x, const ll y) {
    if (x > y) {
        x = y;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, V, s;
    cin >> n >> m >> V >> s;
    s--;

    vector<vector<pair<int, int>>> adj(n);
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({ w, y });
        adj[y].push_back({ w, x });
    }

    vector<int> vis(n);

    vector<ll> dis(n, inf);
    dis[s] = 0;

    priority_queue<pair<ll, int>> Q;
    Q.push({ 0, s });

    while (!Q.empty()) {
        auto [_, x] = Q.top();
        Q.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (auto [w, y] : adj[x]) {
            ll q = dis[x] / V, r = dis[x] % V;
            r += w;
            if (r > V) {
                q++;
                r = w;
            }
            ll ndis = q * V + r;
            if (dis[y] > ndis) {
                dis[y] = ndis;
                Q.push({ -dis[y], y });
            }
        }
    }

    for (int x = 0; x < n; x++) {
        if (dis[x] == inf) {
            cout << -1 << " ";
            continue;
        }
        ll q = dis[x] / V, r = dis[x] % V;
        if (r) {
            q++;
        }
        q = max(1LL, q);
        cout << q << " ";
    }
    cout << endl;

    return 0;
}