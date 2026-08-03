class Solution {
public:
    const int MOD = 1337;

    
    int power(int a, int b) {
        int result = 1;
        a %= MOD;

        while (b > 0) {
            result = (result * a) % MOD;
            b--;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {

        int ans = 1;

        for (int digit : b) {
            ans = (power(ans, 10) * power(a, digit)) % MOD;
        }

        return ans;
    }
};