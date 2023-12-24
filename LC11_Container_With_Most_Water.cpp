#include <iostream>
#include <vector>
#include <iostream>

// Use two-pointer technique

class Solution {
public:
    int maxArea(std::vector<int>& height) {

        int max_water = 0;
        int left = 0, right = height.size()-1;

        // O(n) since we only iterate through all elements once
        while(left < right){
            int lowest_pillar = std::min(height[left], height[right]);
            int cur_area = lowest_pillar * (right-left);

            max_water = std::max(max_water,cur_area);

            // shift pointer pointing to minimum because only a greater value can increase our area from here
            if (height[left] >= height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        
        return max_water;
    }
};

int main(){
    std::vector<int> h{1,8,6,2,5,4,8,3,7}; // 49
    Solution s;

    std::cout << s.maxArea(h) << std::endl;

}