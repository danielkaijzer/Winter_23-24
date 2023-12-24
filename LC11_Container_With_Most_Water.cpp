#include <iostream>
#include <vector>
#include <iostream>

// Use two-pointer technique

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        // int start =0, end = height.size()-1;

        int max_water = 0;

        // brute force
        for (int i = 0; i < height.size(); ++i){
            for (int j = i; j < height.size(); ++j){
                // if new max area found, update max_water
                int cur_area = std::min(height[i],height[j]) * (j-i);
                if (max_water < cur_area){
                    max_water = cur_area;
                }

            }
        }
        return max_water;
    }
};

int main(){
    std::vector<int> h{1,8,6,2,5,4,8,3,7};
    Solution s;

    std::cout << s.maxArea(h) << std::endl;

}