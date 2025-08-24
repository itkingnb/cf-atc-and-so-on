/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 *
 * [2348] 全 0 子数组的数目
 */

// @lc code=start
#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        int n=nums.size();
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }else{
                ans+=(1+cnt)*cnt/2;
                cnt=0;
            }
        }
        if(cnt){
            ans+=(1+cnt)*cnt/2;
        }
        return ans;
    }
};
// @lc code=end

