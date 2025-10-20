#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"YES";
}
void no(){
    cout<<"NO";
}
void AUTO_AC_MACHINE(){
    int n,m;
    cin>>n>>m;
    vector<array<int,2>>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1];
    }
    vector<int>ans(n);
    int l=0,r=n-1;
    int idx=0;
    while ((l<r)){
        ans[l++]=idx++;
        ans[r--]=idx++;
    }
    if(l==r){
        ans[l]=idx;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
        cout<<'\n';
    }
}
