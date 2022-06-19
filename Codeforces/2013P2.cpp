// 抛物线运动，用到简单的物理和三角函数知识；需要注意的点是防止asin函数的溢出；
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)
void solve()
{
    int n;
    cin>>n;
    int i = 1;
    while(n--){
        double v, d;
        cin>>v>>d;
        double sin20 = d*9.8/(v*v);
        if(sin20 > 1)sin20 = 1;
        double ans = asin(sin20)*90.0/PI;
        cout<< fixed << setprecision(10);
        cout<<"Case #"<<i<<": "<<ans<<endl;
        i++;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}


