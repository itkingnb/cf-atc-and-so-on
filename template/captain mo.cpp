#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sqrtn sqrt(n)
int n,m,k;
ll c[50010],a[50010];
ll sum;
struct Q{
    int l,r;
    int id;
};
bool cmp(Q a,Q b){
    if(a.l/sqrtn!=b.l/sqrtn)
        return a.l<b.l;
    return a.r<b.r;
}
void add(ll x){
    sum-=c[x]*c[x];;
    c[x]++;
    sum+=c[x]*c[x];
}
void sub(ll x){
    sum-=c[x]*c[x];;
    c[x]--;
    sum+=c[x]*c[x];
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<Q>question(m);
    vector<ll>ans(m);
    for(int i=0;i<m;i++){
        cin>>question[i].l>>question[i].r;
        question[i].id=i;
    }
    sort(question.begin(),question.end(),cmp);
    for(int i=0,l=1,r=0;i<m;i++){
        while(question[i].l<l) add(a[--l]);
        while(question[i].r>r) add(a[++r]);
        while(question[i].l>l) sub(a[l++]);
        while(question[i].r<r) sub(a[r--]);
        ans[question[i].id]=sum;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}