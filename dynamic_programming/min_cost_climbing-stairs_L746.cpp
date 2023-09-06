#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& cost, vector<int>& dp, int n){
        //base case
        if(n<0)return 0;
        if(n==1 || n==0)return cost[n];

        if(dp[n]!=-1)return dp[n];

        dp[n]=cost[n]+min(solve(cost,dp,n-1), solve(cost,dp,n-2));
        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        //if(len<=1)return 0;
        vector<int>dp;
        for(int i=0; i<=len; i++){
            dp.push_back(-1);
        }

        return min(solve(cost,dp,len-1), solve(cost,dp,len-2));
    }
};

int main(){
    Solution obj;
    vector<int>v={1,100,1,1,1,100,1,1,100,1};
    cout<<obj.minCostClimbingStairs(v)<<"\n";

    return 0;
}


