class Solution {
public:

    int climbStairs(int n) {
        if (n<=2) {
            return n;
        }
        else {
            int a{1};
            int b{2};
            int current{3};

            while (current <= n){
                int temp = a;
                a = b;
                b += temp; 
                current++;
            }

            return b;
        }
    }
};