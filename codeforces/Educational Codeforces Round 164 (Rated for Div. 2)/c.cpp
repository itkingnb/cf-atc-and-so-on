#include<bits/stdc++.h>
using namespace std;
#define ll long long

int jc(int n){
    if(n==1||n==0)
    return 1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void solve(){
    string x,y;
    cin>>x>>y;
    int flag=0;
    for(int i=0;i<x.size();i++){
        if(flag&&x[i]>y[i]){
            swap(x[i],y[i]);
            continue;
        }
        if(x[i]>y[i])
        flag=1;  
        if(x[i]<y[i]&&flag==0){
        swap(x[i],y[i]);
        flag=1;
        }
    }
    cout<<x<<"\n"<<y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }

}