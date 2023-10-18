#include<bits/stdc++.h>
using namespace std;

int main(){
    int** p = new int*[10];
    p[0] = new int[20];

    int m , n ;
    cin >> m >> n ;
    int** arr = new int*[m];
    for(int i = 0 ; i < m ; i++ ){
        arr[i] = new int[n];
        for(int j = 0 ; j < n ; j++ ){
            cin>>arr[i][j];
        }
    }

    // customizing 2D arrays:
    int p1 , q;
    int** a = new int*[p1];
    for(int i = 0 ; i < p1 ; i++){
        cin>>q;
        p[i] = new int[q];
        for(int j = 0 ; j < q ; j++ ){
            cin >> a[i][j] ;
        }
    }

    // de-allocating 2D arrays
    for(int i = 0 ; i < m ; i++){
        delete [] p[i];
    }
    delete []p;

    for(int i = 0 ; i < p1 ; i++){
        delete [] a[i];
    }
    delete [] a;
}

// total memory allocation for a 5*10 array:
/*
    main pointer-8 bytes
    5 rows in the array-each containing an address: 5*8= 40 bytes
    50 int type locations = 50*4 bytes = 200
    total = 248 bytes
*/ 