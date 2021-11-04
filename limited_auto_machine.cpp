#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//char type 
//0 ' '
//1 0~9
//2 .
//3 + -
//4 e E
//5 illegal
 

int gettype(char c){
    if(c == ' '){
        return 0;
    }
    if(c <= '9' && c >= '0'){
        return 1;
    }
    if(c == '.'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 3;
    }
    if(c == 'e' || c == 'E'){
        return 4;
    }
    return 5;
}

enum state {init, sign, number, point_with_num, point_without_num, fraction, exp, exp_sign, exp_int, end_s};
unordered_map<state, unordered_map<int, state>> transfer{
    {init, {{0, init},{1, number}, {2, point_without_num}, {3, sign}}},
    {sign, {{1, number},{2, point_without_num}}},
    {number, {{0, end_s}, {1, number}, {2, point_with_num}, {4, exp}}},
    {point_with_num, {{0, end_s}, {1, fraction}, {4, exp}}},
    {point_without_num, {{1, fraction}}},
    {fraction, {{1, fraction}, {0, end_s}, {4, exp}}},
    {exp, {{1, exp_int}, {3, exp_sign}}},
    {exp_sign, {{1, exp_int}}},
    {exp_int, {{1, exp_int}, {0, end_s}}},
    {end_s, {{0, end_s}}}
};


int isnumber(string s){
    state st = init;
    for(int i = 0;i < s.size();++i){
        int tp = gettype(s[i]);
        if(transfer[st].find(tp) == transfer[st].end()){
            return false;
        }else{
            st = transfer[st][tp];
        }
    }
    if(st == number || st == point_with_num || st == fraction || st == exp_int || st == end_s){
        return true;
    }
    return false;
}


int main(){
    string s = "  -1.e1  ";
    if(isnumber(s)){
        cout<<"Yes!"<<endl;
    }
}