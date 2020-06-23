class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1;
        string res = "";
        int sum = 0;
        while(m >= 0 || n >= 0 || sum == 1){
            if(m >= 0) sum += a[m--] - '0';
            if(n >= 0) sum += b[n--] - '0';
            res.insert(0,1,char(sum % 2 + '0'));
            sum /= 2;
        }
        return res;
    }
};
