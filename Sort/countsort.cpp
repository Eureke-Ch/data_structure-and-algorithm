#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countsort(vector<int> num){
    int max_num = 0;
    for(auto i : num){
        max_num =  max(max_num, i);
    }
    vector<int> rec(max_num+1, 0);
    vector<int> ans;
    for(auto i : num){
        rec[i] += 1;
    }
    for(int i = 0;i <= max_num;++i){
        if(rec[i]){
            for(int j = 0;j < rec[i];++j){
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main(){
    vector<int> num {1,2,6,4,3,52,21,54,32,345};
    vector<int> ans = countsort(num);
    for(auto i : ans){
        cout<<i<<"  ";
    }
    cout<<endl;
}