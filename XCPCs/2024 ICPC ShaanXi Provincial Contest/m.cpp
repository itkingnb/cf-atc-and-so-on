#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
void solve(){
    int n;
    cin>>n;
    vector<pii>a(n);
    map<int,vector<int>>mp1,mp2;
    vector<vector<bool>>v(110,vector<bool>(2,0));
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        mp1[a[i].first].push_back(a[i].second);
        mp2[a[i].second].push_back(a[i].first);
    }
    long double ans=0;
    for(int i=1;i<=99;i++){
        for(int j=1;j<=99;j++){
            v[j][0]=v[j][1]=false;
        }
        sort(mp1[i].begin(),mp1[i].end());
        for(int j=0;j<mp1[i].size();j++){
            if(v[mp1[i][j]][0]){
                ans+=0.5;
            }
            if(v[mp1[i][j]][1]){
                ans+=0.5;
            }
            v[mp1[i][j]-1][1]=v[mp1[i][j]+1][0]=v[mp1[i][j]][0]=v[mp1[i][j]][1]=1;
        }
    }
    // cerr<<ans<<'\n';
    for(int i=1;i<=99;i++){
        for(int j=1;j<=99;j++){
            v[j][0]=v[j][1]=false;
        }
        sort(mp2[i].begin(),mp2[i].end());
        for(int j=0;j<mp2[i].size();j++){
            if(v[mp2[i][j]][0]){
                ans+=0.5;
            }
            if(v[mp2[i][j]][1]){
                ans+=0.5;
            }
            v[mp2[i][j]-1][1]=v[mp2[i][j]+1][0]=v[mp2[i][j]][0]=v[mp2[i][j]][1]=1;
        }
    }
    cout<<2*n-ans;
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