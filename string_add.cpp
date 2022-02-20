#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0;
        string ans = "";
        int n = num1.size();
        int m = num2.size();
        if(n > m){
            swap(n, m);
            swap(num1, num2);
        }
        for(int i = 0;i < n;++i){
            int sum = num1[n-i-1]+num2[m-i-1]-'0'-'0'+c;
            ans += (sum%10+'0');
            c = sum/10;
        }
        for(int i = n;i < m;++i){
            int sum = num2[m-i-1]+c-'0';
            ans += (sum%10+'0');
            c = sum/10;
        }
        if(c){
            ans += (c+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};