#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;
   public:
    PriorityQueue() {}

    void up_heapify(){
        int childIndex = pq.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[parentIndex]<pq[childIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }else break;

            childIndex = parentIndex;
        }
    }

    void down_heapify(){
        int parent = 0;
        int left = parent*2+1;
        int right = parent*2+2;

        while(left < pq.size()){
            int maxIndex = parent;

            if(pq[parent] < pq[left]){
                maxIndex = left;
            }

            if(right < pq.size() && pq[maxIndex] < pq[right]){
                maxIndex = right;
            }

            if(maxIndex == parent) break;

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parent];
            pq[parent] = temp;

            parent = maxIndex;
            left = parent*2+1;
            right = parent*2+2;
        } 
    }

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        up_heapify();        
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.empty()) return -1;
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.empty()) return -1;

        int res = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        down_heapify();
        return res;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.empty();
    }
};