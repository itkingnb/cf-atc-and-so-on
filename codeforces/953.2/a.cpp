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
    int n;
    vector<int> a;
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    sort(a.begin(),a.end()-1);
    cout<<a[n-1]+a[n-2];
    return 0;
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