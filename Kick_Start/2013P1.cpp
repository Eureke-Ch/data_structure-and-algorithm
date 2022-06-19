#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    int cas = 1;
    while(n--){
        int m;
        cin>>m;
        string max_card;
        char c[100];
        int ans = 0;
        cin.getline(c, 100);
        for(int i = 0;i < m;++i){
            cin.getline(c, 100);
            string cur(c);
            if(i == 0)max_card = cur;
            if(cur < max_card){
                ans++;
            }else{
                max_card = cur;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
        cas++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

