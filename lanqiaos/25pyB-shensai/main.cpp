// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n=50000;
//     vector<string>s;
//     for(int i=0;i<n;i++){
//         string ss;
//         cin>>ss;
//         s.push_back(ss);
//     }
//     sort(s.begin(),s.end(),[](string a,string b){
//         return a.size()<b.size();
//     });
//     set<string>st;
//     for(int i=0;i<n;i++){
//         if(s[i].size()==1){
//             st.insert(s[i]);
//             continue;
//         }
//         string tmp=s[i].substr(0,s[i].size()-1);
//         sort(tmp.begin(),tmp.end());
//         do{
//             if(st.count(tmp)){
//                 st.insert(s[i]);
//                 break;
//             }
//         }while(next_permutation(tmp.begin(),tmp.end()));
//     }
//     string mx;
//     for(auto x:st){
//         cout<<x<<'\n';
//         if(x.size()>mx.size()){
//             mx=x;
//         }
//     }
//     cout<<"mx:"<<mx<<endl;

// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rng(time(0));
int n=10000;
vector<int>a(n+1);

int sol(){
    vector<int>fen(n+1);
    vector<int>t=a;
    vector<int>pos(n+1);
    for(int i=1;i<=n;i++){
        pos[t[i]]=i;
    }
    auto add=[&](int x)->void{
        while(x<=n){
            fen[x]++;
            x+=(x&-x);
        }
    };
    auto query=[&](int x)->int{
        int ans=0;
        x--;
        while(x>0){
            ans+=fen[x];
            x-=(x&-x);
        }
        return ans;
    };
    int ans=0;
    for(int i=1;i<=n;i++){
        int left=query(pos[i]);
        int right=i-1-left;
        ans+=abs(pos[i]+right-i);
        add(pos[i]);
    }
    return ans;
}


int brute(){
    int ans=0;
    vector<int>t=a;
    vector<int>pos(n+1);
    for(int i=1;i<=n;i++){
        pos[t[i]]=i;
    }
    for(int i=1;i<=n;i++){
        while(pos[i]>i){
            swap(t[pos[i]],t[pos[i]-1]);
            ans++;
            pos[t[pos[i]]]++;
            pos[i]--;
        }
        while(pos[i]<i){
            swap(t[pos[i]],t[pos[i]+1]);
            ans++;
            pos[t[pos[i]]]--;
            pos[i]++;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    // reverse(a.begin()+1,a.end());
    shuffle(a.begin()+1,a.end(),rng);
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    // cout<<sol()<<"\n";
    while(brute()==sol()){
        cout<<"AC"<<endl;
        shuffle(a.begin()+1,a.end(),rng);
        // for(auto x:a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
    }
    for(auto x:a){
        cout<<x<<" ";
    }
}