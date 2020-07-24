class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};

//条件改成1 < x < N
bool divisorGame(int N){
    return (N & (N - 1) || -~N % 3) && ~N & 1;
}
