#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

namespace rgs = std::ranges;

int query(std::vector<int> s) {
    std::cout << "? " << s.size();
    for (auto x : s) {
        std::cout << " " << x + 1;
    }
    std::cout << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a;
    for (int _ = 0; _ < 3; _++) {
        int lo = 0, hi = a.empty() ? 2 * n : a.back() - 1;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            auto s = a;
            for (int i = 0; i <= m; i++) {
                s.push_back(i);
            }
            if (query(s) % 2 != s.size() % 2) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        a.push_back(lo);
    }
    
    std::cout << "! " << a[2] + 1 << " " << a[1] + 1 << " " << a[0] + 1 << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}