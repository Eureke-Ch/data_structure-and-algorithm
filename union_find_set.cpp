//顾名思义，并查集的本质就是处理一些不相交集合的合并和查询问题，主要由两个操作，union和find；以如下例题为例：
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。返回矩阵中 省份 的数量。
#include <vector>
using namespace std;
// class union_find_set{
//     public:
//         vector<int> rec;
//         union_find_set(int n){
//             rec = vector<int>(n, -1);
//         }
//         int find(int child){
//             if(rec[child] == child)
//                 return child;
//             else{
//                 rec[child] = find(rec[child]);
//                 return rec[child];
//             }
//         }
//         void union_set(int child1, int child2){
//             if(find(child1) != find(child2)){
//                 rec[find(child1)] = find(child2);
//             }
//         }
// };
vector<int> rec;
int find(int child){
    if(rec[child] != child)
        rec[child] = find(rec[child]);
    return rec[child];
}
void union_set(int child1, int child2){
    rec[find(child1)] = find(child2);
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int ans = 0;
    int n = isConnected.size();
    rec = vector<int>(n, -1);
    for(int i = 0;i < n;++i){
        rec[i] = i;
    }
    for(int i = 0; i < n;++i){
        for(int j = 0;j < n;++j){
            if(isConnected[i][j] == 1){
                union_set(i, j);
            }
        }
    }
    for(int i = 0 ;i < n;++i){
        if(find(i) == i){
            ans++;
        }
    }
    return ans;
}
int main(){
    // findCircleNum()
}