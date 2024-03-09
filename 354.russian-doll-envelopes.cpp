/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        static bool decSort(vector<int>& v1, vector<int>& v2) {
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        
        return v1[0] < v2[0];
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),decSort);
        vector<int>v;
        v.push_back(env[0][1]);
        for(int i=1;i<env.size();i++){
            if(env[i][1]>v.back()){
                v.push_back(env[i][1]);
            }else{
                auto it=lower_bound(v.begin(),v.end(),env[i][1])-v.begin();
                v[it]=env[i][1];
            }
        }
        return v.size();
    }
};
// @lc code=end

