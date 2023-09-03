#include<bits/stdc++.h>
using namespace std;

/*
- fib(n)- calculate the nith fibonacci numbers
- fib(n) = fib(n-1)+fib(n-2)
- fib(1)=1, fib(2)=1
*/

const int N=100;

int dp[N]; //dp array

int fib(int n){
    //1. base case
    if(n<=2) return 1;

    //2. check if current state already solved
    if(dp[n]!=-1){//if current state is already solved
        return dp[n];
    }

    //3. calculate from smaller subproblems
    //if current state is not solved already
    int ans= fib(n-1)+fib(n-2);
    dp[n]=ans;//memorize the smaller subproblems
    return ans;

}

int main(){
    int n; cin>>n;

    //for(int i=1; i<=n; i++){
        //dp[i]=-1; //merk all state as unvisited
    //}
    //alternate way of loop through
    memset(dp, -1, sizeof(dp)); //merk all state as unvisited
    cout<<fib(n)<<"\n";

    return 0;
}
