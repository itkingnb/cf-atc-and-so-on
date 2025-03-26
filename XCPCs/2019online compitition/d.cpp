#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 50010
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int>>adj[n+1];
    priority_queue<pair<ll,int>>qq;
    map<int,ll>mp;
    vector<int>qs;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        qq.push({-c,b});
    }
    int cnt=0,maxq=0;
    for(int i=0;i<q;i++){
        int query;
        cin>>query;
        maxq=max(maxq,query);
        mp[query]=-1;
        qs.push_back(query);
    }
    while(cnt!=maxq){
        auto u=qq.top();
        qq.pop();
        for(auto x:adj[u.second])
        qq.push({-(-u.first+x.first),x.second});
        cnt++;
        if(mp[cnt]==-1)
        {
            mp[cnt]=-u.first;
        }
    }
    for(int i=0;i<q;i++){
        cout<<mp[qs[i]]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
    solve(); 
    }
    return 0;
}