#include<bits/stdc++.h>
using namespace std;

/*
- fib(n)- calculate the nith fibonacci numbers
- fib(n) = fib(n-1)+fib(n-2)
- fib(1)=1, fib(2)=1
*/

const int N=100;

int dp[N]; //dp array

int main(){
    int n; cin>>n;

    //1. base case
    dp[1]=1;
    dp[2]=1;

    //2. loop through the state
    for(int i=3; i<=n; i++){
        //2.1 calculate the answer from the smaller subproblems
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;

    return 0;
}

