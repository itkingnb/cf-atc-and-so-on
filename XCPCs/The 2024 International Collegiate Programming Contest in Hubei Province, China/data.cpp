#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
    srand(time(0));
    int n=1;
    cout<<1<<endl;
    int t=0;
    for(int i=0;i<2;i++){
        t+=rng()%(100)+2;
        cout<<(t)<<' ';
    }
    return 0;
}