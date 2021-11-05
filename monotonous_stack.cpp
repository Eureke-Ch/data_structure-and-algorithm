// 1、求取数组中滑动窗口内的最大值：数组的长度为n，滑动窗口的长度为k
// 本质就是维持一个单调栈
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

vector<int> get_max_num_of_vector(vector<int> nums, int k){
    vector<int> ans;
    deque<int> rec;
    for(int i = 0;i < k;++i){
        if(rec.empty()){
            rec.push_back(i);
        }else if(nums[rec.back()] > nums[i]){
            rec.push_back(i);
        }else{
            while(!rec.empty() && nums[rec.back()] <= nums[i]){
                rec.pop_back();
            }
            rec.push_back(i);
        }
    }
    ans.push_back(nums[rec.front()]);
    for(int i = k;i < nums.size();++i){
        if(rec.empty()){
            rec.push_back(i);
        }else if(nums[rec.back()] > nums[i]){
            rec.push_back(i);
        }else{
            while(!rec.empty() && nums[rec.back()] <= nums[i]){
                rec.pop_back();
            }
            rec.push_back(i);
        }
        while(rec.front() < i-k+1){
            rec.pop_front();
        }
        ans.push_back(nums[rec.front()]);

    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,4,5,3,2,7,5,3,6,36,2,3,12,1,43,3};
    vector<int> max_num = get_max_num_of_vector(nums,3);
    for(auto i : max_num){
        cout<<i<<"  ";
    }
}

