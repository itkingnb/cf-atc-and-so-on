#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int INF = 3e18;
const ld EXP = 1e-14;
const int BOD = 1e9;

struct node{
    int a, b;
};

void solve() {
    int n; cin>>n;
    vector<node> l(n+1);
    vector<int> c(n+1);
    for(int i=1; i<=n; i++) {
        ld x; cin>>x;
        l[i].a = x;
    }
    for(int i=1; i<=n; i++) {
        ld x; cin>>x;
        l[i].b = x;
    }
    for(int i=1; i<=n; i++) cin>>c[i];
    sort(c.begin()+1, c.end());
    auto judge = [&](int mid) -> bool{
        int num = 0;
        vector<int> lt, rt;
        for(int i=1; i<=n; i++) {
            if(l[i].a == 0) {
                num += (l[i].b >= mid);
                continue;
            }
            ld b = l[i].b, a = l[i].a;
            ld poi = - (b - mid) / a;
            if(l[i].a > 0) {
                int pos = ceil(poi);
                if(pos <= BOD)  rt.push_back(pos);
            } else {
                int pos = floor(poi);
                if(pos >= -BOD) lt.push_back(pos);
            }
        }
        sort(lt.begin(), lt.end());
        // for(auto &i : lt) cout<<i<<" ";
        // cout<<"\n";
        sort(rt.rbegin(), rt.rend());
        // for(auto &i : rt) cout<<i<<" ";
        // cout<<"\n";
        int lidx = 1, ridx = n;
        vector<bool> vis(n+1);
        for(auto &i : lt) {
            if(lidx <= n && c[lidx] <= i) {
                vis[lidx] = 1;
                lidx += 1;
                num += 1;
            } 
        }
        for(auto &i : rt) {
            while(ridx >= 1 && vis[ridx]) ridx -= 1;
            if(ridx >= 1 && c[ridx] >= i && !vis[ridx]) {
                ridx -= 1;
                num += 1;
            }
        }
        return num >= ((n+1)/2);
    };
    int lt = -INF, rt = INF, res;
    judge(9);
    while(lt <= rt) {
        int mid = (lt + rt) / 2;
        if(judge(mid)) res = mid, lt = mid+1;
        else rt = mid - 1;
        // cout<<mid<<"\n";
    }
    cout<<res<<"\n";
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin>>T;
    for(int i=1; i<=T; i++) solve();
    return 0;
}