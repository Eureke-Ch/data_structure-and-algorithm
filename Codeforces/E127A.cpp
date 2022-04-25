#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 0;i < n;++i){
            if(s[i] == 'a'){
                if(i-1 >= 0 && s[i-1] == 'a' && dp[i-1] == 1)dp[i+1] = 1;
                if(i-2 >= 0 && s[i-1] == 'a' && s[i-2] == 'a' && dp[i-2] == 1)dp[i+1] = 1;
            }else if(s[i] == 'b'){
                if(i-1 >= 0 && s[i-1] == 'b' && dp[i-1] == 1)dp[i+1] = 1;
                if(i-2 >= 0 && s[i-1] == 'b' && s[i-2] == 'b' && dp[i-2] == 1)dp[i+1] = 1;
            }
        }
        if(dp[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

