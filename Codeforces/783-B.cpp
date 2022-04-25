#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n, 0);
        for(auto &i : a){
            cin>>i;
        }
        vector<ll> sum(n+1, 0);
        for(int i = 0;i < n;++i){
            sum[i+1] = sum[i] + a[i];
        }
        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

