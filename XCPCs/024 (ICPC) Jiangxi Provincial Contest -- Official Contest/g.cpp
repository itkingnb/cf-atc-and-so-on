#include<bits/stdc++.h>
#define ll long long
using namespace std;
void yes(){
    cout<<"Yes"<<'\n';
}
void no(){
    cout<<"No"<<'\n';
}
void solve()
{
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        char c;
        cin>>c;
        if(c!='A'){
            sum+=a*(c-'0');
        }
    }
    sum%(ll)5==0?yes():no();
}
int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}