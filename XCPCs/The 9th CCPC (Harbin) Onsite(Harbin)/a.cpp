#include<bits/stdc++.h>
using namespace std;
#define N 100001
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    string ans;
    double k=0;
    for(int i=0;i<n;i++){
        k=0.5*k+a[i];
        if(k>0)
        ans.push_back('+');
        else if(k==0)
        ans.push_back('0');
        else
        ans.push_back('-');
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }    
    return 0;
}