#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k,dp[N];

int main(){
    cin>>n>>k;
    //base case
    for(int i=1; i<=n; i++){
        dp[i]=1;
    }

    if(k<=n){
        cout<<dp[k]<<endl;
        return 0;
    }

    for(int i=n+1; i<=k; i++){
        for(int j=1; j<=n; j++){
            dp[i]=dp[i]+dp[i-j];
        }
    }
    cout<<dp[k]<<endl;

    return 0;
}