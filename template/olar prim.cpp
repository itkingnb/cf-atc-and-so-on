#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000001
vector<ll>prim;
int ok[N];
void get_prim(){
    for(ll i=2;i<N;i++){
        if(!ok[i])
        prim.push_back(i);
        for(int j=0;j<prim.size();j++){
            if(i*prim[j]<N)
            ok[i*prim[j]]=true;
            else
            break;
            if(i%prim[j]==0)
            break;
        }
    }
}
void solve(){
    cout<<prim[123455];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    get_prim();
    solve();
    return 0;
}