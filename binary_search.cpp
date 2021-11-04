#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> nums, int target){
    int l = 0, r = nums.size()-1;
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            l = mid + 1;
        }else{
            r = mid -1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums {1, 2, 3, 4, 6, 21, 32, 52, 54, 345};
    int ans = binary_search(nums, 22);
    cout<<ans<<endl; 
}