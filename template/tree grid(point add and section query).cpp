#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,s[500005];
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    while (x<=n){
        s[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=s[x];
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(i,x);
    }
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int x,k;  cin>>x>>k;  add(x,k);
        }else{
            int l,r;  cin>>l>>r;
            cout<<query(r)-query(l-1)<<'\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}