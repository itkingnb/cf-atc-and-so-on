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
    cin>>n;
    int x,y;
    int a=0,b=0;
    int k=0;
    int a1[200010]={0},b1[200010]={0};
    for(int i=0;i<n;i++)
    cin>>a1[i];
    for(int i=0;i<n;i++)
    cin>>b1[i];
    for(int i=0;i<n;i++){
        x=a1[i],y=b1[i];
        if(x>y){
        a+=x;
        continue;
        }
        if(x<y){
        b+=y;
        continue;
        }
        if(x==y){
            if(x==1)
            k++;
            if(x==-1){
            k++;
            a--;
            b--;
            }
        }
    }
    cout<<min({(a+b+k)>>1,a+k,b+k});
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