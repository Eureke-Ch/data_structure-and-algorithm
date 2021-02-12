class KthLargest {
public:
    vector<int> Nums;
    int K;
    KthLargest(int k, vector<int>& nums) {
        if(nums.size() > 1){
            Nums.push_back(nums[0]);
            for(int i = 1;i < nums.size();i++){
                for(auto j = Nums.begin(); j != Nums.end();++j){
                    if(nums[i] < *j){
                        Nums.insert(j,nums[i]);
                        break;
                    }else if(j == Nums.end() - 1){
                        Nums.push_back(nums[i]);
                        break;
                    }
                    else if(nums[i] >= *j && nums[i] < *(j+1)){
                        Nums.insert(j+1, nums[i]);
                        break;
                    }
                }
            }
        }
        else{
            Nums = nums;
        }
        K = k;       
    }
    
    int add(int val) {
        if(Nums.size() == 0){
            Nums.push_back(val);
            return Nums[Nums.size() - K];
        }
        for(auto i = Nums.begin();i != Nums.end();++i){
            if(val < *i){
                Nums.insert(i,val);
                break;
            }else if(i == Nums.end() -1){
                Nums.push_back(val);
                break;
            }
        }
        return Nums[Nums.size() - K];
    }
};
