/*
    PROBLEM STATEMENT:
    Find Duplicate in Array

    You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.
    Your task is to find the duplicate element. The duplicate element may be repeated more than twice in the error, but there will be exactly one element that is repeated in the array.
    Note :
    All the integers in the array appear only once except for precisely one integer which appears two or more times.
    Input format:
    The first line of input contains an integer ‘T’ denoting the number of test cases. Then the T test cases follow.

    The first line of each test case contains an integer ‘N’, the number of elements in the array. 

    The second line of each test case contains ‘N’ space-separated integers representing the elements of the array. 
    Output format:
    For each test case, the duplicate element of the given array is printed.

    The output of each test case is printed in a separate line. 
    Note :
    You are not supposed to print anything; It has already been taken care of. Just implement the given function.
    Constraints :
    1 <= T <= 5
    1 <= N <= 10^5
    1 <= ARR[i] <= N - 1

    Time Limit: 1 sec
    Sample Input 1:
    1
    3
    1 1 2
    Sample Output 1:
    1
    Explanation of Sample Input 1:
    1 is repeated in the array, hence function returns 1.
    Sample Input 2:
    3
    5
    1 3 4 2 2
    5
    3 1 3 4 2
    3
    1 1 1
    Sample Output 2:
    2
    3
    1
*/


#include<bits/stdc++.h>
using namespace std;

// SOLUTION FUNCTION
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    sort(arr.begin(),arr.end());
    // declaring the iterator
    vector<int> :: iterator i=arr.begin();
    // traversing through the vector
	for(;i!=arr.end()-1;i++){
		if(*i==*(i+1)) return *i;
	}

}

class Runner
{
    int t;
    vector<vector<int> > arr;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
            {
                cin >> temp[i];
            }
            arr.push_back(temp);
        }
    }

    void execute()
    {
        vector<vector<int> > arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
        	int n = arrCopy[i].size();
            int ans = findDuplicate(arrCopy[i], n);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int n = arr[i].size();
            int ans = findDuplicate(arr[i], n);
            cout << ans <<endl;
        }
    }
};

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
    
}