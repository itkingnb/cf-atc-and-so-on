#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
    srand(time(0));
    cout<<1<<endl;
    int n=rng()%20;
    n++;
    ll l=rng()%(int)1e18;
    l++;
    ll r=l;
    cout<<n<<' '<<l<<' '<<r<<' '<<endl;
    for(int i=0;i<n;i++){
        cout<<(rng()%2)<<' ';
    }
    return 0;
}