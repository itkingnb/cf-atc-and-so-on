#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#define ll long long
using namespace std;
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
    int x,y,k;
    cin>>x>>y>>k;
    //int n=log(x)/log(y);
    //vector<int>a(n+1,0);
    //for(int j=0;j<n+1;j++){
        //a[j]=pow(y,j+1);
    //}
    while(x>=y&&k>0){
        int mod=x%y;
        int min1=min(k,y-mod);
        k-=min1;
        x+=min1;
        while (x%y==0)
        {
            x/=y;
        }
    }
    if(x<y)
    cout<<1+(k-1+x)%(y-1);
    else
    cout<<x;    
    
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
    return 0;
}