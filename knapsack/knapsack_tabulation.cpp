// https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;

/**
 * state: knapsack(n,w) -> max profit considering object 1 to n and capacity/weight w
 * recurrance:
 *      knapsack(n,w) -> max(
 *          val[n]+knapsack(n-1, cap -wt[n]),
 *          knapsack(n-1, cap)
 *      )
 * base case: knapsack(0,x)=0
*/

const int N=105;
const int M=1e5+5;
long long dp[N][M];
int wt[N], val[N];

int main(){
    int n,w; cin>>n>>w;

    for(int i=1; i<=n; i++){
        cin>>wt[i]>>val[i];
    }

    //handle base case
    for(int i=0; i <=w; i++){
        dp[0][i]=0;
    }

    // loop over the states
    for(int i=1; i<=n; i++){
        for(int cap=0; cap<=w; cap++){
            // calculate the result from smaller subproblem
            if(cap<wt[i]){
                dp[i][cap]=dp[i-1][cap];
            }
            else{
                dp[i][cap]=max(
                val[i] + dp[i-1][cap-wt[i]],
                dp[i-1][cap]
            );
            }
        }
    }

    cout<<dp[n][w]<<endl;

    return 0;
}