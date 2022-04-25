#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    vector<ll> a(n, 0);
    for(auto &i : a){
        cin>>i;
    }
    ll tmp;
    ll ans = 1e30;
    for(int i = 0;i < n;++i){
        ll cur = 0;
        ll rec = 0;
        for(int j = i+1;j < n;++j){
            tmp = rec/a[j]+1;
            cur += tmp;
            rec = tmp*a[j];
        }
        rec = 0;
        for(int j = i-1;j >= 0;--j){
            tmp = rec/a[j]-1;
            cur += abs(tmp);
            rec = tmp*a[j];
        }
        ans = min(ans, cur);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

