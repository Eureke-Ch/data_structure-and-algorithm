#include <iostream>
#include <vector>
using namespace std;

bool check(int mid){
    return true;
}
// 二分一共可以分成三种类型分别是，分别是求取满足要求的值，满足要求的最小值，满足要求的最大值：
// 1.满足要求的值：
int binary_search(vector<int> nums, int target){
    int l = 0, r = nums.size()-1;
    int mid;
    while(l <= r){
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

// 2.满足要求的最小值：
int binary_search(vector<int> nums){
    int l = 0, r = nums.size()-1;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(check(l)){return l;}
    else return -1;
}

// 3.满足要求的最大值：
int binary_search(vector<int> nums){
    int l = 0, r = nums.size()-1;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        }else{
           r = mid - 1;
        }
    }
    if(check(l)){return l;}
    else return -1;
}






int main(){
    vector<int> nums {1, 2, 3, 4, 6, 21, 32, 52, 54, 345};
    int ans = binary_search(nums, 22);
    cout<<ans<<endl; 
}