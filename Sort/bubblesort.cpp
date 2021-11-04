#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int> &num){
    for(int i = 0;i < num.size();++i){
        for(int j = num.size()-1;j > 0;--j){
            int temp;
            if(num[j] < num[j-1]){
                temp = num[j-1];
                num[j-1] = num[j];
                num[j] = temp;
            }
        }
    }
}

int main(){
    vector<int> num {1,2,6,4,3,52,21,54,32,345};
    bubblesort(num);
    for(auto i : num){
        cout<<i<<"  ";
    }
    cout<<endl;
}