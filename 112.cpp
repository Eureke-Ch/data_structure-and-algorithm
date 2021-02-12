class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> n_row(1,1);
        if(rowIndex == 0){
            return n_row;
        }
        vector<int> n_1_row;
        for(int i = 1;i < rowIndex+1; ++i){
            n_1_row = n_row;
            n_row.clear();
            n_row.push_back(1);
            for(int j = 0;j < i-1;++j){
                n_row.push_back(n_1_row[j] + n_1_row[j+1]);
            }
            n_row.push_back(1);
        }
        return n_row;
    }
};