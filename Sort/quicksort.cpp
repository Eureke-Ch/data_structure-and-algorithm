#include "stdlib.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> quicksort(vector<int> num){
    vector<int> F;
    vector<int> B;
    if(num.size() <= 1){
        return num;
    }
    int com = num[0];
    for(int i = 1;i < num.size();++i){
        if(num[i] < com){
            F.push_back(num[i]);
        }
        else{
            B.push_back(num[i]);
        }
    }
    F = quicksort(F);
    B = quicksort(B);
    F.push_back(com);
    for(auto i : B){
        F.push_back(i);
    }
    return F;
}

int main(){
    vector<int> num {1,2,6,4,3,52,21,54,32,345};
    vector<int> ans = quicksort(num);
    for(auto i : ans){
        cout<<i<<"  ";
    }
    cout<<endl;
}