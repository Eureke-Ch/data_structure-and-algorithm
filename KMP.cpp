#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> getnext(string s){
    int len_s = s.size();
    vector<int> next(len_s, 0);
    if(len_s < 2){
        return next;
    }
    if(s[1] == s[0]){
        next[1] = 1;
    }
    int j = 2, k = next[1];
    while(j < len_s){
        if(s[j] == s[k]){
            next[j] = k+1;
            j++;
            k = k+1;
        }else{
            if(k == 0){
                next[j] = 0;
                j++;
                k = next[j-1];
            }else{
                k = next[k-1];
            }
        }
    }
    return next;
}

int string_match(vector<int> next, string subs, string s){
    int p = 0, subp = 0;
    int len_s = s.size(), len_subs = subs.size();
    while(p < len_s && subp < len_subs){
        if(s[p] == subs[subp]){
            p++;
            subp++;
        }else{
            if(subp == 0){
                p++;
            }else{
                subp = next[subp-1];
            }
        }
    }
    if(subp == len_subs){
        return p-len_subs;
    }
    return -1;
}


int main(){
    string s = "jfdkfyhhdfhhhdehfajshdfhhhhhhhhfdhagsdfheh";
    string subs = "hhdfhhhd";
    vector<int> next = getnext(subs);
    // for(auto i : next){
    //     cout<<i<<"  ";
    // }
    // cout<<endl;
    int pos = string_match(next, subs, s);
    cout<<pos<<endl;
}