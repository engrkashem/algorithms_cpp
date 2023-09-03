#include<bits/stdc++.h>
using namespace std;

long long arr[1];

long long fibonacci(int n) {
    if(n<=2)return 1;
    //check if fib(n) already calculated
    if(arr[n]>0){
        return arr[n];
    }
    arr[n]=fibonacci(n-1)+fibonacci(n-2);
    return arr[n];
}

int main(){
    cout<<fibonacci(3)<<endl;
    cout<<fibonacci(5)<<endl;
    cout<<fibonacci(50)<<endl;

    return 0;
}
