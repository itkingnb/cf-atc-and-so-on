/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>a(cards.size());
        for(int i=0;i<cards.size();i++){
            a[i]=1.0*cards[i];
        }
        bool ok=0;
        auto dfs=[&](auto&&self,vector<double> a)->void{
            // for(auto x:a){
            //     cout<<x<<" ";
            // }
            // cout<<'\n';
            if(a.size()==1){
                ok|=(abs(a[0]-24)<1e-6);
                // if(a[0]-24<1e-6){
                //     cout<<111111111<<'\n';
                // }
            }
            for(int i=0;i<a.size();i++){
                for(int j=i+1;j<a.size();j++){
                    vector<double>t;
                    double x=a[i],y=a[j];
                    for(int k=0;k<a.size();k++){
                        if(k!=i&&k!=j){
                            t.push_back(a[k]);
                        }
                    }
                    t.push_back(x+y);
                    self(self,t);
                    t.pop_back();
                    t.push_back(x-y);
                    self(self,t);
                    t.pop_back();
                    t.push_back(y-x);
                    self(self,t);
                    t.pop_back();
                    t.push_back(x*y);
                    self(self,t);
                    t.pop_back();
                    if(y){
                        t.push_back(x/y);
                        self(self,t);
                        t.pop_back();
                    }
                    if(x){
                        t.push_back(y/x);
                        self(self,t);
                        t.pop_back();
                    }
                }
            }
        };
        dfs(dfs,a);
        return ok;
    }
};
// @lc code=end

