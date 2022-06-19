#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
void mcout(int cas){
    cout<<"Case #"<<cas<<": ";
}
ll p, q;
void tree_get(ll n){
    if(n == 1){
        p = 1;
        q = 1;
        return ;
    }
    tree_get((n >> 1));
    if(n>>1 == 0){
        q += p;
    }else{
        p += q;
    }
}
ll tree_slove(ll p, ll q){
    if(p == 1 && q == 1)return 1;
    if(p > q){
        return tree_slove(p-q, q)<<1|1;
    }else{
        return tree_slove(p, q-p)<<1;
    }
}
void solve()
{
    int n;
    cin>>n;
    int cas = 1;
    while(n--){
        mcout(cas++);
        int op;
        cin>>op;
        if(op == 1){
            ll n;
            cin>>n;
            tree_get(n);
            cout<<p<<" "<<q<<" "<<endl;
        }else{
            cin>>p>>q;
            cout<<tree_slove(p, q)<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

