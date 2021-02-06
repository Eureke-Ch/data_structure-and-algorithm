#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lenght = cardPoints.size()-k;
        vector<int> sum;
        sum.push_back(cardPoints[0]);
        for(int i = 1; i<cardPoints.size();i++){
            sum.push_back(sum[i-1]+cardPoints[i]);
        }
        if(k == cardPoints.size()){
            return sum[k-1];
        }
        int maxnum = sum[lenght-1];
        for(int i = 1; i<k+1; i++){
            maxnum = min(maxnum,sum[i+lenght-1]-sum[i-1]);
        }
        return sum[sum.size()-1]-maxnum;
    }
};
int main(){
    Solution a;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(4);
    b.push_back(2);
    int k = 2;
    int result = a.maxScore(b,k);
    cout<<result;
    // printf("%d",result);
    return 0;
}