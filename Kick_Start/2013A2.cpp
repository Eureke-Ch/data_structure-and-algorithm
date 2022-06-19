#include <bits/stdc++.h>
using namespace std;
#define ll long long
void mcout(int cas){
    cout<<"Case #"<<cas<<": ";
}
void solve()
{
    int n;
    cin>>n;
    unordered_map<int , string> times_word;
    times_word[2] = "double";
    times_word[3] = "triple";
    times_word[4] = "quadruple";
    times_word[5] = "quintuple";
    times_word[6] = "sextuple";
    times_word[7] = "septuple";
    times_word[8] = "octuple";
    times_word[9] = "nonuple";
    times_word[10] = "decuple";
    vector<string> number_word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int cas = 1;
    while(n--){
        mcout(cas++);
        string number, split;
        cin>>number>>split;
        stringstream instr(split);
        int p = 0;
        int split_len = split.size();
        string temp;
        while(getline(instr, temp, '-')){
            int cur = stoi(temp);
            int rep = 1;
            for(int j = 0;j < cur;++j){
                if(j == cur-1 || number[p] != number[p+1]){
                    if(rep == 1)cout<<number_word[number[p]-'0']<<" ";
                    else if(rep > 10){
                        for(int k = 0;k < rep;++k){
                            cout<<number_word[number[p-rep+k+1]-'0']<<" ";
                        }
                    }else{
                        cout<<times_word[rep]<<" "<<number_word[number[p]-'0']<<" ";
                    }
                    rep = 1;
                }else{
                    rep++;
                }
                p++;
            }
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}

