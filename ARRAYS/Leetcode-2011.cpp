#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum = 0;
        for (string item:operations){
            if(item == "X++" || item == "++X") sum+=1;
            else sum-=1;
        }
        return sum;
    }
};