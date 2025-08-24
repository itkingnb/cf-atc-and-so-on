#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
ll c[]={1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489, 3486784401, 31381059609, 282429536481, 2541865828329, 22876792454961, 205891132094649, 1853020188851841, 16677181699666569, 150094635296999121};
void solve(){
    ll n,x;
    cin>>n>>x;
    ll d=0;
    ll ans=0;
    while(n){
        int nn=n%10;
        n/=10;
        if(nn<x){
            ans+=nn*c[d];
        }else{
            ans+=(nn-1)*c[d];
        }
        d++;
    }
    cout<<ans+1;
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