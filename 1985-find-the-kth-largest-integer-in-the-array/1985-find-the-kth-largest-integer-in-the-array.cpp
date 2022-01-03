class NumStrMinComparator {
public:
    bool operator() (string &b, string &a) { // Please note, I swap position of `a` and `b` here!
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string,vector<string>,NumStrMinComparator> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return (pq.top());
    }
};