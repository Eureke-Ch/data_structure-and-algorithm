class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        vector<int> ans;
        for(int i = 0; i < nums.size();++i){
            result[nums[i]-1] ++;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(result[i] == 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};