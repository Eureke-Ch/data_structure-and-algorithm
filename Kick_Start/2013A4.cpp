#include <bits/stdc++.h>
using namespace std;
#define ll long long
void mcout(int cas){
    cout<<"Case #"<<cas<<": ";
}
struct node{
    int dis, x, y;
    bool operator > (const node &a) const {return dis > a.dis;}
};
void solve()
{
    int t;
    cin>>t;
    int cas = 1;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
    string direction = "SNWE";
    while(t--){
        mcout(cas++);
        int n;
        cin>>n;
        vector<string> maze;
        for(int i = 0;i < n;++i){
            string cur;
            cin>>cur;
            maze.push_back(cur);
        }

        int dis[105][105], vis[105][105];
        memset(dis, 63, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        priority_queue<node, vector<node>, greater<node>> q;
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        sx -= 1, sy -= 1, ex -= 1, ey -=1;
        dis[sx][sy] = 0;
        q.push({0, sx, sy});
        while(q.size()){
            int ux = q.top().x;
            int uy = q.top().y;
            q.pop();
            if(vis[ux][uy])continue;
            vis[ux][uy] = 1;
            for(int i = 0;i < 4;++i){
                if(ux+dx[i] < n && ux+dx[i] >= 0 && uy+dy[i] >= 0 && uy+dy[i] < n && maze[ux+dx[i]][uy+dy[i]] == '.' && dis[ux+dx[i]][uy+dy[i]] > dis[ux][uy]+1){
                    dis[ux+dx[i]][uy+dy[i]] = dis[ux][uy]+1;
                    q.push({dis[ux+dx[i]][uy+dy[i]], ux+dx[i], uy+dy[i]});
                }
            }
        }
        if(dis[ex][ey] > 10000){
            cout<<" Edison ran out of energy."<<endl;
        }else{
            cout<<dis[ex][ey]<<endl;
            string ans = "";
            while(ex != sx || ey != sy){
                for(int i = 0;i < 4;++i){
                    if(ex+dx[i] >= 0 && ex+dx[i] < n && ey+dy[i] < n && ey+dy[i] >= 0 && dis[ex+dx[i]][ey+dy[i]] == dis[ex][ey]-1){
                        ex += dx[i];
                        ey += dy[i];
                        ans += direction[i];
                        break;
                    }
                }
            }
            reverse(ans.begin(), ans.end());
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

