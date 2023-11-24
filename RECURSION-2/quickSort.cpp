#include<bits/stdc++.h>
using namespace std;

int partition(int a[] , int left , int right){
    int x = a[left];
    int cnt = 0;

    for(int i = left + 1 ; i <= right ; i++){
        if(x >= a[i]) cnt++;
    }

    int temp = a[left + cnt];
    a[left + cnt] = a[left];
    a[left] = temp;

    // 2 pointer method
    int partitionIndex = left + cnt;
    int i = left;
    int j = right;

    while(i < partitionIndex && j > partitionIndex){
        if(a[i] <= x) i++;
        else if(a[j] > x) j--;
        else{
            // swapping elements
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return partitionIndex;
}

void quickSort(int a[] , int left , int right){
    // base case:
    if(left >= right) return;
    // induction step
    // this function segrates the elements into 2 sets...
    // to the right -> greater than elements at position c
    // to the left -> lesser than elements at position c
    int c = partition(a , left , right);
    quickSort(a , left , c-1);
    quickSort(a , c+1 , right);
}


/*
    Working of quick sort is different from merge sort.
    In mergeSort() first recursion is called and then induction step happens
    In quickSort() first induction step is exected then recursion is called
    => there first we place an element(first or last) at its correct position -> partition()
    => and all elements less then the element is placed to the left and the greater one's to the right

    In partition():
    -> we find the count of smaller elements present in the array
    -> we place x at the appropriate position
    -> to achieve this we swap elements placed at the wrong position in the left and right partitions
    18 , 24 , 11 , 91, 62 , 9 , 2 , 26 
    18 , 2 , 11 , 91, 62 , 9 , 24 , 26 
    18 , 2 , 11 , 9, 62 , 91 , 24 , 26 

*/