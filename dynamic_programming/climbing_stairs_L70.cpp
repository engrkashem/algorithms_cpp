#include<bits/stdc++.h>
using namespace std;

const int N=100;
int dp[N];

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

int comb(int n){
    //base case
    if(n==0 || n==1)return 1;

    //check if result exists
    if(dp[n]!=-1)return dp[n];

    //recurrence relation
    int ans=comb(n-1)+comb(n-2);
    dp[n]=ans;
    return ans;
}

int main(){
    int n; cin>>n;

    for(int i=1; i<=n; i++){
        dp[i]=-1;
    }

    cout<<comb(n)<<"\n";

    return 0;
}

