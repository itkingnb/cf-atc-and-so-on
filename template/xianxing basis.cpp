#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[51];
int n,k;
ll ans;
void gauss(){
    for(int i=55;i>=0;i--){
        for(int j=k;j<n;j++)
            if(a[j]>>i&1) {swap(a[j],a[k]);break;}
        if(!(a[k]>>i&1)) continue;//除去某一位都是0的情况
        for(int j=0;j<n;j++){
            if(j!=k&&(a[j]>>i&1))
            a[j]^=a[k];
        }
        k++;
        if(k==n) break;//满秩
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    gauss();
    for(int i=0;i<k;i++)
    ans^=a[i];
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}