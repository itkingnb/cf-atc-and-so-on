#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int,int>
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    vector<int>k(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        a[i]-=i;
        b[i]=i-b[i];
        k[i]=i;
    }
    auto cmp=[&](int x,int y)->bool{
        return a[x]==a[y]?x<y:a[x]<a[y];
    };
    sort(k.begin(),k.end(),cmp);
    vector<int>stk(n);
    stk[0]=k[0];
    for(int i=1;i<n;i++){
        if(k[i]>)
    }

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