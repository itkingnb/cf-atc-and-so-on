#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ex_gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int x1,y1,d;
    d=ex_gcd(b,a%b,x1,y1);
    x=y1; y=x1-a/b*y1;
    return d;
}
void solve(){
    int a,b,c,x,y;
    cin>>a>>b>>c;
    int d=ex_gcd(a,b,x,y);
    if(c%d) puts("none");
    else cout<<c/d*x<<" "<<c/d*y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}