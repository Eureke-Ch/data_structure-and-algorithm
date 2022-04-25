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
        vector<int> points(n, 0);
        for(auto &i : points)cin>>i;
        if(points[n-1] - points[0] + 1 >= n+3)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

