#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
    cout<<1<<endl;
    cout<<rng()%10000<<" "<<rng()%(int)1e9<<" "<<rng()%(int)1e9<<endl;
}