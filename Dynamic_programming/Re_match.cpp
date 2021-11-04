#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Re_match(string s, string p){
    vector<vector<int>> rec(s.size()+1, vector<int>(p.size()+1, 0));
    rec[0][0] = 1;
    for(int i = 0;i <= s.size();++i){
        for(int j = 1;j <= p.size();++j){
            if(p[j-1] ==  '*'){
                if(j-2 >= 0 && i-1 >= 0 && (p[j-2] == s[i-1] || p[j-2] == '.') && rec[i-1][j]){
                    rec[i][j] = 1;
                }
                if(j-2 >= 0 && rec[i][j-2]){
                    rec[i][j] = 1;
                }
            }
            if(i-1 >= 0 && (p[j-1] == '.' || s[i-1] == p[j-1]) && rec[i-1][j-1]){
                rec[i][j] = 1;
            }
        }
    }
    return rec[s.size()][p.size()];
}


int main(){
    string s = "abc";
    string p = "ab*b*c*bc";
    if(Re_match(s,p)){
        cout<<"Match success!"<<endl;
    }else{
        cout<<"Match fail!"<<endl;
    }
    return 1;

}