#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
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
int solve(){
    int a[200010]={0},n,ans=0,max,qzh=0;
    long long b[200010]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0)
        b[i]+=a[i];
        else
        b[i]+=(a[i]+b[i-1]);
    }
    if(a[0]==0)
    ans++;
    max=a[0];
    for(int i=1;i<n;i++){
    if(a[i]>max)
    max=a[i];
    if(b[i]-max==max){
        ans++;
    }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
    return 0;
}