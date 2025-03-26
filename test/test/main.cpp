class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        auto get=[&](auto&& get,vector<int> nums1,int p1,vector<int> nums2,int p2,int x)->int{
            if(p1==n){
                return nums2[p2+x-1];
            }else if(p2==m){
                return nums1[p1+x-1];
            }
            if(x==1){
                return min(nums1[p1],nums2[p2]);
            }
            int pp1=min(n-1,p1+x/2-1);
            int pp2=min(m-1,p2+x/2-1);
            if(nums1[pp1]<nums2[pp2]){
                x-=pp1-p1+1;
                return get(get,nums1,pp1+1,nums2,p2,x);
            }
            x-=pp2-p2+1;
            return get(get,nums1,p1,nums2,pp2+1,x); 
        };
        if((n+m)&1){
            return 1.0*get(get,nums1,0,nums2,0,((n+m)>>1)+1);
        }
        return (get(get,nums1,0,nums2,0,(((n+m)>>1)+1))+get(get,nums1,0,nums2,0,((n+m)>>1)))*1.0/2;
    }
};