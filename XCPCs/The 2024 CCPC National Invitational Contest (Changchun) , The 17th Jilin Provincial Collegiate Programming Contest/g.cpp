#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int,int>
void solve(){
    int n;
    cin>>n;
    map<int,vector<pii>>mp;
    vector<int>yy(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r>>yy[i];
        mp[yy[i]].push_back({l,r});
    }
    int x,y;
    cin>>x>>y;
    sort(yy.begin(),yy.end(),greater<int>());
    int i=0;
    while(i<n){
        if(y<yy[i]){
            i++;
            continue;
        }
        y=yy[i]-1;
        sort(mp[yy[i]].begin(),mp[yy[i]].end());
        // int idx=upper_bound(mp[yy[i]].begin(),mp[yy[i]].end())
        for(auto lr:mp[yy[i]]){
            if(lr.first<x&&x<=lr.second){
                x=lr.second;
                break;
            }
        }
    }
    cout<<x;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}