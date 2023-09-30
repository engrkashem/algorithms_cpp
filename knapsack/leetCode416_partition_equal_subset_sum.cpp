#include<bits/stdc++.h>
using namespace std;
/**
 - State: fun(n, target)-> return true if it is possible to create a subset from numbers 1 to n and form the sum "target"

 - recurrance: fun(n, target)-> fun(n-1, target) or
                                fun(n-1, target-nums[n]) if target >= nums[n]

 - base case: fun(0, target) -> 1 if target ==0
                                else 0

4 
1 5 11 5
target=9

1 5
5

*/
const int N=202+2;
const int M=1e5+5;
int dp[N][M];

int subset_sum(int n, int target, vector<int>&nums){
    //basecase
    if(n==0){
        if(target==0)return 1;
        return 0;
    }

    // if result already exists
    if(dp[n][target] != -1){
        return dp[n][target];
    }

    // calculate result from smaller state
    int ans1=subset_sum(n-1, target, nums);
    if(target < nums[n]){
        dp[n][target] = ans1;
        return ans1;
    }

    int ans2=subset_sum(n-1, target-nums[n], nums);
    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
    
}

bool canPartition(vector<int>& nums) {
    int total_sum=0, len=0;
    for(int x:nums){
        total_sum+=x;
        len++;
    }
    if(total_sum % 2 != 0)return false;
    int target=total_sum/2;

    int res=subset_sum(len, target, nums);
    if(res)return true;
    return false;
}

int main(){
    int n, target;
    cin>>n;
    vector<int> nums;

    for(int i=1; i<=n; i++){
        cin>>nums[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            dp[i][j]=-1;
        }
    }

    cout<<canPartition(nums)<<endl;

    return 0;
}