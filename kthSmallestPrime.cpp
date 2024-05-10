
//Question 

//786. K-th Smallest Prime Fraction


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        double mini = INT_MAX;
        int x, y;
        double z;
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                z = (double)arr[i] / arr[j]; // Perform floating-point division
                pq.push({z, {arr[i], arr[j]}});
            }
        }
        while(k--) {
            auto it = pq.top();
            x = it.second.first;
            y = it.second.second;
            pq.pop();
        }
        return {x, y};
    }
};
