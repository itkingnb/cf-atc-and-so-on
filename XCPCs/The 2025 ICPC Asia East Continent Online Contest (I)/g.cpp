#include<bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int>f,siz;
    DSU(){}
    DSU(int n){
        init(n);
    }
    void init(int n){
        f.resize(n);
        iota(f.begin(),f.end(),0);
        siz.assign(n,1);
    }
    int find(int x){
        while(x!=f[x]){
            x=f[x]=f[f[x]];
        }
        return x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    bool merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return false;
        }
        siz[x]+=siz[y];
        f[y]=x;
        return true;
    }
    int size(int x){
        return siz[find(x)];
    }
};


void solve(){
    int n,m;
    cin>>n>>m;
    // DSU dsu(n);
    vector<bool>vis(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(a==b-1){
            vis[a]=1;
        }
        // dsu.merge(a,b);
    }
    for(int i=0;i<n-1;i++){
        if(!vis[i]){
            cout<<"No";
            return ;
        }
    }
    cout<<"Yes";
    // (dsu.size(0)==n?cout<<"Yes":cout<<"No");
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}