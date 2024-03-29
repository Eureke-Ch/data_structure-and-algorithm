// 用来求解任意两点之间的最短路：复杂度为O(n^3)，适用于任何图，不管有向无向，边权正负，但是要求最短路必须存在（即不能有负环）；
// Floyd算法的本质就是动态规划算法，通过不断的引入新节点，从而更新各节点之间的最短距离；最简单写法就是三层循环加一个三维向量，如下：
#include "bits/stdc++.h"
using namespace std;
void floyd(int n, vector<vector<vector<int>>> &dis){
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            for(int k = 0;k < n;++k){
                dis[i][j][k] = min(dis[i-1][j][k], dis[i-1][j][i]+dis[i-1][i][k]);
            }
        }
    }
}

void floyd_zip(int n, vector<vector<int>> &dis){
    // 动态规划中常用的记忆数组维度压缩，可以发现dis数组的第一维是不必要的，因此可以写成如下形式：
    vector<vector<int>> dis;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            for(int k = 0;k < n;++k){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
}