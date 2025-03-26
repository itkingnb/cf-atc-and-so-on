#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
vector<int>zishu={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
void solve(){
    int t,n,k,j;
    int flag=-1;
    int a[1000]={0};
    int b[1010]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(count(zishu.begin(),zishu.end(),a[i])==0&&a[i]!=1){
        flag=0;
        }
    }
    if(flag==0){
        cout<<flag;
        return ;
    }else{
        for(int i=0;i<n;i++){
            flag=0;
            k=a[i];
            j=1;
            do{
                if(i+j>=n){
                    b[i]=-1;
                    flag=1;
                    break;
                }
                k+=a[i+j];
                j++;
            }while(count(zishu.begin(),zishu.end(),k)!=0);
            if(flag==1)
            continue ;
            b[i]=j-1;
        }
        sort(b,b+n+1);
            if(b[n-1]==-1){
                cout<<-1;
                return;
            }else{
                for(int i=0;i<n+1;i++){
                    if(b[i]!=-1&&b[i]!=0){
                        cout<<b[i];
                        return;
                    }
                }
            }
        }
        return;
    }
    
signed main(){
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    for(int i=0;i<t;i++){
    solve();
    cout<<'\n';
    }
    return 0;
}