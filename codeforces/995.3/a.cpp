    #include<bits/stdc++.h>
using  namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>b[i+1]){
            ans+=a[i]-b[i+1];
        }
    }
    cout<<ans+a[n-1];
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