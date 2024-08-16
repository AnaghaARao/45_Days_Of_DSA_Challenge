// Problem statement
// You want to buy a ticket for a well-known concert which is happening in your city. 
// But the number of tickets available is limited. 
// Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
// A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).

// The tickets are sold in the following manner -

// 1. The first person (pi) in the queue requests for the ticket.
// 2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
// 3. Otherwise, give him the ticket (and don't make him stand in queue again).
// Giving a ticket to a person takes exactly 1 second and it takes no time for removing and adding a person to the queue. 
// And you can assume that no new person joins the queue.

// Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). 
// Find and return the time it will take until you get the ticket.

// APPROACH
// 1. store all elements in a PQ and indices in a queue
// 2. run a loop with condition till q is empty
// 3. if there is a match in pq and arr[q] then:
// --- increment time counter
// --- pop the element from pq
// --- check if q.front() == k --> if yes then break, else q.pop()
// --- else move q.front() to rear
// 4. return cnt;

#include<bits/stdc++.h>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    if(k>=n) return -1;
    // Write your code here
    priority_queue<int>pq;
    queue<int>q;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        if(pq.top() == arr[q.front()]){ // match of priorities
            cnt++;
            pq.pop();
            if(q.front() == k) break; 
            q.pop();
        }else{ // no match -> go to end of queue
            q.push(q.front());
            q.pop();
        }
    }
    return cnt;
}