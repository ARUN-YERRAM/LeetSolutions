/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>vec;
    void solve(vector<int>&candid,vector<int>ans,int idx,int target){
        if(target == 0){
            vec.push_back(ans);
            return;
        }

        if(idx >= candid.size() || target < 0) return;
        
        ans.push_back(candid[idx]);

        solve(candid,ans,idx,target-candid[idx]);

        ans.pop_back();

        solve(candid,ans,idx+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candid, int target) {
        // vector<vector<int>>vec;
        sort(candid.begin(),candid.end());
        vector<int>ans;
        int i = 0;
        int sum = 0;

        solve(candid,ans,i,target);
        
        return vec;
    }
};
// @lc code=end

