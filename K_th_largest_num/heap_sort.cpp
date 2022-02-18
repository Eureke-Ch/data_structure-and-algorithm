#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void maxheap(vector<int> &nums, int pos, int len){
        int left = 2*pos+1 <= len ? 2*pos+1 : len, right = 2*pos+2 <= len ? 2*pos+2 : len;
        if(nums[left] < nums[right]){
            swap(left, right);
        }
        if(nums[pos] < nums[left]){
            swap(nums[pos], nums[left]);
            if(left < (len-1)/2){
                maxheap(nums, left, len);
            }
        }
    }
    void build_heap(vector<int> &nums){
        int n = nums.size()-1;
        int start = (n-1)/2;
        while(start >= 0){
            maxheap(nums, start, n);
            start--;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_heap(nums);
        int n = nums.size()-1;
        k--;
        while(k--){
            swap(nums[0], nums[n]);
            n--;
            maxheap(nums, 0, n);
        }
        return nums[0];
    }
};