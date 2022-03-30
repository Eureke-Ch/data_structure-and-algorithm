// 题目见：https://uoj.ac/problem/15
// 石头剪刀布是常见的猜拳游戏:石头胜剪刀,剪刀胜布,布胜石头。如果两个人出拳一 样，则不分胜负。在《生活大爆炸》第二季第 8 集中出现了一种石头剪刀布的升级版游戏。
// 升级版游戏在传统的石头剪刀布游戏的基础上,增加了两个新手势:
// 斯波克:《星际迷航》主角之一。
// 蜥蜴人:《星际迷航》中的反面角色。
// 这五种手势的胜负关系如表一所示,表中列出的是甲对乙的游戏结果。

// 甲\乙	剪刀	石头	布	蜥蜴人	斯波克
// 剪刀	    平	输	赢	赢	输
// 石头	    ×	平	输	赢	输
// 布	    ×	×	平	输	赢
// 蜥蜴人   ×	×	×	平	赢
// 斯波克	×	×	×	×	平
// 现在,小 A 和小 B 尝试玩这种升级版的猜拳游戏。已知他们的出拳都是有周期性规律的，但周期长度不一定相等。例如：如果小A以“石头-布-石头-剪刀-蜥蜴人-斯波克”长度为 6 的周期出拳,那么他的出拳序列就是“石头-布-石头-剪刀-蜥蜴人-斯波克-石头-布-石头-剪刀-蜥蜴人-斯波克-......”,而如果小B以“剪刀-石头-布-斯波克-蜥蜴人”长度为 5 的周期出拳,那么他出拳的序列就是“剪刀-石头-布-斯波克-蜥蜴人-剪刀-石头-布-斯波克-蜥蜴人-......”

// 已知小 A 和小 B 一共进行 N 次猜拳。每一次赢的人得 1 分，输的得 0 分；平局两人都得 0 分。现请你统计 N 次猜拳结束之后两人的得分。

// 输入格式
// 第一行包含三个整数：N,NA,NB,分别表示共进行 N 次猜拳、小 A 出拳的周期长度，小 B 出拳的周期长度。数与数之间以一个空格分隔。

// 第二行包含 NA 个整数,表示小 A 出拳的规律,第三行包含 NB 个整数,表示小 B 出拳的规律。其中，0 表示“剪刀”，1 表示“石头”，2 表示“布”，3 表示“蜥蜴人”，4 表示“斯波克”。数与数之间以一个空格分隔。

// 输出格式
// 输出一行，包含两个整数，以一个空格分隔，分别表示小 A、小 B 的得分。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    vector<vector<int>> table(5, vector<int>(5, 1));
    for(int i = 0;i < 5;++i){
        table[i][i] = 0;
    }
    table[0][1] = -1;
    table[0][4] = -1;
    table[1][2] = -1;
    table[1][4] = -1;
    table[2][0] = -1;
    table[2][3] = -1;
    table[3][0] = -1;
    table[3][1] = -1;
    table[4][2] = -1;
    table[4][3] = -1;
    int n, t1, t2;
    cin>>n>>t1>>t2;
    vector<int> a(t1+1, 0);
    vector<int> b(t2+1, 0);
    for(int i = 0;i < t1;++i){
        cin>>a[i];
    }
    for(int i = 0;i < t2;++i){
        cin>>b[i];
    }
    int as = 0, bs = 0;
    for(int i = 0;i < n;++i){
        if(table[a[i%t1]][b[i%t2]] == 1){
            as++;
        }else if(table[a[i%t1]][b[i%t2]] == -1){
            bs++;
        }
    }
    cout<<as<<" "<<bs<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

