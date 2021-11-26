#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> rec;
    vector<int> vis;
    int flag = 1;
    vector<int> ans;
    void dfs(int node){
        vis[node] = 1;
        for(auto &i : rec[node]){
            if(flag == 0)return ;
            if(vis[i] == 0){
                dfs(i);
            }else if(vis[i] == 1){
                flag = 0;
                return ;
            }
        }
        vis[node] = 2;
        ans.push_back(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        rec.resize(numCourses);
        vis.resize(numCourses);
        for(auto &i : prerequisites){
            rec[i[1]].push_back(i[0]);
        }
        for(int i = 0;i < numCourses && flag;++i){
            if(vis[i] == 0){
                dfs(i);
            }
        }
        reverse(ans.begin(), ans.end());
        if(!flag)return vector<int>();
        else return ans;
    }
};