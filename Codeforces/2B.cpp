// 尾零最小的问题，本质就是动态规划求解路径中质因子2和质因子5的最小值，同时记得特殊情况0即可；
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> a2 = vector<vector<int>>(n, vector<int>(n, 0));
    vector<vector<int>> a5 = vector<vector<int>>(n, vector<int>(n, 0));
    int flag = 0, x, y;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            int cur;
            cin>>cur;
            if(!cur){
                flag = 1;
                x = i;
                y = j;
                a2[i][j] += 1;
                a5[i][j] += 1; 
            }
            while(cur){
                if(cur%2 == 0){
                    a2[i][j] ++;
                    cur = cur/2;
                }
                else if(cur%5 == 0){
                    a5[i][j] ++;
                    cur = cur/5;
                }else{
                    break;
                }
            }
        }
    }
    int ans;
    vector<vector<int>> rec2 = vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX));
    vector<vector<int>> rec5 = vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX));
    vector<vector<char>> dir2 = vector<vector<char>>(n+1, vector<char>(n+1, '-'));
    vector<vector<char>> dir5 = vector<vector<char>>(n+1, vector<char>(n+1, '-'));
    rec2[0][1] = 0;rec5[0][1] = 0;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            rec2[i+1][j+1] = min(rec2[i][j+1], rec2[i+1][j]) + a2[i][j];
            if(rec2[i][j+1] < rec2[i+1][j])dir2[i+1][j+1] = 'D';
            else{dir2[i+1][j+1] = 'R';}
        }
    }
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            rec5[i+1][j+1] = min(rec5[i+1][j], rec5[i][j+1]) + a5[i][j];
            if(rec5[i][j+1] < rec5[i+1][j])dir5[i+1][j+1] = 'D';
            else{dir5[i+1][j+1] = 'R';}
        }
    }
    ans = min(rec2[n][n], rec5[n][n]);
    if(flag)ans = min(ans, 1);
    cout<<ans<<endl;

    if(flag && ans == 1){
        string path = "";
        for(int i = 0;i < x;++i){
            path += 'D';
        }
        for(int i = 0;i < y;++i){
            path += 'R';
        }
        for(int i = x;i < n;++i){
            path += 'D';
        }
        for(int i = y;i < n;++i){
            path += 'R';
        }
        cout<<path<<endl;
    }else if(rec2[n][n] < rec5[n][n]){
        int px = n, py = n;
        string path = "";
        while(px != 1 || py != 1){
            path += dir2[px][py];
            if(dir2[px][py] == 'D'){
                px -= 1;
            }else{
                py -= 1;
            }
        }
        for(auto i = path.rbegin();i != path.rend();++i){
            cout<<*i;
        }
        cout<<endl;
    }else{
        int px = n, py = n;
        string path = "";
        while(px != 1 || py != 1){
            path += dir5[px][py];
            if(dir5[px][py] == 'D'){
                px -= 1;
            }else{
                py -= 1;
            }
        }
        for(auto i = path.rbegin();i != path.rend();++i){
            cout<<*i;
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

