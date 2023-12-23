/*

Notes:
- Base case:
    - node in decision tree reaches n
- Use bottom up DP approach. Start at base case and work way up.
- Follows Fibonacci sequence
*/

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        // init vars for onestep and twostep (two possible choices at each step)
        int onestep = 1, twostep = 1;

        for (int i = 0; i < n-1; ++i){
            int tmp = onestep;
            onestep += twostep;
            twostep = tmp;
        }
        return onestep;
    }
};


int main(){
    Solution s;
    std::cout << s.climbStairs(3) << std::endl;
}