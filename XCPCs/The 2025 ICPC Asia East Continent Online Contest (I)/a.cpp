#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int P=131;
#define ull unsigned ll
ull id(string s){
    ull res=0;
    for(int i=0;i<s.size();i++){
        res=res*P+s[i];
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<string>teams;
    // map<ull,int>ac;
    map<ull,vector<int>>problems;
    map<ull,ll>time_ac;
    map<ull,int>ac;
    map<ull,vector<ll>>time_uk,time_wa;
    int mx=0,pt=0;
    struct line{
        string t;char pp;int tt;
        string stt;
    };
    vector<line>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].t>>a[i].pp>>a[i].tt>>a[i].stt;
    }
    sort(a.begin(),a.end(),[](line aa,line bb){
        return aa.tt<bb.tt;
    });
    for(int i=0;i<n;i++){
        string team=a[i].t;
        char p=a[i].pp;
        int t=a[i].tt;
        string st=a[i].stt;
        // cin>>team>>p>>t>>st;
        ull idd=id(team);
        if(problems[idd].size()==0){
            teams.push_back(team);
            problems[idd].resize(26);
            time_uk[idd].resize(26);
            time_wa[idd].resize(26);
        }
        if(st=="Accepted"&&problems[idd][p-'A']<=0){//ac且之前没ac过或者uk过
            problems[idd][p-'A']=2;//ac
            ac[idd]++;//数量加一
            time_ac[idd]+=t+time_wa[idd][p-'A']*20;//累计罚时
            if(ac[idd]>mx||ac[idd]==mx&&time_ac[idd]<pt){//如果优于当前冠军
                mx=ac[idd];//更新
                pt=time_ac[idd];
            }
        }else if(st=="Rejected"&&problems[idd][p-'A']<=0){//wa且之前没有uk或者ac
            time_wa[idd][p-'A']++;//累计
        }else if(st=="Unknown"&&problems[idd][p-'A']<=0){//uk且之前没有ac
            problems[idd][p-'A']=1;
            time_uk[idd][p-'A']+=t;
        }
    }
    vector<string>ans;
    for(int i=0;i<teams.size();i++){
        ull idd=id(teams[i]);
        for(int j=0;j<26;j++){
            if(problems[idd][j]==1){
                ac[idd]++;
                time_ac[idd]+=time_uk[idd][j];
                time_ac[idd]+=time_wa[idd][j]*20;
            }
        }
        // cerr<<ac[idd]<<" "<<
        if(ac[idd]>mx||ac[idd]==mx&&time_ac[idd]<=pt){
            // cout<<teams[i]<<" ";
            ans.push_back(teams[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}