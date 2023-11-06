/*
    PROBLEM STATEMENT:
    Transpose of a Matrix

    You are given a matrix ‘MAT’. Print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i].
    For example:
    Let matrix be : 
    1 2
    3 4

    Then transpose of the matrix will be: 
    1 3
    2 4
    Input Format :
    The first line of input contains an integer ‘T’, denoting the number of test cases.

    The first line of each test case contains two space-separated integers, ‘M’ and ‘N’, representing the size of the matrices.

    The next ‘M’  lines of each test case contain ‘N’ space-separated integers, representing the elements of ‘MAT’.
    Output Format :
    For each test case, print the transpose of the matrix.

    Print output of each test case in a separate line.
    Note :
    You do not need to print anything. It has already been taken care of. Just implement the given function. 
    Constraints :
    1 <= T <= 10
    1 <= M, N <= 3*10^3
    0 <= MAT[i][j] <= 10^7

    Time Limit: 1 sec
    Sample Input 1 :
    2
    2 2
    1 2
    3 4
    3 2
    1 2 
    2 3
    3 4
    Sample Output 1 :
    1 3
    2 4
    1 2 3
    2 3 4
    Explanation For Sample Input 1 :
    For test case 1: 
    The transpose of the matrix will be: 
    1 3
    2 4

    For test case 2:    
    The transpose of the matrix will be: 
    1 2 3
    2 3 4
    Sample Input 2 :
    2
    2 3
    1 2 3 
    3 4 5
    2 1
    1
    2
    Sample Output 2 :
    1 3
    2 4 
    3 5
    1 2
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transMat(int m, int n, vector<vector<int>> &mat){
    // Write your code here.
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            ans[j][i] = mat[i][j];
            // IMPORTANT:
            // note: ans[i][j] = mat[j][i] doesnt work 
            //cause ans[i][j] may not exist for the size n*m

        }
    }
    return ans;
}

class Runner
{
    int t;
    vector<vector<vector<int>>> mat1;

public:
    void takeInput()
    {
        cin >> t;
      
        mat1.resize(t);
        for (int c = 0; c < t; c++)
        {   
            int m,n;
            cin>>m>>n;
            mat1[c].resize(m);
            for(int k = 0; k < m; k++){
                mat1[c][k].resize(n);
                for(int l = 0; l < n; ++l) {
                    cin>>mat1[c][k][l];
                }
            }
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {   
            vector<vector<int>> ans = transMat(mat1[i].size(), mat1[i][0].size(), mat1[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> ans = transMat(mat1[i].size(), mat1[i][0].size(), mat1[i]);
        
            for(int m = 0; m < ans.size(); ++m) {
                for(int n = 0; n < ans[0].size(); ++n) {
                    cout<<ans[m][n]<<" ";
                }
                cout<<"\n";
            } 
        }
    }
};

int main()
{   
// #ifndef ONLINE_JUDGE
//     freopen("Testcases/large/in/input4.txt", "r", stdin);
//     //freopen("Testcases/large/out/output1.txt", "w", stdout);
// #endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}