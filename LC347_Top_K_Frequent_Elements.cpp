#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

class Solution {
public:
    // custom comparator to order keys by their value
    struct CompareSecond {
        bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2) const{
            return p1.second < p2.second;
        }
    };

    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> output;

        // capture frequency of each key in hash table, O(N)
        std::unordered_map<int,int> hmp; // key: num value, value: frequency
        for (auto n : nums){
            if (hmp.count(n) == 0){
                hmp.insert(std::make_pair(n,1));
            }
            else{
                hmp[n] += 1;
            }
        }

        // make a priority queue from hash map, sort keys by value (using custom comparator), O(NlogN)
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int, int>>, CompareSecond> pq;
        for (auto i : hmp){
            pq.push(i);
        }

        // add k most frequent elements from priority queue to output vector, O(KlogN)
        for (int i = 0; i < k; ++i){
            output.push_back(pq.top().first);
            pq.pop();
        }

        return output;

    }
};


int main(){
    std::vector nums{1,1,1,2,2,3};
    int k = 2;

    Solution s;
    for (auto itr : s.topKFrequent(nums,k)){
        std::cout << itr << std::endl;
    }

}