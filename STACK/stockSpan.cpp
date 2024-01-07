/*
    Stock Span
    Afzal has been working with an organization called 'Money Traders' for the past few years. 
    The organization is into the money trading business. 
    His manager assigned him a task. 
    For a given array/list of stock's prices for N days, find the stock's span for each day.
    The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.

    For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
    Explanation:
    On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

    Similarly, we can deduce the remaining results.
    Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.

    Input Format:
    The first line of input contains an integer N, denoting the total number of days.
    The second line of input contains the stock prices of each day. A single space will separate them.

    Output Format:
    The only line of output will print the span for each day's stock price. A single space will separate them.

    Note:
    You are not required to print the expected output explicitly. It has already been taken care of. Just store the values of output in the spans array.
    Constraints:
    0 <= N <= 10^7
    1 <= X <= 10^9
    Where X denotes the stock's price for a day.

    Time Limit: 1 second
    Sample Input 1:
    4
    10 10 10 10
    Sample Output 1:
    1 1 1 1 
    Sample Input 2:
    8
    60 70 80 100 90 75 80 120
    Sample Output 2:
    1 2 3 4 1 1 2 8 
*/

/*APPROACH:
    1.create a stack and store the index numbers of stacks
    2.compare two consecutive stack =>
        a. if it is less then stack_value = index[i]-index[i-1]
        b. if greater than all the previous values then 
        pop elements less than currect cost previous value+1
        c. if prevous element is greater then mark 1 else mark index+1

*/


#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int prices[], int n, int spans[]) {
    //Write your code here
    /* working
            prices 60 70 80 100 90 75 80 120
            index  0  1  2  3   4  5  6  7
            spans  0  2  3  4   1  1  2  8
        stack-top  0  1  2  3   4  5  6  8
                                3  4  4
                                3  3
    */
    stack<int> s;
    //initial condition:
    spans[0]=1;
    s.push(0);
    //comparing all the stack prices
    for(int i = 1 ; i < n ; i++){
        //we pop all elements less than current stock price
        while(!s.empty() && prices[i]>prices[s.top()]){
            s.pop();
        }
        
        /*
        1.span of i will be i+1 when stack is empty,ie, 
            when the current element is the greatest of all
        2.If stack is not empty then span[i] will be 
            current index,i - stack of top index...
            ie, the index of the greatest element 
        */
        spans[i] = (s.empty())?(i+1):(i-s.top());
        s.push(i);
    }
}

int main() {
    int n;
    cin >> n;

    int* prices = new int[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int* spans = new int[n];
    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}