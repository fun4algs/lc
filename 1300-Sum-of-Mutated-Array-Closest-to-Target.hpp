#include<cmath>
#include<vector>
using namespace std;

//time complexity:O(NlogM)
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        int sum = 0,max_num = 1;
        for(int a : A){ 
            if(max_num < a) max_num = a; 
            sum += a;
        }
        if(target >= sum) return max_num;

        int l = 1,r = max_num;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(helper(mid,A) < target) l = mid + 1;
            else r = mid;
        }
        if(abs(helper(l - 1,A) - target) <= abs(helper(l,A) - target))
            return l - 1;
        else return l;
    }

    int helper(int i,vector<int>&A){
        int sum = 0;
        for(int a:A) sum += a > i?i : a;
        return sum;
    }
};
