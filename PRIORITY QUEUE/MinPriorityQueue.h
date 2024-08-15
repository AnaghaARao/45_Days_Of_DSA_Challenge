#include<bits/stdc++.h>
using namespace std;

class MinPriorityQueue{
    vector<int> pq;

    public:
        PriorityQueue(){}

        // Functions:

        // isEmpty()
        bool isEmpty(){
            return pq.empty();
        }

        // getMin()
        int getMin(){
            if(isEmpty()) return -1;
            return pq.at(0);
        }

        // getSize()
        int getSize(){
            return pq.size();
        }

        // insert(int ele)
        void insert(int ele){
            pq.push_back(ele);

            int childIndex = pq.size()-1;
            while(childIndex > 0){
                int parentIndex = (childIndex-1)/2;
                if(pq[childIndex] < pq[parentIndex]){ // check for heap order
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                }
                else{
                    break;
                }
                childIndex = parentIndex;
            }
        }

        // removeMin()
        int removeMin(){
            if(isEmpty()) return -1;

            int res = pq[0];
            pq[0] = pq[pq.size()-1]; 
            pq.pop_back(); // removing the min value
            
            int parentIndex = 0;
            int left = parentIndex*2 +1;
            int right = parentIndex*2+2;

            while(left < pq.size()){ // comparing with left cause that will be the first in leaf node line
                int index = parentIndex;
                if(pq[parentIndex] > pq[left]) index = left; // finding the index of min of the 2 elements

                // comparing with right if it exists and updating index to index of min element
                if(right < pq.size() && pq[index] > pq[right]){
                    index = right;
                }

                if(index == parentIndex) break; // parent itself is min among parent & child/children

                // else DOWN-HEAPIFY
                int temp = pq[index];
                pq[index] = pq[parentIndex];
                pq[parentIndex] = temp;

                // Updating the indices
                parentIndex = index;
                left = parentIndex*2+1;
                right = left+1;
            }
            return res; // returning the result
        }
}