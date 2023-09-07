#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
/**
 * state: fun(n,x) -> maximum happiness till day-n 
                       if we pick task-x on day n
 * Recurrence: fun(n,x)=max{
                          fun(n-1,y) where x!=y
                          + happiness[n][x]
                        }
 * Base Case: fun(1,x) = happiness[1][x]
*/
int happiness[N][4], dp[N][4];

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<4; j++){
            cin >> happiness[i][j];
        }
    }

    //base case
    for(int task=1; task<4; task++){
        dp[1][task]=happiness[1][task];
    }

    //loop over ta state to calc smaller sub problems
    for(int day=1; day<=n; day++){
        for(int cur_task = 1; cur_task <= 3; cur_task++){
            int max_profit = -1;
            for(int last_task=1; last_task<=3; last_task++){
                if(last_task != cur_task){
                    int cur_profit=dp[day-1][last_task]+ happiness[day][cur_task];
                    max_profit=max(max_profit, cur_profit);
                }
            }
            dp[day][cur_task]=max_profit;
        }
    }
    int ans=-1;
    for(int i=1; i<=3; i++){
        ans=max(ans, dp[n][i]);
    }
    cout<<ans<<endl;

    return 0;
}