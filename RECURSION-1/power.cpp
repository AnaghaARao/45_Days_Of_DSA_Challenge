/*
    PROBLEM STATEMENT:
    Write a program to find x to the power n. 
    Take x and n from the user. You need to return the answer.
    DO this recursively.
*/

int power(int x,int n){
    // base case
    if(n<1) return 1;
    if(x==0) return 0;
    //recursive call
    int smallAnswer = x*power(x,n-1);
    // induction step
    return smallAnswer;    
}