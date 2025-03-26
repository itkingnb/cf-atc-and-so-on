#include<bits/stdc++.h>
using  namespace std;
#define ll long long
ll mid;
bool cmp(pair<ll,ll>aa){
    return mid<=aa.second;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>a(n);
    vector<ll>tb(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].first=-a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
        tb[i]=a[i].second;
    }
    sort(tb.begin(),tb.end());
    sort(a.begin(),a.end(),[](pair<ll,ll>aa,pair<ll,ll>b){
        if(aa.first==b.first){
            return aa.second<b.second;
        }
        return aa.first<b.first;
    });
    auto check=[&](ll lo,ll hi)->ll{
        mid=(lo+hi)>>1;
        int pos=upper_bound(a.begin(),a.end(),make_pair(-mid,3000000000))-a.begin();
        ll ans=pos*mid;
        int kk=count_if(a.begin()+pos,a.end(),cmp);
        if(kk>k){
            return 0;
        }
        ans+=kk*mid;
        return ans;
    };
    ll lo=0,hi=3e9;
    ll ans=0;
    while(lo<hi){
        ll temp=check(lo,hi);
        if(temp==0){
            hi=((lo+hi)>>1)-1;
            continue;
        }
        if(temp>ans){
            lo=((lo+hi)>>1)+1;
            ans=temp;
        }else{
            hi=((lo+hi)>>1)-1;
        }
    }
    if(check(lo,lo)){
        ans=max(check(lo,lo),ans);
    }
    if(check(hi,hi)){
        ans=max(check(hi,hi),ans);
    }
    cout<<max(ans,tb[n-k]*(k));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}