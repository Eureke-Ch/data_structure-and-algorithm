#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int quick_part(int left, int right, vector<int> &nums, int k){
        random_swap(left, right, nums);
        int pre = left+1, next = right;
        while(pre <= next){
            if(nums[pre] >= nums[left]){
                swap(nums[pre], nums[next]);
                next--;
            }else{
                pre++;
            }
        }
        if(right-next == k-1){
            return nums[left];
        }else if(right-next < k-1){
            return quick_part(left+1, next, nums, k-(right-next+1));
        }else{
            return quick_part(next+1, right, nums, k);
        }
        
    }
    void random_swap(int left, int right, vector<int> &nums){
        int rn = rand()%(right-left+1)+left;
        swap(nums[left], nums[rn]);
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quick_part(0, nums.size()-1, nums, k);
    }
};