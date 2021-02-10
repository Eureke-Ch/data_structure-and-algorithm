class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_new(26,0);
        for(int i = 0;i < s1.size();++i){
            s1_new[s1[i] - 'a']++;
        }
        int left = 0,right = 0;
        while(right < s2.size()){
            s1_new[s2[right] - 'a'] --;
            while(s1_new[s2[right] - 'a'] < 0){
                s1_new[s2[left] - 'a'] ++;
                left ++;
            }
            if(right - left +1 == s1.size()) return true;
            right ++;
        }
        return false;
    }
};