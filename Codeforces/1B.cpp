#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    while(n--){
        string coord;
        cin>>coord;
        int n = coord.size();
        bool f_R = 0, f_C = 0;
        int p_R = 0, p_C = 0;
        for(int i = 0;i < n;++i){
            if(coord[i] == 'R'){f_R = 1;p_R = i;}
            if(coord[i] == 'C'){f_C = 1;p_C = i;}
        }
        if(f_R && f_C && p_C >= p_R+1 && coord[p_R+1] <= '9' && coord[p_R+1] >= '0'){
            int x = 0, y = 0;
            for(int i = 1;i < p_C;++i){
                x = x*10+coord[i]-'0';
            }
            for(int i = p_C+1;i < n;++i){
                y = y*10+coord[i]-'0';
            }
            string ans = "";
            string column = "";
            while(y){
                column += (y-1)%26+'A';
                y = (y-1)/26;
            }
            reverse(column.begin(), column.end());
            ans += column;
            ans += to_string(x);
            cout<<ans<<endl;
        }else{
            string column = "";
            int raw = 0;
            for(auto i : coord){
                if(i >= 'A' && i <= 'Z')column += i;
                else {raw = raw*10+i-'0';}
            }
            int y = 0;
            for(auto i : column){
                y = y*26+i-'A'+1;
            }
            string ans = "R";
            ans += to_string(raw);
            ans += 'C';
            ans += to_string(y);
            cout<<ans<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

