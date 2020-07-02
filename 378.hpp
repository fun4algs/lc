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
