    #include<bits/stdc++.h>
    using namespace std;
    #define N 100001
    #define ll long long
    string ans;
    int n;
    map<int,int>mp;
    int cnt;
    void solve(){
        ans.clear();
        mp.clear();
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        bool flag=true;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(a[i]!=b[i])
            flag=false;
            mp[b[i]]=i;
        }
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<n-1;j++){
                if(mp[a[j]]>mp[a[j+1]]){
                    swap(a[j],a[j+1]);
                    ans.push_back('2');
                }else
                ans.push_back('1');
            }
            ans.push_back('1');
        }
        cout<<ans;
    }

    int main(){
        //ios_base::sync_with_stdio(0);
        //cin.tie(0); cout.tie(0);
        int t=1;
        cin>>t;
        while(t--){
            solve();
            cout<<'\n';
        }       
        return 0;
    }