class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1){return 1;}
        int max_num = 1;
        int letf_less = 0;
        int cur_num = 1;
        int equal = 1;
        for(int i = 0; i < arr.size()-1; ++i){
            if(arr[i] == arr[i+1]){
                equal = 1;
                cur_num  = 1;
            }
            else if(equal == 1){
                cur_num += 1;
                if(arr[i] < arr[i+1]){
                    equal = 0;
                    letf_less = 1;
                    max_num = max(cur_num,max_num);
                }
                if(arr[i] > arr[i+1]){
                    equal = 0;
                    letf_less = 0;
                    max_num = max(cur_num,max_num);
                }
            }
            else if(arr[i] > arr[i+1] && letf_less == 1){
                cur_num += 1;
                letf_less = 0;
                max_num = max(cur_num,max_num);
            }
            else if(arr[i] > arr[i+1] && letf_less == 0){
                letf_less = 0;
                cur_num = 2;
            }
            else if(arr[i] < arr[i+1] && letf_less == 0){
                cur_num += 1;
                letf_less = 1;
                max_num = max(cur_num,max_num);
            }
            else{
                cur_num = 2;
                letf_less = 1;
            }
        }
        return max_num;
    }
};