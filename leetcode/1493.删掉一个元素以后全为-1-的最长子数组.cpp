/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(nums==vector<int>(n,1)){
            return n-1;
        }
        vector<int>pre(n),suf(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }else{
                pre[i]=cnt;
                cnt=0;
            }
        }
        cnt=0;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }else{
                suf[i]=cnt;
                cnt=0;
            }
        }
        reverse(nums.begin(),nums.end());
        reverse(suf.begin(),suf.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans=max(ans,suf[i]+pre[i]);
            }
        }   
        return ans;
    }
};
// @lc code=end

