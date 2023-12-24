#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq;


        // O(nlogn), add all nums into max heap
        for (auto n : nums){
            pq.push(n);
        }

        // start ... k ... end

        // so we need to deleteMax from our maxheap end-k times 

        // O(klogn), remove max elements until we reach k'th element
        for (int i = 0; i < k-1; i++){
            pq.pop(); // 
        }
        return pq.top(); // kth largest element
    }
};

int main(){
    std::vector<int> n{3,2,1,5,6,4};

    Solution s;

    std::cout << s.findKthLargest(n,2) << std::endl; // 5

}