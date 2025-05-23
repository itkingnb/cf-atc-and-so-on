#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
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
    int n;
    ll max=0;
    ll sum=0;
    cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==1){
        cout<<0;
        return;
    }
    /*if(n==2){
        if(a[0]<=a[1]){
        cout<<0;
        return;
        }
        else{
        cout<<a[1]-a[0]+1;
        return;
        }
    }*/
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            int d=a[i-1]-a[i];
            a[i]=a[i-1];
            sum+=d;
            if(d>max)
            max=d;
        }
    }
    cout<<sum+max;
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