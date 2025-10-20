#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"yes"<<'\n';
}
void no(){
    cout<<"no"<<'\n';
}
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void AUTO_AC_MACHINE(){
    int n;
    cin>>n;
    int mx=0;
    int mn=1e9;
    vector<vector<int>>a(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        mx=max(mx,k);
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
            if(j==0){
                mn=min(mn,a[i][j]);
            }
        }
    }
    cout<<mn<<" ";
    DSU dsu(n+1);
    // int now=0;
    // vector<int>vis(n);
    bool ok=0;
    for(int i=2;i<=mx;i++){
        int ans=1e9;
        int ans2=1e9;
        for(int j=0;j<n;j++){
            if(a[j].size()>=i){
                ans2=min(ans2,a[j][i-1]);
                if(a[j][i-2]==mn){
                    ans=min(ans,a[j][i-1]);
                }
            }else{
                if(j==dsu.find(j)){
                    dsu.merge(j+1,j);
                }
                j=dsu.find(j)-1;
            }
            // if(a[j].size()>=i-1)
        }
        if(ans!=(int)1e9){
            cout<<ans<<" ";
            mn=ans;
        }else{
            cout<<ans2<<" ";
            mn=ans2;
        }
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
