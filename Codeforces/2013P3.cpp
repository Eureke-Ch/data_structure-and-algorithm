#include <bits/stdc++.h>
using namespace std;
#define ll long long
int flag;
unordered_map<string, int> vis;
unordered_map<string, unordered_set<string>> rec;
void dfs(string peo){
    if(flag)return ;
    for(auto p : rec[peo]){
        if(vis[p] == vis[peo]){
            flag = 1;
            return ;
        }else if(vis[p] == 0){
            vis[p] = vis[peo] == 1 ? -1 : 1;
            dfs(p);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    int cas = 1;
    while(n--){
        flag = 0;
        vis.clear();
        rec.clear();
        int m;
        cin>>m;
        for(int i = 0;i < m;++i){
            string a, b;
            cin>>a>>b;
            vis[a] = 0;vis[b] = 0;
            if(rec.find(a) == rec.end()){
                rec[a] = unordered_set<string>();
            }
            rec[a].insert(b);
            if(rec.find(b) == rec.end()){
                rec[b] = unordered_set<string>();
            }
            rec[b].insert(a);
        }
        for(auto peo : vis){
            if(flag)break;
            if(vis[peo.first] == 0){
                vis[peo.first] = 1;
                dfs(peo.first);
            }
        }

        cout<<"Case #"<<cas<<": ";
        if(!flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        cas++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

