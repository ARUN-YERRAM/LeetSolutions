/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candid, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candid.begin(), candid.end());
        backTrack(ans, current, candid, target, 0);
        return ans;
    }
    
    void backTrack(vector<vector<int>>& ans, vector<int>& current, vector<int>& candid, int target, int start) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        for (int i = start; i < candid.size(); ++i) {
            if (i > start && candid[i] == candid[i - 1])
                continue;
            if (candid[i] > target) 
                break;
            current.push_back(candid[i]);
            backTrack(ans, current, candid, target - candid[i], i + 1);
            current.pop_back();
        }
    }
};







// #include<bits/stdc++.h>
// class Solution {
// public:
//     // vector<vector<int>>ans;
//     void backTrack( vector<vector<int>>&ans,vector<int>&vec,vector<int>&candid,int idx,int target){
//         if(target == 0){
//             // if(find(ans.begin(),ans.end(),vec) == ans.end())
//             ans.push_back(vec);
//             return;
//         }

//     //     if(idx >= candid.size() || target < 0) return;

//     //     vec.push_back(candid[idx]);

//     //     backTrack(ans,vec,candid,idx+1,target-candid[idx]);

//     //     vec.pop_back();

//     //     backTrack(ans,vec,candid,idx+1,target);
//     // }
//     for (int i = idx; i < candid.size(); ++i) {
//             if (i > idx && candid[i] == candid[i - 1]) // Skip duplicates
//                 continue;
//             if (candid[i] > target) // Optimization: Stop if candidate is greater than target
//                 break;
//             vec.push_back(candid[i]);
//             backTrack(ans, vec, candid, target - candid[i], i + 1);
//             vec.pop_back();
//         }
// }
//     vector<vector<int>> combinationSum2(vector<int>& candid, int target) {
//         sort(candid.begin(),candid.end());
//         vector<vector<int>>ans;

//         vector<int>vec;
//         int i = 0;

//         backTrack(ans,vec,candid,i,target);

//         return ans;
//     }
// };
// // @lc code=end

