/* The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. 
Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. 
The sandwiches are placed in a stack. At each step:
If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack 
(i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue 
(j = 0 is the front of the queue). Return the number of students that are unable to eat. */

#include<bits/stdc++.h>
using namespace std;

/* Count the number of students preferring each type of sandwich.
Serve sandwiches to students based on their preferences.
Keep track of remaining sandwiches to be served.
Return the count of remaining sandwiches, representing the number of students unable to eat lunch. */

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int pref[2], n = students.size();
        pref[0] = count(students.begin() , students.end() , 0);
        pref[1] = n - pref[0];

        for(int s : sandwiches){
            // If the count of students preferring the current sandwich type s is zero (pref[s] == 0), 
            // it means there are no more students who prefer this type of sandwich. Thus, the loop breaks.
            if(pref[s]==0) break;

            // If n (the total number of students) is already zero, 
            // it means there are no more students in the queue. Hence, the loop also breaks.
            // size of students and sandwiches vector is same
            if(n==0) break;

            // Otherwise, decrement the count of students preferring the current sandwich type s (pref[s]--) and 
            // decrement the total number of students (n--).
            pref[s]--;
            n--;
        }

        return n;
    }
};