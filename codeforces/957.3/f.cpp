#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
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
    int n,x;
    int flag=0;
    int ans=0;
    cin>>n>>x;
    vector<int>a(n,0);
    vector<int>b(x+1,0);
    int j=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int m=a[i];
        if(b[a[i]]&&a[i]<=x){
            ans++;
            for(int k=i-1;k>=j;k--){
                b[x/a[k]]=0;
            }
            j=i;
            //cout<<i;
        }
        if(x%a[i]!=0)
        continue;
        else
        b[x/a[i]]++;
    }
    
    cout<<ans+1;
}

signed main(){
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