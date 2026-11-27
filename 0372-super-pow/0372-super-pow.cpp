
class Solution {
public:
    int mod = 1337;

    // Fast Modular Exponentiation
    int power(int a, int b) {
        int ans = 1;
        a %= mod;

        while (b > 0) {

            if (b % 2 == 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;
            b /= 2;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {

        int ans = 1;
        a %= mod;

        for (int digit : b) {

            ans = (power(ans, 10) * power(a, digit)) % mod;
        }

        return ans;
    }
};
