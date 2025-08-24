#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<bool>vis(n+1,0);
    vector<int>fa(n+1,0);
    iota(fa.begin(),fa.end(),0);
    auto findfa=[&](auto &&self,int x)->int{
        if(fa[x]==x){
            return x;
        }
        return fa[x]=self(self,fa[x]);
    };
    // if(m==0){
    //     cout<<n-1;
    //     return ;
    // }
    int ans=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vis[u]=1;
        vis[v]=1;
        if(findfa(findfa,u)==findfa(findfa,v)){
            ans++;
        }else{
            fa[findfa(findfa,v)]=findfa(findfa,u);
        }
    }
    set<int>st;
    for(int i=1;i<=n;i++){    
        st.insert(findfa(findfa,i));
    }
    cout<<ans+st.size()-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}