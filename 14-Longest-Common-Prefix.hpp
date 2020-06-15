#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end(),[&](string& a,string& b){
            return a.size() < b.size();
        });
        string str = strs[0];

        int n = strs.size();
        for(string s : strs){
            while(s.substr(0,str.size()) != str)
                str.pop_back();
        }
        return str;
    }
};
