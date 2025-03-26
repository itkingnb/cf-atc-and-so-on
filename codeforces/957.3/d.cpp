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
    int n,m,k,j=0,flag=0,flag1=0;
    int nums=0;
    int danger=0;
    cin>>n>>m>>k;
    string s;
    string b="L";
    cin>>s;
    s=b+s+b;
    int huancun=0;
    //cout<<s;
    for(int i=1;i<s.size();i++){
        if(s[i]=='L'){
        j=i;
        flag=0;
        }
        if(i-j<m&&flag==0)
        continue;
        else{
            flag=1;
        }
        if(flag&&s[i]=='C'){
            no();
            cout<<'\n';
            return;
        }
        if(flag&&s[i]=='W')
        nums++;
    }
    if(nums>k){
    no();
    cout<<'\n';
    }
    else
    {
        yes();
        cout<<'\n';
    } 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}