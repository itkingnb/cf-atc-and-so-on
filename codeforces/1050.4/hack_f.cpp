#include<bits/stdc++.h>
using namespace std;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<1<<endl;
    cout<<250<<endl;
    for(int i=1;i<=250;i++){
        cout<<250<<" ";
        for(int j=1;j<=250;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}