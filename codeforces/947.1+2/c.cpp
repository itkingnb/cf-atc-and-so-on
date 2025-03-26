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
    int n;
    cin>>n;
    int flag=0;
    int j=0;
    int mx=0;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==2){
        cout<<min(a[0],a[1]);
        return ;
    }
    vector<int>b(3,0);
    for(int i=2;i<n;i++){
        b[0]=a[i-2];
        b[1]=a[i-1];
        b[2]=a[i];
        sort(b.begin(),b.end());
        mx=max(mx,b[1]);
    }
    cout<<mx;
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