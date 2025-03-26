#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
struct p {double x,y;};
int n;
bool cmp(p a,p b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
double cross(p a,p b,p c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double dis(p a,p b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Andrew(vector<p> ps){
    double ans=0;
    vector<p>anss(N);
    int top=0;
    for(int i=0;i<n;i++){
        while(top>1&&cross(anss[top-1],anss[top],ps[i])<=0)
            top--;
        anss[++top]=ps[i];
    }
    int k=top;
    for(int i=n-2;i>=0;i--){
        while(top>k&&cross(anss[top-1],anss[top],ps[i])<=0)
            top--;
        anss[++top]=ps[i];
    }
    for(int i=1;i<top;i++){
        ans+=dis(anss[i],anss[i+1]);
    }
    return ans;
}
void solve(){
    cin>>n;
    vector<p>ps(n);
    for(int i=0;i<n;i++){
        cin>>ps[i].x>>ps[i].y;
    }
    sort(ps.begin(),ps.end(),cmp);
    cout<<fixed<<setprecision(2)<<Andrew(ps);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}