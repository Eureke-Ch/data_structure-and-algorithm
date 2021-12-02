//顾名思义就是一棵像字典一样的数，主要分成插入insert和查询search操作，以下题为例：
// 给你n个名字串，然后进行m次点名，每次你需要回答“名字不存在”、“第一次点到这个名字”、“已经点过这个名字”之一。
#include <vector> 
#include <string>
#include <iostream>
using namespace std;
int Trie[100005][26], cnt;
int exist[100005];
void insert(string name){
    int n = name.size();
    int p = 0;
    for(int i = 0;i < n;++i){
        int c = name[i]-'a';
        if(!Trie[p][c])Trie[p][c] = ++cnt;
        p = Trie[p][c];
    }
    exist[p] = 1;
}
int search(string name){
    int n = name.size();
    int p = 0;
    for(int i = 0;i < n;++i){
        int c = name[i] - 'a';
        if(!Trie[p][c]){
            return 0;
        }
        p = Trie[p][c];
    }
    if(exist[p] == 1){
        exist[p] = 2;
        return 1;
    }
    return exist[p];
}
vector<int> call_the_roll(vector<string> students, vector<string> name){
    vector<int> ans;
    for(auto i : students){
        insert(i);
    }
    for(auto i : name){
        ans.push_back(search(i));
    }
    return ans;
}

// int main(){
//     vector<int> ans;
//     vector<string> students{"a", "abc", "acd"};
//     vector<string> name{"a", "ab", "abc", "a", "abcd"};
//     ans = call_the_roll(students, name);
//     for(auto i : ans){
//         cout<<i;
//     }
//     return 0;
// }
