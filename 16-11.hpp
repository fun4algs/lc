class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) return {};
        if(shorter == longer) return {shorter * k};

        vector<int>res(k + 1);
        for(int i = 0; i <= k; ++i)
            res[i] = shorter * (k - i) + longer * i;
        return res;
    }
};
