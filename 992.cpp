class Solution {
public:
    int max_arrays(vector<int>& A,int K){
        int result = 0;
        int left = 0,right  = 0;
        unordered_map<int,int> wind;
        int lenght = A.size();
        while(right < lenght){
            wind[A[right]] += 1;
            while(wind.size() > K){
                wind[A[left]] -= 1;
                if(wind[A[left]] == 0){
                    wind.erase(A[left]);
                }
                left += 1;
            }
            result += (++right- left);
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return max_arrays(A,K) - max_arrays(A,K-1);
    }
};