struct DSU {
    std::vector<std::pair<int &, int>> his;
    
    int n;
    std::vector<int> f, g, bip;
    
    DSU(int n_) : n(n_), f(n, -1), g(n), bip(n, 1) {}
    
    std::pair<int, int> find(int x) {
        if (f[x] < 0) {
            return {x, 0};
        }
        auto [u, v] = find(f[x]);
        return {u, v ^ g[x]};
    }
    
    void set(int &a, int b) {
        his.emplace_back(a, a);
        a = b;
    }
    
    void merge(int a, int b, int &ans) {
        auto [u, xa] = find(a);
        auto [v, xb] = find(b);
        int w = xa ^ xb ^ 1;
        if (u == v) {
            if (bip[u] && w) {
                set(bip[u], 0);
                ans--;
            }
            return;
        }
        if (f[u] > f[v]) {
            std::swap(u, v);
        }
        ans -= bip[u];
        ans -= bip[v];
        set(bip[u], bip[u] && bip[v]);
        set(f[u], f[u] + f[v]);
        set(f[v], u);
        set(g[v], w);
        ans += bip[u];
    }
    
    int timeStamp() {
        return his.size();
    }
    
    void rollback(int t) {
        while (his.size() > t) {
            auto [x, y] = his.back();
            x = y;
            his.pop_back();
        }
    }
};