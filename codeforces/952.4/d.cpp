#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
string s[200001];
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
    int n,m,max=0,p=0,ii=0,hang;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#')
            p++;
        }
        if(p>max){
            max=p;
            ii=i;
            p=0;
        }else
        p=0;
    }
    for(int i=0;i<m;i++)
    if(s[ii][i]=='#'){
        hang=i+max/2+1;
        break;
    }
    cout<<ii+1<<" "<<hang;
    return 0;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}