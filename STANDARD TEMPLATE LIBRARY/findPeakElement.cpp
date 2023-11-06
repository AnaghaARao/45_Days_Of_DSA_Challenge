/*
    PROBLEM STATEMENT:
    Find Peak Element

    You are given an array 'arr' of length 'n'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.


    Peak element is defined as that element that is greater than both of its neighbors. If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.


    Assume 'arr[-1]' and 'arr[n]' as negative infinity.


    Note:
    1.  There are no 2 adjacent elements having same value (as mentioned in the constraints).
    2.  Do not print anything, just return the index of the peak element (0 - indexed).
    3. 'True'/'False' will be printed depending on whether your answer is correct or not.


    Example:
    Input: 'arr' = [1, 8, 1, 5, 3]

    Output: 3

    Explanation: There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3.


    Input format:
    The first line contains an integer ‘n’, the number of elements in 'arr'.
    The second line contains ‘n’ space-separated integers , the array 'arr'.


    Output Format
    The output contains True/ False depending whether the found number is peak element or not.


    Sample Input 1:
    5
    1 8 1 5 3


    Expected Answer:
    1


    Output on Console:
    True


    Explanation of sample input 1 :
    There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3. Any of these 2 numbers will print 'True'.


    Sample Input 2:
    3
    1 2 1 


    Expected Answer:
    1


    Output on Console:
    True


    Expected time complexity:
    The expected time complexity is O(log 'n').


    Constraints:
    1 <= 'n' <= 10^5
    1 <= 'arr[i]' <= 10^5
    'arr[i]' != 'arr[i + 1]' for all 'i' in range 0 <= 'i' < 'n' - 1
*/

#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n = arr.size();
    int i;
    bool flag = false;
    for(i = 0 ; i < n ; i++){
        if(arr[i-1] < arr[i] && arr[i+1] < arr[i]){
            flag = true;
            break;
        }
    }

    if(flag) return i;
    return -1;
}

class Runner {
    vector<int> v;

public:
    void takeInput() {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }

    void execute() {
        vector<int> temp = v;
        int ans = findPeakElement(temp);
    }

    void executeAndPrintOutput() {
        vector<int> temp = v;
        int ans = findPeakElement(temp);
        if (ans >= 0 && ans < v.size() && get(ans - 1) < get(ans) && get(ans) > get(ans + 1))
            cout << "True\n";
        else
            cout << "False\n";
    }

    int get(int i) {
        if (i < 0)
            return -100;
        if (i >= v.size())
            return -100;
        return v[i];
    }
};

int main() {
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}