#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

class Solution {
public:
    /**
     * @brief 
     * 
     * @param times 
     * @param n = number of nodes
     * @param k = source node
     * @return int 
     */
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {

        int infinity = std::numeric_limits<int>::max();

        // make adj list that stores adj edges and distance
        // key: source node
        // value: a vector of adjacent edges, where an edge is a pair of values:
            // first value of edge: vector of pairs:
                // 1) destination node
                // 2) weight/distance of edge
            // second value of edge: if shortest path KNOWN, default to FALSE
        std::unordered_map<int,std::pair<std::vector<std::pair<int,int>> , int>> adjlist(n+1);

        // track total number of vertices given by graph (vector of travel times)
        int num_vertices = 0;

        for (auto t : times){
            // make adjacency list for source node
            adjlist[t.at(0)].first.push_back(std::make_pair(t.at(1), t.at(2)));

            // make tmp distance for all nodes in graph equal to infinity (for Dijkstra's)
            // if it doesn't have infinity yet, it means node not yet seen
            if (adjlist[t.at(0)].second != infinity){
                adjlist[t.at(0)].second = infinity; // make tmp dist INFINITY
                num_vertices++; // add new unique vertex to count total

            }
            if (adjlist[t.at(1)].second != infinity){
                adjlist[t.at(1)].second = infinity;
                num_vertices++; // add new unique vertex to count total
            }
        }

        // if vertices given by graph is not equal to n (the number of nodes we need to visit)
        // return error flag -1
        if (num_vertices != n){
            return -1;
        }

        // make a min heap that is sorted based off of distance values from source node
        // first: distance
        // second: node
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
        adjlist[k].second = 0; // change tmp distance to 0 for source node to begin Dijkstra's
        pq.push(std::make_pair(adjlist[k].second,k)); // push source node given by k and remember it will be ordered by temp distance values

        // track total distance from source to all nodes
        // this is equivalent to minimum time it takes to for all the n nodes to receive signal
        int total_distance_processed = -1;

        while(!pq.empty()){ // while there is an unknown distance vertex 
            // process smallest unknown distance vertex
            int current_node = pq.top().second;
            int current_distance = pq.top().first;
            pq.pop(); // make smallest unknown distance vertex known to finish processing it

            // look through adjacency list for unknown neighbors
            for (auto edge : adjlist.at(current_node).first){
                int neighbor_node = edge.first;
                int neighbor_distance = edge.second + current_distance;
                int temp_distance = adjlist[neighbor_node].second;
                // if shorter distance found, update shortest distance and add to pq
                if (neighbor_distance < temp_distance){
                    adjlist[neighbor_node].second = neighbor_distance;
                    pq.push({neighbor_distance,neighbor_node});
                }
            }
        }

        // the max distance value held by a node will be shortest path to visit all nodes 
        for (auto n : adjlist){
            if (n.second.second > total_distance_processed){
                total_distance_processed = n.second.second;
            }
        }

        // Return the minimum time it takes for all the n nodes to receive the signal.

        // if time = infinity, that means there's no path from source to all other nodes
        if (total_distance_processed == infinity){
            return -1; // error flag
        }
        return total_distance_processed;
    }
};

int main(){
    Solution s;

    // {source_node, destination_node, weight}
    std::vector<std::vector<int>> times1{{2,1,1}, {2,3,1}, {3,4,1} };
    std::vector<std::vector<int>> times2{{1,2,1}};
    std::vector<std::vector<int>> times3{{1,2,1}, {2,3,2}, {1,3,4}};
    std::vector<std::vector<int>> times4{{1,2,1}, {2,3,7}, {1,3,4}, {2,1,2}};

    std::cout << s.networkDelayTime(times1,4,2) << std::endl; // 2
    std::cout << s.networkDelayTime(times2,2,1) << std::endl; // 1
    std::cout << s.networkDelayTime(times2,2,2) << std::endl; // -1
    std::cout << s.networkDelayTime(times3,3,1) << std::endl; // 3
    std::cout << s.networkDelayTime(times4,4,1) << std::endl; // -1

    return 0;
}