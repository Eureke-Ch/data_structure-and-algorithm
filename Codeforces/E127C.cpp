#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<ll> s(n, 0);
        for(auto &i : s)cin>>i;
        sort(s.begin(), s.end());
        ll ans = 0;
        int sum = 0;
        for(int i = 0;i < n;++i){
            sum += s[i];
            if(sum > x)break;
            ans += (x-sum)/(i+1)+1;
        }
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

