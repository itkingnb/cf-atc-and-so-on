#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,w;
    priority_queue<int>a;
    priority_queue<int,vector<int>,greater<int>>b;
    cin>>n>>w;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(b.empty()||x>b.top())
        b.push(x);
        else
        a.push(x);
        int k=max(1,w*(i+1)/100);
        while(b.size()>k) a.push(b.top()),b.pop();
        while(b.size()<k) b.push(a.top()),a.pop();
        cout<<b.top()<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}