#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    int cas = 1;
    while(n--){
        int m;
        cin>>m;
        vector<int> book;
        vector<int> alex, bob;
        for(int i = 0;i < m;++i){
            int cur;
            cin>>cur;
            book.push_back(cur);
            if(cur%2 == 0){
                bob.push_back(cur);
            }else{
                alex.push_back(cur);
            }
        }
        sort(alex.begin(), alex.end());
        sort(bob.begin(), bob.end(), [&](int &a, int &b){return a > b;});
        int pa = 0, pb = 0;
        for(int i = 0;i < m;++i){
            if(book[i]%2 == 0){
                book[i] = bob[pb];
                pb++;
            }else{
                book[i] = alex[pa];
                pa++;
            }
        }
        cout<<"Case #"<<cas<<": ";
        for(int i = 0;i < m;++i){
            cout<<book[i]<<" ";
        }
        cout<<endl;
        cas++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

