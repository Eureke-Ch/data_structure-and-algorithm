// 枚举问题中的熄灯问题
// 问题描述：有一个由按钮组成的矩阵，其中每行有6个按钮，共5行。每个按钮的位置上有一盏灯。当按下一个按钮后，该按钮以及周围位置(上边、下边、左边、右边)的灯都会改变一次。即，如果灯原来是点亮的，就会被熄灭；如果灯原来是熄灭的，则会被点亮。在矩阵角上的按钮改变3盏灯的状态；在矩阵边上的按钮改变4盏灯的状态；其他的按钮改变5盏灯的状态。
// 输入：5行组成，每一行包括6个数字（0或1）。相邻两个数字之间用单个空格隔开。0表示灯的初始状态是熄灭的，1表示灯的初始状态是点亮的。
// 输出：5行组成，每一行包括6个数字（0或1）。相邻两个数字之间用单个空格隔开。其中的1表示需要把对应的按钮按下，0则表示不需要按对应的按钮。
// 解决思路：如果直接枚举全部的可能，则是2的30次方，会超时；思考如何枚举局部内容，由于能改变第一行灯状态的只有第二行和第一行，因此在确定第一行按钮的状态后，为了使第一行的灯全部熄灭，则只能按第二行对应位置的按钮，因此枚举的状态为2的6次方

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int state[5][6];
    int press[5][6];
    memset(state, 0, sizeof state);
    for(int i = 0;i < 5;++i){
        for(int j = 0;j < 6;++j){
            cin>>state[i][j];
        }
    }
    for(int i = 0;i < (1<<6);++i){
        memset(press, 0, sizeof press);
        int mask = 1;
        for(int m = 5;m >= 0;--m){
            press[0][m] = i&mask ? 1 : 0;
            mask = mask<<1;
        }
        int state_new[5][6];
        memcpy(state_new, state, sizeof state);
        for(int j = 0;j < 5;++j){
            for(int k = 0;k < 6;++k){
                if(press[j][k]){
                    if(k > 0)state_new[j][k-1] = state_new[j][k-1] ? 0 : 1;
                    if(k < 5)state_new[j][k+1] = state_new[j][k+1] ? 0 : 1;
                    if(j < 4)state_new[j+1][k] = state_new[j+1][k] ? 0 : 1;
                    state_new[j][k] = state_new[j][k] ? 0 : 1;
                }
            }
            for(int k = 0;k < 6;++k){
                if(j < 4 && state_new[j][k]){
                    press[j+1][k] = 1;
                }
            }
        }
        int flag = 0;
        for(int j = 0;j < 6;++j){
            if(state_new[4][j] == 1){
                flag = 1;
                break;
            }
        }
        if(!flag){
            for(int j = 0;j < 5;++j){
                for(int k = 0;k < 6;++k){
                    cout<<press[j][k]<<" ";
                }
                cout<<endl;
            }
            return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

