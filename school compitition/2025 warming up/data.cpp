#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
    srand(time(0));
    cout<<1<<endl;
    int n=rng()%100;
    n++;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<(rng()%n)<<' ';
    }
    return 0;
}