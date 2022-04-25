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
        vector<int> a(n+1, 0);
        int mx = -1, mn = INT_MAX;
        ll ans = 0;
        for(int i = 0;i < n;++i){
            cin>>a[i];
            if(i)ans += abs(a[i]-a[i-1]);
            mx = max(mx, a[i]);mn = min(mn, a[i]);
        }
        if(mn != 1)ans += min(a[0]-1, min((mn-1)*2, a[n-1]-1));
        if(mx < x)ans += min(x-a[0], min((x-mx)*2, x-a[n-1]));
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

