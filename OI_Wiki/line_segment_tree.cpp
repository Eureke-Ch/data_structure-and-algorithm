// 线段树模板，对应的题目是https://www.luogu.com.cn/problem/P3372
// Note：题目的下标是从1开始的，以及区间求和的结果超过了int的范围；
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
vector<ll> d;
vector<int> b;
void build(int s, int t, int p){
    if(s == t){
        d[p] = a[s];
        return ;
    }
    int m = s + ((t-s)>>1);
    build(s, m, p*2+1);
    build(m+1, t, p*2+2);
    d[p] = d[p*2+1]+d[p*2+2];
}
void update(int l, int r, int c, int s, int t, int p){
    if(l <= s && t <= r){
        d[p] += (t-s+1)*c;
        b[p] += c;
        return ;
    }
    int m = s + ((t-s)>>1);
    if(b[p] && s != t){
        b[p*2+1] += b[p];
        b[p*2+2] += b[p];
        d[p*2+1] += (m-s+1)*b[p];
        d[p*2+2] += (t-m)*b[p];
        b[p] = 0;
    }
    if(l <= m)update(l, r, c, s, m, p*2+1);
    if(r > m)update(l, r, c, m+1, t, p*2+2);
    d[p] = d[p*2+1]+d[p*2+2];
}
ll getsum(int l, int r, int s, int t, int p){
    if(l <= s && t <= r){
        return d[p];
    }
    int m = s+((t-s)>>1);
    if(b[p]){
        d[p*2+1] += (m-s+1)*b[p];
        d[p*2+2] += (t-m)*b[p];
        b[p*2+1] += b[p];
        b[p*2+2] += b[p];
        b[p] = 0;
    }
    ll sum = 0;
    if(l <= m)sum = getsum(l, r, s, m, p*2+1);
    if(r > m)sum += getsum(l, r, m+1, t, p*2+2);
    return sum;
}
void solve()
{
    int n, m;
    cin>>n>>m;
    a = vector<int>(n, 0);
    for(int i = 0;i < n;++i){
        int cur;
        cin>>cur;
        a[i] = cur;
    }
    d = vector<ll>(4*n, 0);
    b = vector<int>(4*n, 0);
    build(0, n-1, 0);
    while(m--){
        int type;
        cin>>type;
        if(type == 1){
            int s, t, c;
            cin>>s>>t>>c;
            update(s-1, t-1, c, 0, n-1, 0);
        }else{
            int l, r;
            cin>>l>>r;
            ll ans = getsum(l-1, r-1, 0, n-1, 0);
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

