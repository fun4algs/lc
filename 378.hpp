//time complexity:O(nlogn*logM)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int l = m[0][0], r = m.back().back();
        int n = m.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 0; i < n; ++i){
                cnt += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
            }
            if(cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

//time complexity:O(nlogM)
int kthSmallest(vector<vector<int>>&m, int k){
    int l = m[0][0], r = m.back().back();
    int n = m.size();
    while(l < r){
        int mid = l + (r - l) / 2;
        int cnt = helper(m, mid);
        if(cnt < k) l = mid + 1;
        else r = mid;
    }
    return l;
}

int helper(vector<vector<int>>&m, int tar){
    int n = m.size();
    int i = n - 1, j = 0;
    int cnt = 0;
    while(i >= 0 && j < n){
        if(m[i][j] <= tar){
            cnt += i + 1;
            ++j;
        }
        else --i;
    }
    return cnt;
}
