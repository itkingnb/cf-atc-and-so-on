#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"YES";
}
void no(){
    cout<<"NO";
}
std::vector<int> minp, primes, f;

void sieve(int n) {
    minp.assign(n + 1, 0);
    f.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            f[i] = 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                f[i * p] = f[i];
                break;
            }
            f[i * p] = f[i] + 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }
}

void AUTO_AC_MACHINE(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<int>cnt(n+1,0);
    vector<int>d(n+1,0);
    vector<int>b(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                cnt[j]++;
                b[j]++;
                cnt[a[i]/j]++;
                b[a[i]/j]++;
            }
            if(j*j==a[i]){
                cnt[j]--;
                b[j]--;
            }
        }
        if(a[i]%3==0){
            d[a[i]/3]++;
            d[a[i]/3+1]--;
        }
        d[1]++;
        d[a[i]/4+1]--;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        d[i]+=d[i-1];
        // d[i]-=b[i];
        if(d[i]+k+cnt[i]-b[i]>=n){
            ans=max(ans,i);
        }
    }
    cout<<ans;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    // sieve(2e5);
    while(t--){
        AUTO_AC_MACHINE();
        cout<<'\n';
    }
}
