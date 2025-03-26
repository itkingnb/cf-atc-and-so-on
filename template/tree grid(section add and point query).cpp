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
    int last=0;
    for(int i=1;i<=n;i++){
        int a; cin>>a; add(i,a-last); last=a;
    }
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,k; cin>>l>>r>>k; add(l,k); add(r+1,-k);
        }else{
            int x; cin>>x; cout<<query(x)<<'\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}