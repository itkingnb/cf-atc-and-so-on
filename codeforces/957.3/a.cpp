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
    int a,b,c;
    cin>>a>>b>>c;
    int t=5,k;
    int sum=a*b*c;
    while (t>0)
    {
        k=max({a*b,b*c,a*c});
        sum+=k;
        if(k==a*b)
        c++;
        else{
            if(k==b*c)
            a++;
            else
            b++;
        }
        t--;
    }
    cout<<sum;
    
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