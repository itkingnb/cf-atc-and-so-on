#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    if(a.first.second==b.first.second)
        return a.first.first>b.first.first;
    return a.first.second<b.first.second;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>>b(n);
    vector<int>ans(n);
    bool ok=true;
    for(int i=0;i<n;i++){
        cin>>b[i].first.first>>b[i].first.second;
        b[i].second=i;
    }
    sort(b.begin(),b.end(),cmp);
    int mx=1e6;
    if(b[0].first.second!=0)
        ok=false;
    else
        ans[b[0].second]=mx;
    map<int,int>mp;
    mp[0]=b[0].first.first;
    for(int i=1;i<n;i++){
        if(b[i].first.first==b[i-1].first.first&&b[i].first.second==b[i-1].first.second||b[i].first.second-b[i-1].first.second>1||!ok){
            ok=false;
            break;
        }else if(b[i].first.second==b[i-1].first.second){
            ans[b[i].second]=ans[b[i-1].second]-1;
        }else if(b[i].first.first<mp[b[i].first.second-1]){
            ok=false;
            break;
        }else{
            if(mp[b[i].first.second-1]==b[i].first.first){
                ans[b[i].second]=mx-1;
            }else{
                ans[b[i].second]=mx;
            }
            mp[b[i].first.second]=b[i].first.first;
        }
        if(ans[b[i].second]<b[i].first.first){
            ok=false;
            break;
        }
    }
    if(ok){
        for(int i=0;i<n;i++)
            cout<<ans[i]<<'\n';
    }else
        cout<<-1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}