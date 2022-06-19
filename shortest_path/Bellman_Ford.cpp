// Bellman_Ford算法是一种基于松弛操作的最短路算法，可以求出有负权的图的最短路，并且能够对是否存在最短路进行判断（即存在负环）；
// 松弛操作：对每一个边(u, v)，都有dis(v) = min(dis(v), dis(u)+w(u,v));每一次循环，Bellman_Ford都尝试对图中的所有边进行松弛，一共有m条边，每次循环在最短路存在情况下都会使最短路的边数加一，而最短路的边数最多是n-1，因此最多循环n-1次，所以算法的时间复杂度是O(mn)；
// 对于存在负环的情况，第n轮将依然存在能够松弛的边，基于此能够检测负环是否存在；
// 实际使用该算法的时候，很多松弛都是没必要的，只有上一轮循环中成功松弛的边的节点所对应的边才有可能松弛，因此可以用队列来维护引起松弛的节点，从而降低没必要的松弛操作，队列优化的Bellman_Ford算法也称为SPFA(Shortest Path Faster Algorithm);
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9;
struct edge
{
    int v, w;
};
vector<edge> e[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q;
bool spfa(int n, int s){
    memset(dis, 63, sizeof dis);
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while(q.empty()){
        int u = q.front();
        q.pop(), vis[u] = 0;
        for(auto ed : e[u]){
            int v = ed.v, w = ed.w;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                cnt[v] += 1;
                if(cnt[v] > n)return false;
                if(!vis[v])q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}

