#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n, dp[N];

int nbunacci(int k){
    if(k<=n)return 1;

    if(dp[k]!=0)return dp[k];

    for(int i=1; i<=n; i++){
        // cout<<dp[k]<<" ";
        dp[k]=dp[k] + nbunacci(k-i);
        
    }

    return dp[k];
}

int main(){
    int k; cin>>n>>k;

    memset(dp, 0, sizeof(dp));

    cout<<nbunacci(k)<<"\n";


    return 0;
}