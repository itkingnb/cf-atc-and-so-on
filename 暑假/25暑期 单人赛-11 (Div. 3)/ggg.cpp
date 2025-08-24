#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tii tuple<int, int, int>
#define tll tuple<ll, ll, ll>
using namespace std;
constexpr int N = 2e5 + 5;

template <typename T>
struct Fenwick
{
    int n;
    vector <T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x, const T &v)
    {
        while (x <= n) {
            a[x] += v;
            x += lowbit(x);
        }
    }

    T sum(int x)
    {
        T ans{};
        while (x >= 1) {
            ans += a[x];
            x -= lowbit(x);
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<int> p(n + 1);
    Fenwick<ll> fen(n);
    for (int i = n; i >= 1; i--) {
        auto check = [&] (int x) {
            return 1LL * (x + 1) * x / 2 - fen.sum(x) > s[i];
        };
        int l = 1, r = n, mid, ans = 1;
        while (l <= r) {
            mid = l + r >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        p[i] = ans;
        fen.add(p[i], p[i]);
        // fen.add(p[i] - 1, 1 - p[i]);
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}