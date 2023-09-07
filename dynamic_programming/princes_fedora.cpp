#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int dp[N], coins[N];
int n; 

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>coins[i];
        dp[i]=-1;
    }
    dp[1]=coins[1];
    dp[2]=coins[2];
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-2]+coins[i];
    }
    cout<<max(dp[n],dp[n-1])<<endl;
    return 0;
}

// int solve(int n){
//     if(n<=2)return coins[n];
//     if(dp[n] != -1)return dp[n];
//     dp[n]=coins[n]+solve(n-2);
//     return dp[n];
// }

// int main(){
//     cin>>n;
//     for(int i=1; i<=n; i++){
//         cin>>coins[i];
//         dp[i]=-1;
//     }
//     cout<<max(solve(n), solve(n-1))<<endl;
//     return 0;
// }