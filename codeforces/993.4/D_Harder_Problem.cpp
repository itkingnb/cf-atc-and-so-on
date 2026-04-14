#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans(n);
    // vector<int>t;
    priority_queue<int,vector<int>,greater<int>>t;
    vector<int>cnt(n+1);
    int mx=1;
    cnt[a[0]]++;
    ans[0]=a[0];
    for(int i=1;i<n;i++){
        t.push(i);
        while(t.size()&&cnt[a[i]]<mx){
            ans[t.top()]=a[i];
            cnt[a[i]]++;
            mx=max(mx,cnt[a[i]]);
            t.pop();
        }
    }
    vector<int>t2;
    for(int i=1;i<=n;i++){
        if(!cnt[i]){
            t2.push_back(i);
        }
    }
    while(t.size()){
        ans[t.top()]=t2.back();
        t.pop();
        t2.pop_back();
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}