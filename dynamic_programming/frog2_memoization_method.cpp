// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
const int INF=2e9;
/**
 * State: stone(n) -> Min cost to reach nth stone from first stone
 * Recurrence: stone(n) -> for i=1 to k:
 *                          min(
 *                                  stone(n-i)+abs(h[n]-h[n-i])
 *                               )
 * Base Case: stone(1) = 0
 * 
 * 
*/

int h[N], dp[N];
int n,k;

int stone2(int n){
    //base case
    if(n==1)return 0;

    //if answer is already calculated
    if(dp[n] != -1) return dp[n];

    //recurrence relation: calculate answer from smaller subproblems
    int ans=INF;
    for(int i=1; i<=k; i++){
        //handle corner case
        if( n-i <= 0 )break;

        int candidate_ans=stone2(n-i)+abs(h[n]-h[n-i]);
        ans=min(ans, candidate_ans);
    }
    dp[n]=ans;

    return dp[n];
}

int main(){
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    for(int i=1; i<=n; i++){
        dp[i]=-1;
    }

    cout<<stone2(n)<<endl;


    return 0;
}