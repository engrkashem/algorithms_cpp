#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& nums, vector<int>& dp, int n){
        if (n<0)return 0;
        //if(n<=1)return nums[n];

        if(dp[n]!= -1)return dp[n];

        dp[n]=max(solve(nums,dp,n-2)+nums[n], solve(nums,dp,n-1));
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp;
        for(int i=0; i<=n; i++)dp.push_back(-1);
        return solve(nums,dp,n-1);
    }
};

int main(){
    Solution obj;
    // vector<int>v={2,7,9,3,1};
    vector<int>v={1,2,3,1};
    cout<<obj.rob(v)<<"\n";

    return 0;
}
