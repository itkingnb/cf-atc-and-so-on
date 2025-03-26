#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
int jc(int n){
    if(n==1||n==0)
    return 1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n,0);
    vector<int>b(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    map<int,int>diff;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(a[i]!=b[i])
        diff[b[i]]++;
    }
    int m;
    cin>>m;
    vector<int>d(m,0);
    for(int i=0;i<m;i++){
    cin>>d[i];
    if(diff[d[i]])
    diff[d[i]]--;
    }
    for(auto &[x,y]:diff){
        if(y){
            no();
            return;
        }
    }
    if(count(b.begin(),b.end(),d[m-1]))
    yes();
    else
    no();
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