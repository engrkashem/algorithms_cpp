#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int dp[N];

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

int tribunacci(int n){
    // base case
    if(n<=3)return 1;

    //check if already result availe
    if(dp[n]!=-1){
        return dp[n];
    }

    //calculate result/recurrence relation
    int ans= tribunacci(n-1)+tribunacci(n-2)+tribunacci(n-3);
    dp[n]=ans;
    return ans;

}

int main(){
    int n; cin>>n;

    for(int i=1; i<=n; i++){
        dp[i]=-1;
    }

    cout<<tribunacci(n)<<"\n";

    return 0;
}
