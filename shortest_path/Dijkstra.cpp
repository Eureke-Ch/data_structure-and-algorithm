// Dijkstra算法也是基于松弛操作的算法，能够求解非负权图的单源最短路径，1956年发现，1959年首次公布；
// 算法的思路：将所有点划分成两个集合，分别是已确定最短路的点集(记为S)和未确定最短路的点集(记为T)，接着每次从T中寻找距离最短的点加入S，然后对刚刚加入S的节点的出边执行松弛操作，直到T集合为空；
// 该算法的时间复杂度取决于集合T的数据结构，如果是暴力遍历的方式，挑选距离最短的点的总时间复杂度是O(n^2)，松弛操作的总时间复杂度是O(m)，因此总的时间复杂度是O(n^2+m)；如果是采用优先队列的方式，由于存在重复放入的问题，因此优先队列中的元素个数是m个，每次取最小值以及插入新值的时间复杂度都是O(log(m))，因此总的时间复杂度为O(mlog(m))；
// 看似优先队列的实现方式更优，但是这需要分情况讨论，对于稀疏图，m和n的值比较接近的时候，优先队列的实现更优；对于稠密图，m远大于n的时候，暴力搜索的实现方式更优；下面分别给出暴力和优先队列的实现方式：

// 暴力实现：
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9;
struct edge{
    int v, w;
};
vector<edge> e[maxn];
int dis[maxn], vis[maxn];

void dijstra(int n, int s){
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    for(int i = 0;i < n;++i){
        int u = 0;int cur = 1e9;
        for(int j = 0;j < n;++j){
            if(!vis[j] && dis[j] < cur){
                u = j, cur = dis[j];
            }
        }
        vis[u] = 1;
        for(auto ed : e[u]){
            int v = ed.v, w = ed.w;
            dis[v] = min(dis[v], dis[u]+w);
        }
    }
}


// 优先队列实现
struct edge{
    int v, w;
};

struct node
{
    int dis, v;
    bool operator > (const node& a) const {return  dis > a.dis;}
};
vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int n, int s){
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    q.push({0, s});
    while(q.size()){
        int u = q.top().v;
        if(vis[u])continue;
        vis[u] = 1;
        for(auto ed : e[u]){
            int v = ed.v, w = ed.w;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                q.push({dis[v], v});
            }
        }
    }
}


