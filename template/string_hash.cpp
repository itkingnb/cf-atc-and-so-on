#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define N 1510
ull p[N],h[N];
const int P=131;
const ll mod=9223372036854775807;
int to_hash(string s){
    p[0]=1;
    h[0]=(ull)0;
    for(int i=0;i<s.size();i++){
        h[i+1]=((h[i]*P%mod)+s[i])%mod;
        p[i+1]=p[i]*P%mod;
    }
    return h[s.size()]-h[1-1]*p[s.size()-1+1];
}
void solve(){
    int n;
    cin>>n;
    vector<ull>hashs;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        hashs.push_back(to_hash(a));
    }
    sort(hashs.begin(),hashs.end());
    hashs.erase(unique(hashs.begin(),hashs.end()),hashs.end());
    cout<<hashs.size();
}
int main(){
    solve();
    return 0;
}