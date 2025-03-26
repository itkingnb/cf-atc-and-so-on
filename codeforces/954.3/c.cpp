#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    vector<int>a(m,0);
    int hash[100010]={0};
    for(int i=0;i<m;i++){
        cin>>a[i];
        hash[a[i]]++;
    }
    string c;
    cin>>c;
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    for(int i=0;i<m;i++){
        if(hash[a[i]]!=1){
            int t=hash[a[i]]-1;
            while(t--){
                char m=c[c.size()-1];
                c.insert(i,1,m);
                c.pop_back();
            }
            i+=hash[a[i]]-1;
        }
    }
    for(int i=0;i<m;i++){
        //cout<<s[a[i]-1]<<c[a[i]-1];
        swap(s[a[i]-1],c[i]);
    }
    cout<<s;
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