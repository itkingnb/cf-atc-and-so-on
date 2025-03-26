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
ll zuida(ll n){
    ll zuidashu=0;
    while(n>0){
    zuidashu+=n;
    n-=2;
    }
    return 2*zuidashu;

}
void solve(){
    ll n,k;
    int shulie[200001]={0};
    cin>>n>>k;
    ll a=n;
    ll max=0;
    int j=1;
    if(k%2!=0){
        no();
        return ;
    }
    max=zuida(n-1);                 //n-1
    if(max<k){
        no();
        return;
    }
    for(int i=1;i<=n;i++){
        shulie[i]=i;
    }
    yes();
    cout<<'\n';
    do{
        ll m=k/2;
        if(m>n-1){
            swap(shulie[j],shulie[a+1-j]);
            j++;
            k-=(n-1)*2;
            n-=2;
        }
        else{
            swap(shulie[j],shulie[j+m]);
            break;
        }
    }while(1);
    for(int i=1;i<=a;i++){
        cout<<shulie[i]<<" ";
    }
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