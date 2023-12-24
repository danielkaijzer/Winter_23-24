/*


Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.


*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int unique = 1; // can start at 1 since we know first value is unique

        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] != nums[i-1]){
                nums[unique] = nums[i];
                unique++;
            }
        }

        return unique;
    }
};

int main(){
    std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    Solution s;
    std::cout << s.removeDuplicates(nums) << std::endl;

    for (auto itr : nums){
        std::cout << itr << " ";
    }
    std::cout << std::endl;
}