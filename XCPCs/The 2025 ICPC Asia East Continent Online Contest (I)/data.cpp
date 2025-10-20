#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
    int V=rng()%(int)100+1;
    cout<<5<<" "<<10<<" "<<V<<" "<<rng()%5+1<<endl;
    for(int i=0;i<10;i++){
        cout<<rng()%5+1<<" "<<rng()%5+1<<" "<<rng()%(int)V+1<<endl;
    }
}