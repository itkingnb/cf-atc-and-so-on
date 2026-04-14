#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
    cout<<1<<endl;
    int a=rng()%10;
    int b=rng()%10;
    int c=rng()%10;
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}