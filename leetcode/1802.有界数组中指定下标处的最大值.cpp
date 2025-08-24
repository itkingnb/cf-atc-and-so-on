/*
 * @lc app=leetcode.cn id=1802 lang=cpp
 *
 * [1802] 有界数组中指定下标处的最大值
 */

// @lc code=start
#define ll long long
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l=1,r=1e9+1;
        int ans=0;
        auto check=[&](ll x)->bool{
            ll f=index;
            ll b=n-index-1;
            ll mx=min(f,x-1);
            ll sum=(x-mx+x)*(mx+1)/2;
            sum+=(f-mx);
            // cout<<sum<<'\n';
            ll mx2=min(b,x-1);
            sum+=(x-mx2+x)*(mx2+1)/2;
            sum+=(b-mx2);
            // cout<<sum<<'\n';
            // cout<<x<<" "<<sum<<'\n';
            return sum-x<=maxSum;
        };
        // check(0);
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};
// @lc code=end

