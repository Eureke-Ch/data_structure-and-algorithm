#include <iostream>
using namespace std;

double quick_pow(double x, int n){
    double ans = 1;
    if(n < 0){
        n = -n;
        x = 1/x;
    }
    while(n){
        if(n & 1){
            ans *= x;
        }
        n = n>>1;
        x *= x;
    }
    return ans;
}

int main(){
    double x = 1.1;
    int n = 2355;
    cout<<quick_pow(x, n)<<endl;
}