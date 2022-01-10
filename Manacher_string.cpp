// 求解回文字符串常用的马拉车算法，本质就是利用回文字符串的对称性
// 马拉车算法首先需要将字符串s的长度转化为奇数，这样回文中心就一定是奇数了，同时为了处理时的方便，新构造字符串的首尾同时加上不会出现字符串中的字符（$, @等)
// 1. 构造辅助数组p，p[i]代表以i为回文中心的最长回文字符串中i右边的字符个数；id代表对应当前到达最远的位置mx的回文字符串的回文中心；mx当前到达的最远位置；pos最长回文字符串对应的下标；
// 2. 对于小于mx的回文中心i，其对应的p[i]等于关于id对称的mirror_id的p[mirror_id]和mx-id中的较小值；
// 3. 同时不停更新mx, id, pos即可；
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string malache = "$";
        for(auto i : s){
            malache += '#';
            malache += i;
        }
        malache += '#';
        malache += '@';
        int n = malache.size();
        vector<int> rec(n, 0);
        int id = 0, mx = 0;
        int max_len_pos = 0;
        for(int i = 1;i < n-1;++i){
            if(i < mx){
                rec[i] = min(mx-i, rec[2*id-i]);
            }
            while(malache[i+rec[i]+1] == malache[i-rec[i]-1]){
                rec[i] += 1;
            }
            if(i + rec[i] > mx){
                mx = i+rec[i];
                id = i;
            }
            if(rec[i] > rec[max_len_pos]){
                max_len_pos = i;
            }
        }
        return s.substr((max_len_pos-rec[max_len_pos])/2, max(1, rec[max_len_pos]));

    }
};