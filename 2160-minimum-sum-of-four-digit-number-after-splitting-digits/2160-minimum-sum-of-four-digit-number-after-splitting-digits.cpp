class Solution { public: int minimumSum(int num) { string sNum = to_string(num); sort(sNum.begin(),sNum.end()); string new1 = ""; new1.push_back(sNum[0]);new1.push_back(sNum[2]); string new2=""; new2.push_back(sNum[1]);new2.push_back(sNum[3]); cout<<new1<<new2; int sum = stoi(new1)+stoi(new2); return sum; } };