#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int dp[N];

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

int main(){
    int n; cin>>n;

    //base case
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;

    for(int i=4; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

    cout<<dp[n]<<"\n";

    return 0;
}
