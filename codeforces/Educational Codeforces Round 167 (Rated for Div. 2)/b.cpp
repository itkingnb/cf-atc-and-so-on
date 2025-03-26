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
    string a,b;
    cin>>a>>b;
    int length=0;
    int max=0;
    for(int i=0;i<b.size();i++){
        int k=i;
        length=0;
        for(int j=0;j<a.size();j++){
            if(k<b.size()&&b[k]==a[j]){
            k++;
            length++;
            }
        }
        if(length>max)
        max=length;
    }
    cout<<a.size()+b.size()-max;
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