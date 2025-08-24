#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ull unsigned ll
const ull P=131;
void solve(){
    int n;
    cin>>n;
    vector<string>s(2*n);
    int idx=0;
    for(int i=0;i<n;i++){
        cin>>s[idx]>>s[idx+1];
        idx+=2;
    }
    sort(s.begin(),s.end());
    unordered_map<ull,ll>mp;
    ll ans=0;
    for(int i=0;i<2*n;i+=2){
        ull ha=0;
        for(int j=0;j<s[i].size();j++){
            ha=ha*P+s[i][j];
            mp[ha]++;
        }
    }
    // for(auto [x,y]:mp){
    //     cout<<x<<" "<<y<<endl;
    // }
    for(int i=1;i<2*n;i+=2){
        // cout<<s[i]<<endl;
        ull ha=0;
        for(int j=0;j<s[i].size();j++){
            ha=ha*P+s[i][j];
            ans+=mp[ha];
        }
        // cout<<ans;
    }
    cout<<ans;
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