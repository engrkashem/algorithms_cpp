#include<bits/stdc++.h>
using namespace std;
/**
 - State: fun(n, target)-> return true if it is possible to create a subset from numbers 1 to n and form the sum "target"

 - recurrance: fun(n, target)-> fun(n-1, target) or
                                fun(n-1, target-nums[n]) if target >= nums[n]

 - base case: fun(0, target) -> 1 if target ==0
                                else 0

6 1
3 34 4 12 5 2
target=9

1 5
5

*/
const int N=101;
const int M=1e5+5;
int nums[N];
int dp[N][M];

int subset_sum(int n, int target){
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
    int ans1=subset_sum(n-1, target);
    if(target < nums[n]){
        dp[n][target] = ans1;
        return ans1;
    }

    int ans2=subset_sum(n-1, target-nums[n]);
    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
    
}

int main(){
    int n, target;
    cin>>n>>target;

    for(int i=1; i<=n; i++){
        cin>>nums[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            dp[i][j]=-1;
        }
    }

    cout<<subset_sum(n,target)<<endl;

    return 0;
}